#include "globals.h"

#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "parser.h"

#include <stdlib.h>
#include <unistd.h>
#include <string.h>


/**
 * input - gets data from sdtin
 * @buffer: buffer pointer
 * @buffer_size: size of buffer
 * Return: number of bytes read
 */

size_t input(char **buffer, size_t *buffer_size)
{
	char *prompt = "($) ";
	size_t size;

	write(1, prompt, 4);
	
	size = getline(buffer, buffer_size, stdin);

	return (size);
}

/**
 * main - entry point
 * @argc: number of args
 * @argv: null terminated array of shell args
 * @env: environment variables
 * Return: Always Zero (Success)
 */
int main(void)
{
	size_t buffer_size = 1024;
	char *buffer = malloc(buffer_size);
	size_t b_read;
	int run = 1;

	Token *token_list = NULL;

	while (run)
	{
		b_read = input(&buffer, &buffer_size);

		if ((int)b_read == -1)
			break;

		buffer[b_read - 1] = 0;
		
		if (!strcmp(buffer, "exit"))
		{
			break;
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
