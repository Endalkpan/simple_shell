#include "main.h"

#define BUFF_SIZE 1024

void t(void);
/**
 * main - Starts a shell
 * @ac: argument count
 * @av: argument variable
 * Return: EXIT_SUCCESS
 */

int main(int ac, char *av[])
{

	size_t ncmd = 0;
	char **tokens = NULL, *built_buff[BUFF_SIZE];
	int pid, status, exit_code = 0, exit_read = 0;
	char *line = NULL, exec_err[256], *cmd, *_line, *path, *delim;
	size_t len_line = 0;
	ssize_t read;
	list_t *PATH = NULL;
	New_env *env = create_env(environ);

	path = _getenv("PATH", env->env_var);
	start_check(ac);
	PathToList(&PATH, path);
	inter_mode();

	while ((read = _getline(&line, &len_line, stdin)) != -1)
	{
		_line = _liner(line);
		exit_read = 0;
		ncmd++;
		exit_read = check_exit(_line, &exit_code, av[0], ncmd);

		if (exit_read == -1)
		{
			free_m1(PATH, env, _line, line);
			exit(exit_code);
		}
		if (exit_read == 2 && !isatty(STDIN_FILENO))
		{
			free_m1(PATH, env, _line, line);
			exit(2);
		}
		/* if multiple commands exists*/
		delim = _Multi(_line);
		if (delim != NULL)
		{
			X_M(delim, _line, &exit_code, &ncmd, av[0], PATH, env);
			free(_line);
		}
		/* if the command is builtin execute it*/
		else if (_built(line))
		{
			tokeniz(built_buff, _line, " ");

			_exec_built(built_buff, &exit_code, ncmd, av[0], env);
			free(_line);
			free_grid_half(built_buff);
		}
		/* if it's not builtin, tokenize line */
		else if (exit_read == 0)
		{
			cmd = get_cmd(PATH, _line, &exit_code, exec_err, av[0], ncmd);
			if (cmd != NULL && cmd[0] != '\0' && exit_read == 0)
			{
				pid = fork();

				if (exit_read == 2 && pid == 0)
					return (2);

				if (pid == -1)
				{
					perror("Fork");
					exit(EXIT_FAILURE);
				}

				if (pid == 0)
				{

					tokens = line_tokens(_line, " ");
					if (tokens[1])
						_var_replace(tokens, env, exit_code);

					if (execve(cmd, tokens, env->env_var) == -1)
					{
						perror("execve");
						_exit(2);
					}
				}
				else
				{
					wait(&status);
					if (exit_read != 2)
						exit_code = status >> 8;
				}

			}
			else if (!isatty(STDIN_FILENO) && exit_code != 0)
			{
				free_m2(PATH, env, _line, line, cmd);
				return (exit_code);
			}
			if (cmd != NULL)
			{
				free(cmd);
				cmd = NULL;
			}
			free(_line);
		}
		inter_mode();
	}

	free_m3(PATH, env, line);
	if (!isatty(STDIN_FILENO))
		exit(exit_code);
	return (EXIT_SUCCESS);
}
