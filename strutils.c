#include <unistd.h>

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int str_comp(char *str0, char *str1)
{
	while (*str0 != '\0' && *str1 !='\0')
		if (!(*str0++ == *str1++))
			return (0);
	return (1);
}

void str_print(char *str)
{
	while (*str)
	{
		_putchar(*str);
		str++;
	}
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
