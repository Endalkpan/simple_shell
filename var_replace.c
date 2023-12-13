#include "main.h"

/**
 * _var_replace - this function handel
 *	the variable replacements
 * @toks: tokens of the line (input)
 * @env: the environment
 * @exit_code: the exit status
 */

void _var_replace(char **toks, New_env *env, int exit_code)
{
	pid_t parent_pid = getppid();
	int ppid, i;
	char *tmp;

	for (i = 1; toks[i]; i++)
	{
		if (toks[i][0] != '$')
			continue;

		if ((toks[i][1] == '$') || (toks[i][1] == '?'))
		{
			if (toks[i][1] == '$')
			{
				ppid = (int)parent_pid;
				toks[i] = int_to_str(ppid);
			}
			else if (toks[i][1] == '?')
				toks[i] = int_to_str(exit_code);
		}
		else
		{
			toks[i]++;
			tmp = _getenv(toks[i], env->env_var);
			if (tmp != NULL)
				toks[i] = tmp;
			else
				toks[i] = NULL;
		}
	}

}
