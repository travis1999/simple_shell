#include <unistd.h>

/**
 * _putchar - prints a character
 * @c: character to print
 * Return: number of printed characters
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * str_comp - string compare
 * @str0: first string
 * @str1: second string
 * Return: 1 if equal 0 otherwise
 */
int str_comp(char *str0, char *str1)
{
	if (str0 == NULL || str1 == NULL)
		return (0);

	while (*str0 != '\0' && *str1 != '\0')
		if (!(*str0++ == *str1++))
			return (0);
	return (1);
}

/**
 * str_cpy - find if string exists in array
 * @dest: first string
 * @src: list of strings
 * Return: 1 if equal 0 otherwise
 */
void str_cpy(char *dest, char *src)
{
	if (dest == NULL || src == NULL)
		return;
	while (*dest != '\0' && *src != '\0')
		*dest++ = *src++;
	*dest = 0;
}

/**
 * str_exists - find if string exists in array
 * @str: first string
 * @str_list: list of strings
 * Return: 1 if equal 0 otherwise
 */

int str_exists(char *str, char **str_list)
{
	while (*str_list != NULL)
	{
		if (str_comp(str, *str_list++))
			return (1);
	}
	return (0);
}

/**
 * str_len - length of string
 * @str: string to get length
 * Return: length of string
 */
int str_len(char *str)
{
	int count = 0;

	while (*str)
	{
		str++;
		count++;
	}
	return (count);
}
