#include "shell.h"

/**
 * _myexit - exit the shell
 * @h: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int _myexit(h_t *h)
{
	int exitcheck;

	if (h->argv[1])  /* If there is an exit arguement */
	{
		exitcheck = _erratoi(h->argv[1]);
		if (exitcheck == -1)
		{
			h->status = 2;
			print_error(h, "Illegal number: ");
			_eputs(h->argv[1]);
			_eputchar('\n');
			return (1);
		}
		h->err_num = _erratoi(h->argv[1]);
		return (-2);
	}
	h->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @h: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _mycd(h_t *h)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!h->argv[1])
	{
		dir = _getenv(h, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(h, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(h->argv[1], "-") == 0)
	{
		if (!_getenv(h, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(h, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(h, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(h->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(h, "can't cd to ");
		_eputs(h->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(h, "OLDPWD", _getenv(h, "PWD="));
		_setenv(h, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @h: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myhelp(h_t *h)
{
	char **arg_array;

	arg_array = h->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
