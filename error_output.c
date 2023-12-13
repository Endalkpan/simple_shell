#include "main.h"

/**
 * error_cd - generates an error message
 * @BUF: the buffer that contains the message
 * @prg: the name of the program
 * @ncmd: number of consecutive commands
 * @dir: the path name of the directory
 */
void error_cd(char *BUF, char *prg, size_t ncmd, char *dir)
{
	char num[20], *delim = ": ", *err_cd = ": cd: can't cd to ";
	unsigned int l = 0, n = ncmd;

	while (n != 0)
	{
		num[l] = n % 10 + '0';
		n /= 10, l++;
	}
	num[l] = '\0';

	_strcpy(BUF, prg);
	_strcat(BUF, delim);
	_strcat(BUF, num);
	_strcat(BUF, err_cd);
	_strcat(BUF, dir);
	_strcat(BUF, "\n");

}

/**
 * error_ret - generates an error message
 * @err_msg: the err's message string concatenated
 * @prg: the name of the program
 * @ncmd: the count of successive cmds executed
 *	in the program
 * @cmd: the executed command
 * @tmp: temporary string
 */

void error_ret(char *err_msg, char *prg, size_t ncmd,
		char *cmd, char *tmp)
{
	unsigned int l = 0, n = ncmd;
	char num[20], *delim = ": ", *err1 = ": Illegal number: ";

	while (n != 0)
	{
		num[l] = n % 10 + '0';
		n /= 10, l++;
	}
	num[l] = '\0';

	l = 0;
	_strcpy(err_msg, prg);
	_strcat(err_msg, delim);
	_strcat(err_msg, num);
	_strcat(err_msg, delim);
	_strcat(err_msg, cmd);
	_strcat(err_msg, err1);
	_strcat(err_msg, tmp);
	_strcat(err_msg, "\n");
}

/**
 * error_exec - generates an error message for
 *	execve function if the file is not found
 * @err_msg: the err's message string concatenated
 * @prg: the name of the program
 * @ncmd: the count of successive cmds executed
 *	in the program
 * @cmd: the executed command
 */

void error_exec(char *err_msg, char *prg, size_t ncmd,
		char *cmd)
{
	unsigned int l = 0, n = ncmd;
	char num[20], *delim = ": ", *err1 = ": not found";

	while (n != 0)
	{
		num[l] = n % 10 + '0';
		n /= 10, l++;
	}
	num[l] = '\0';

	l = 0;
	_strcpy(err_msg, prg);
	_strcat(err_msg, delim);
	_strcat(err_msg, num);
	_strcat(err_msg, delim);
	_strcat(err_msg, cmd);
	_strcat(err_msg, err1);
	_strcat(err_msg, "\n");
}
