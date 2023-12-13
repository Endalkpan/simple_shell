#include "main.h"

/**
 * _unset_env - removes a variable from env
 * @var_name: the name of the variable
 * @env: the copy environement
 * Return: 0 for Success 1 for failure
 */

int _unset_env(char *var_name, New_env *env)
{
	int i;

	if (var_name == NULL)
	{
		perror("unsetenv");
		return (-1);
	}

	for (i = 0; env->env_var[i]; i++)
	{
		if (_strncmp(env->env_var[i], var_name, _strlen(var_name)) == 0)
		{
			free(env->env_var[i]);
			for (; env->env_var[i]; i++)
			{
				env->env_var[i] = env->env_var[i + 1];
			}
			return (0);
		}
	}
	return (0);
}

/**
 * change_dir - changes the current directory
 * @token: the string that contains the command
 * @prg: the name of the program
 * @ncmd: number of commands
 * @env: the copy environement
 * Return: 0 for Success, 1 for failure
 */

int change_dir(char **token, char *prg, size_t ncmd, New_env *env)
{
	char *dir, pwd[1024], oldpwd[1024];
	char err_msg[1024], startpwd[1024];
	int cd_ret;

	_set_env("OLDPWD", getcwd(startpwd, 1024), 0, env);
	getcwd(oldpwd, 126);

	if (token[1] == NULL)
	{
		dir = _getenv("HOME", env->env_var);
		if (dir == NULL)
			return (0);
	}

	else if (token[1][0] == '-')
	{
		dir = _getenv("OLDPWD", env->env_var);
		write(STDOUT_FILENO, dir, _strlen(dir));
		write(STDOUT_FILENO, "\n", 1);
	}
	else
		dir = token[1];


	cd_ret = chdir(dir);
	if (cd_ret == -1)
	{
		error_cd(err_msg, prg, ncmd, dir);
		write(STDERR_FILENO, err_msg, _strlen(err_msg));
		return (1);
	}
	else
	{
		_set_env("OLDPWD", oldpwd, 1, env);
		_set_env("PWD", getcwd(pwd, 126), 1, env);
		return (0);
	}
}
