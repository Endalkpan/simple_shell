#include "shell.h"

/**
 * get_environ - returns the string array copy of our environ
 * @h: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **get_environ(h_t *h)
{
	if (!h->environ || h->env_changed)
	{
		h->environ = list_to_strings(h->env);
		h->env_changed = 0;
	}

	return (h->environ);
}

/**
 * _unsetenv - Remove an environment variable
 * @h: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int _unsetenv(h_t *h, char *var)
{
	list_t *node = h->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			h->env_changed = delete_node_at_index(&(h->env), i);
			i = 0;
			node = h->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (h->env_changed);
}

/**
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @h: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 *  Return: Always 0
 */
int _setenv(h_t *h, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = h->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			h->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(h->env), buf, 0);
	free(buf);
	h->env_changed = 1;
	return (0);
}
