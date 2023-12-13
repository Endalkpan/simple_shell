#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @g: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char g, char *delim)
{
	while (*delim)
		if (*delim++ == g)
			return (1);
	return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@b: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int b)
{
	if ((b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@g: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *g)
{
	int j, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (j = 0;  g[j] != '\0' && flag != 2; j++)
	{
		if (g[j] == '-')
			sign *= -1;

		if (g[j] >= '0' && g[j] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (g[j] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
