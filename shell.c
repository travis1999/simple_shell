#include "globals.h"

#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "parser.h"
#include "strutils.h"

#include <stdlib.h>
#include <unistd.h>
#include <string.h>


/**
 * input - gets data from sdtin
 * @buffer: buffer pointer
 * @buffer_size: size of buffer
 * Return: number of bytes read
 */
size_t input(char *buffer, int show_prompt)
{
	char *prompt = "($) ";
	int idx = 0;
	char inpt;

	if (show_prompt)
		write(1, prompt, 4);

	inpt = getchar();

	while (inpt != '\n')
	{
		buffer[idx] = inpt;
		idx++;
		inpt = getchar();
	}
	buffer[idx] ='\0';

	return ((size_t)(str_len(buffer)));
}

/**
 * main - entry point
 * @argv: number of args
 * @argc:array of char*
 * Return: Always Zero (Success)
 */
int main(int argv, char **argc __attribute__((unused)))
{
	size_t buffer_size = 1024;
	char *buffer = malloc(buffer_size);
	size_t b_read;
	int run = 1;

	Token *token_list = NULL;
	printf("length = %d", argv);

	while (run)
	{
		b_read = input(buffer, (argv == 1));
		printf("buffer: %s\n", buffer);

		if ((int)b_read == -1)
			break;

		if (str_comp(buffer, "exit"))
		{
			break;
			printf("buffer1: %s\n", buffer);
			run = 0;
		}
		token_list = make_tokens(buffer);

		if (token_list == NULL)
			continue;
		else
		{
			#ifdef DEBUG
			print_tokens(token_list);
			#endif

			operation *head_op = parse_list(token_list);

			exec_tree(head_op);
			free_tokens(token_list);
		}
	}

	free(buffer);
	return (0);
}
