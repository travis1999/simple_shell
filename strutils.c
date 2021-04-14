#include <unistd.h>

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int str_comp(char *str0, char *str1)
{
	if (str0 == NULL || str1 == NULL)
		return (0);

	while (*str0 != '\0' && *str1 !='\0')
		if (!(*str0++ == *str1++))
			return (0);
	return (1);
}

void str_cpy(char *dest, char *src)
{
	if (dest == NULL || src == NULL)
		return;
	while (*dest != '\0' && *src !='\0')
		*dest++ = *src++;
	*dest = 0;
}

int str_exists(char *str, char **str_list)
{
	while (*str_list != NULL)
	{
		if (str_comp(str, *str_list++))
			return (1);
	}
	return (0);
}

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