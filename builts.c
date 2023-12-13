#include "main.h"

/**
 * _built - Checks the exixstence of builtins
 *	commands
 * @token_0: the strings to check
 * Return: Success or Failure
 */

int _built(char *token_0)
{
	char *possible[] = {"env", "setenv", "unsetenv", "cd", NULL};
	int i;


	for (i = 0; possible[i]; i++)
	{
		if (_strcmp(token_0, possible[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * _exec_built - Execute the builtin command
 * @token: the string that contains the arguments
 * @exit_code: the exit code
 * @ncmd: the number of consecutive commands
 * @prg: the name of the program
 * @env: the copy environment
 */

void _exec_built(char **token, int *exit_code, size_t ncmd,
		char *prg, New_env *env)
{
	char *err_set = "An error has been occured\n";
	int tok3_sub = 1;

	if (_strcmp(token[0], "env") == 0)
	{
		_printenv(exit_code, env);
	}

	else if (_strcmp(token[0], "setenv") == 0)
	{
		if (token[1] == NULL || token[2] == NULL)
		{
			write(STDERR_FILENO, err_set, _strlen(err_set));
			return;
		}
		else if ((token[3]) != NULL)
			tok3_sub = _atoi(token[3]);

		_set_env(token[1], token[2], tok3_sub, env);
	}
	else if (_strcmp(token[0], "unsetenv") == 0)
	{
		if (token[1] == NULL)
		{
			write(STDERR_FILENO, err_set, _strlen(err_set));
			return;
		}
		_unset_env(token[1], env);
	}
	else if (_strcmp(token[0], "cd") == 0)
	{
		*exit_code = change_dir(token, prg, ncmd, env);
	}
}

/**
 * _printenv - prints the environment
 * @exit_code: the exit code
 * @env: the copy enivronment
 */

void _printenv(int *exit_code, New_env *env)
{
	int i;

	for (i = 0; env->env_var[i]; i++)
	{
		write(STDOUT_FILENO, env->env_var[i], _strlen(env->env_var[i]));
		write(STDOUT_FILENO, "\n", 1);
	}

	*exit_code = 0;
}

/**
 * _set_env - adds a new variable to Env
 * @var_name: the variable's name
 * @var_value: the variable's value
 * @condition: what to do with the variable
 * @env: the copy environment
 * Return: 0 for Success -1 for failure
 */
int _set_env(char *var_name, char *var_value, int condition, New_env *env)
{
	char *new_var;
	int i;

	if (var_name == NULL || var_value == NULL || _strchr(var_name, '=') != NULL)
	{
		perror("setenv");
		return (-1);
	}

	new_var = malloc(_strlen(var_name) + _strlen(var_value) + 2);
	if (new_var == NULL)
	{
		free(new_var);
		perror("setenv");
		return (-1);
	}

	var_name_cat(new_var, var_name, "=", var_value);


	for (i = 0; env->env_var[i]; i++)
	{
		if (_strncmp(env->env_var[i], var_name, _strlen(var_name)) == 0)
		{
			if (condition == 0)
			{
				free(new_var);
				return (0);
			}
			free(env->env_var[i]);
			env->env_var[i] = new_var;
			return (0);
		}
	}

	env->env_var = realloc(env->env_var, sizeof(char *) * (i + 2));
	env->env_var[i + 1] = NULL;
	env->env_var[i] = new_var;
	return (0);
}

/**
 * var_name_cat - concatenate the new var
 * @new_var: the new variable
 * @name: the var's name
 * @sign: equal sign
 * @value: the var's value
 */
void var_name_cat(char *new_var, char *name, char *sign, char *value)
{
	_strcpy(new_var, name);
	_strcat(new_var, sign);
	_strcat(new_var, value);
}

