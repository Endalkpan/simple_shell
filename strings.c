#include "main.h"

/**
 * _strdup - returns a pointer to a newly
 *	allocated space in memory, which contains
 *	a copy of the string given as a parameter
 * @str: the string
 * Return: Pointer
 */

char *_strdup(char *str)
{
	int len, i;
	char *s;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	s = malloc(len + 1);

	if (s == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		s[i] = str[i];
	s[i] = '\0';
	return (s);

}

/**
 * _strlen - return the length of a string
 * @s: the string
 * Return: the length
 */

int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _strcpy - copies a strings
 * @src: the string to copy
 * @dest: the destination
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcspn - calculates the length of the
 *	initial segment of a string that consists
 *	entirely of characters in another string
 * @s: the string
 * @reject: second argument
 * Return: the position if a matching character is
 *	found in reject or the length of the
 *	string if none is found
 */

unsigned int _strcspn(char *s, char *reject)
{
	unsigned int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; reject[j] != '\0'; j++)
		{
			if (reject[j] == s[i])
				return (i);
		}
	}
	return (i);
}

/**
 * _strcat - concatenates two strings
 * @dest: first string
 * @src: second string
 * Return: a pointer to string dest
 */

char *_strcat(char *dest, char *src)
{
	int j, len = _strlen(dest);

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[len + j] = src[j];
	}
	dest[len + j] = '\0';
	return (dest);
}
