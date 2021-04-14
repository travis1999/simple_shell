#include "globals.h"

#ifdef DEBUG
#include <stdio.h>
#endif

#include "tokenizer.h"
#include "parser.h"

#include <stdlib.h>
#include <unistd.h>
#include <string.h>



size_t input(char **buffer, size_t *buffer_size)
{
	char *prompt = "($) ";
	size_t size;

	write(1, prompt, 4);
	
	size = getline(buffer, buffer_size, stdin);

	return (size);
}

int main(int argc, char **argv, char **env)
{
	size_t buffer_size = 1024;
	char *buffer = malloc(buffer_size);
	size_t b_read;

	Token *token_list = NULL;

	while (1)
	{
		b_read = input(&buffer, &buffer_size);

		if (b_read == -1)
			break;

		buffer[b_read - 1] = 0;
		
		if (!strcmp(buffer, "exit"))
		{
			printf("exiting");
			free(buffer);
			exit(0);
			break;
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
