#ifndef MAIN
#define MAIN

/*<-----Standard Libraries----->*/
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdarg.h>

/*<------Data Structures------->*/

/**
 * struct list_t - singly linked list
 * @path: a path variable value
 * @next: points to the next node
 *
 * Description: PATH structure list
 *
 */
typedef struct list_t
{
	char *path;
	struct list_t *next;
} list_t;

/**
 * struct env - Array of env variables
 * @env_var: an env variable value
 *
 * Description: custom Environ structure
 *
 */

typedef struct env
{
	char **env_var;
} New_env;


extern char **environ;

/*<---------Strings Standard----------->*/
ssize_t _getline(char **line, size_t *size, FILE *source);
int _atoi(char *s);
char *_strchr(char *s, char c);
char *_strcat(char *dest, char *src);
char *_strtok(char *str, const char *delim);
unsigned int _strcspn(char *s, char *reject);
int _strncmp(char *s1, char *s2, int num);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);


/*<---------Strings Custom----------->*/
char *_strpbrk_token(char *s, const char *accept);
unsigned int _strspn_token(char *s, const char *accept);
char **line_tokens(char *line, char *delim);
char *get_cmd(list_t *head, char *str, int *exit_code,
		char *exec_err, char *name, size_t ncmd);
char *_liner(char *str);
char *int_to_str(int n);
void var_name_cat(char *new_var, char *name, char *sign, char *value);

/*<---------Built Ins----------->*/
int check_exit(char *s, int *exit_code, char *prg, size_t ncmd);
int _built(char *token_0);
void _exec_built(char **token_0, int *exit_code, size_t ncmd,
		char *prg, New_env *env);
int change_dir(char **token, char *prg, size_t ncmd, New_env *env);

/*<---------Multiple Commands----------->*/
char *_Multi(char *line);
void X_M(char *d, char *L, int *X, size_t *N, char *P,
		list_t *p, New_env *env);
int M_c(char *d, char *L, size_t *N, char *P, list_t *p, New_env *env, int F);
void tokeniz(char **toks, char *line, char *delim);

/*<---------Environment Related----------->*/
char *_getenv(char *s, char **env);
void _printenv(int *exit_code, New_env *env);
int _set_env(char *var_name, char *var_value, int condition, New_env *env);
int _unset_env(char *var_name, New_env *env);
char **cp_env(char **environ);
New_env *create_env(char **environ);

/*<---------Error Output----------->*/
void error_cd(char *BUF, char *prg, size_t ncmd, char *dir);
void error_exec(char *err_msg, char *prg, size_t ncmd, char *cmd);
void error_ret(char *err_msg, char *prg, size_t ncmd,
		char *cmd, char *tmp);

/*<---------Singly Linkled List Related----------->*/
list_t *add_node_end(list_t **head, const char *p);

/*<---------Path Related----------->*/
char *cmd_to_path(list_t *head, char *command);
int PathToList(list_t **head, char *path);

/*<----------Variable Replacement---------->*/
void _var_replace(char **toks, New_env *env, int exit_code);

/*<---------Free Related----------->*/
void free_grid(char **grid);
void free_char1(const unsigned int n, ...);
void free_list(list_t **head);
void free_grid_half(char **grid);
void free_m1(list_t *PATH, New_env *env, char *_line, char *line);
void free_m2(list_t *PATH, New_env *env, char *_line, char *line, char *cmd);
void free_m3(list_t *PATH, New_env *env, char *line);

/*<---------Extras----------->*/
void start_check(int ac);
void inter_mode(void);

#endif
