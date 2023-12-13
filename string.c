include "shell.h"

/**
 * _strlen - returns the length of a string
 * @f: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *f)
{
	int i = 0;

	if (!f)
		return (0);

	while (*f++)
		i++;
	return (i);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks if bone starts with blood
 * @blood: string to search
 * @bone: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *blood, const char *bone)
{
	while (*bone)
		if (*bone++ != *blood++)
			return (NULL);
	return ((char *)blood);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
