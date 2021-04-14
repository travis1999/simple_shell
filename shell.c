#include "globals.h"

#ifdef DEBUG
#include <stdio.h>
#endif

#include "tokenizer.h"
#include <stdlib.h>
#include <stdio.h>
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

int main(int argc, char **argv)
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
			break;
		token_list = make_tokens(buffer);

		#ifdef DEBUG
		print_tokens(token_list);
		#endif

		free_tokens(token_list);
	}

	free(buffer);
	return (0);
}
