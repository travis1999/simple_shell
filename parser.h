#ifndef PARSER_H
#define PARSER_H
#include "globals.h"
#include "tokenizer.h"
#include "exec.h"
#include <stdlib.h>

/**
 * struct operation - used to  store data  for execution
 * @commands: pointer to commands
 * @temp_ptr: pointer to raw list of commands
 * @size: number of arguments
 * @next: pointer to next operation
 * @function: pointer to the function that executes
 * the operation
 */
typedef struct operation
{
	char **commands;
	char **temp_ptr;
	int size;
	struct operation *next;
	void (*function)(char**, int size);
} operation;

operation *parse_list(Token *head);
void exec_tree(operation *head);


#endif
