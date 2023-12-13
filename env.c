#include "main.h"

/**
 * create_env - creates a structure for the copy
 *	of Environ
 * @environ: the global environment
 * Return: the new structure
 */

New_env *create_env(char **environ)
{
	New_env *env = malloc(sizeof(New_env));

	env->env_var = cp_env(environ);
	return (env);
}

/**
 * cp_env - copies the Environ to Env struct
 * @environ: the global environment
 * Return: the copy of Environ
 */

char **cp_env(char **environ)
{
	int i = 0;
	char **new_env = NULL;

	while (environ[i] != NULL)
	{
		i++;
	}

	new_env = malloc((i + 1) * sizeof(char *));

	for (i = 0; environ[i] != NULL; i++)
	{
		new_env[i] = _strdup(environ[i]);
	}
	new_env[i] = NULL;

	return (new_env);
}
