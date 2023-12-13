#include "main.h"

void empty(void);
/**
 * _Multi - checks for special seperators
 * @L: the string to check
 * Return: the seperator
 */

char *_Multi(char *L)
{
	char and[2] = "&&", or[2] = "||";
	char semi[1] = ";";
	int i;

	for (i = 0; L[i]; i++)
	{
		if (L[i] == semi[0])
			return (";");

		else if (L[i] == and[0] && L[i + 1] == and[1])
			return ("&&");

		else if (L[i] == or[0] && L[i + 1] == or[1])
			return ("||");
	}

	return (NULL);
}

/**
 * X_M - the commands to execute
 * @d: the delimiter
 * @L: the line that contains the commands
 * @X: the exit code
 * @N: the number of consecutive commands
 * @P: the name of the program
 * @p: the ph singly linked list
 * @env: the copy environement
 */
void X_M(char *d, char *L, int *X, size_t *N, char *P, list_t *p, New_env *env)
{
	if (_strcmp(d, ";") == 0)
		*X = M_c(d, L, N, P, p, env, 0);

	else if (_strcmp(d, "&&") == 0)
		*X = M_c(d, L, N, P, p, env, 1);

	else if (_strcmp(d, "||") == 0)
		*X = M_c(d, L, N, P, p, env, 2);
}

/**
 * M_c - execute the commands
 * @d: the delimiter
 * @L: the line that contains the commands
 * @N: number of consecutive commands
 * @P: the name of the program
 * @p: tha ph list
 * @env: the copy environment
 * @F: a Flag for the type of operator
 * Return: the exit code
 */

int M_c(char *d, char *L, size_t *N, char *P, list_t *p, New_env *env, int F)

{
	char *cmd_list[1024], *tokens[1024], *cmd, exec_err[516];
	int X, i,  pid, status;

	tokeniz(cmd_list, L, d);
	for (i = 0; cmd_list[i] != NULL; i++)
	{
		tokeniz(tokens, cmd_list[i], " ");
		if (_built(tokens[0]))
			_exec_built(tokens, &X, *N, P, env);
		else
		{
			cmd = get_cmd(p, tokens[0], &X, exec_err, P, *N);
			if (cmd != NULL && cmd[0] != '\0')
			{
				pid = fork();

				if (pid == -1)
				{
					perror("Fork");
					exit(98);
				}
				if (pid == 0)
				{
					if (execve(cmd, tokens, env->env_var) == -1)
					{
						perror("Execve");
						_exit(2);
					}
				}
				else
				{
					wait(&status);
					X = status >> 8;
				}
				free(cmd);
			}
		}
		free_grid_half(tokens);
		if (F == 1)
		{
			if (X != 0)
				break;
		}
		else if (F == 2)
		{
			if (X == 0)
				break;
		}

	}
	/*inter_mode();*/
	free_grid_half(cmd_list);
	return (X);
}

/**
 * tokeniz - custom tokenizer
 * @toks: the array to hold the results
 * @L: the string to tokenize
 * @d: the delimiter
 */

void tokeniz(char **toks, char *L, char *d)
{
	char *tmp;
	int i;

	tmp = _strtok(L, d);
	for (i = 0; tmp; i++)
	{
		toks[i] = _strdup(tmp);
		tmp = _strtok(NULL, d);
	}

	toks[i] = NULL;
}
