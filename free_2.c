#include "main.h"

/**
 * free_m1 - frees multiple variables
 * @PATH: linked list of the PATH
 * @env: copy of the environment
 * @_line: the clean line (input)
 * @line: the line
 */

void free_m1(list_t *PATH, New_env *env, char *_line, char *line)
{
	free_list(&PATH);
	free_grid(env->env_var);
	free_char1(3, _line, line, env);
}

/**
 * free_m2 - frees multiple variables
 * @PATH: linked list of the PATH
 * @env: copy of the environment
 * @_line: the clean line (input)
 * @line: the line
 * @cmd: the command
 */

void free_m2(list_t *PATH, New_env *env, char *_line, char *line, char *cmd)
{
	free_list(&PATH);
	free_grid(env->env_var);
	free_char1(4, _line, line, env, cmd);
}

/**
 * free_m3 - frees multiple variables
 * @PATH: linked list of the PATH
 * @env: copy of the environment
 * @line: the line
 */

void free_m3(list_t *PATH, New_env *env, char *line)
{
	free_list(&PATH);
	free_grid(env->env_var);
	free_char1(2, line, env);
}
