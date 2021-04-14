#include "parser.h"
#include "strutils.h"


#ifdef DEBUG
#include <stdio.h>
#endif

/**
 * parse_list - parses a list of tokens
 * @head: head of list
 * Return: returns head of operation
 */
operation *parse_list(Token *head)
{
	char *builtins[] = {"exec_shell", "env", NULL};
	void (*func_builtins[])(char **, int size) = {exec_shell, env};

	Token *next_token = head;
	operation *head_op = malloc(sizeof(operation));
	operation *last_op = head_op;
	operation *temp_op = NULL;

	int idx = 0, idy;

	char **temp;

	while (next_token != NULL)
	{
		temp = malloc(sizeof(char **) * 256);
		while (1)
		{
			temp[idx] = malloc(str_len((char *)next_token->value) + 1);
			*(temp + idx) = (char *)next_token->value;
			next_token = next_token->next;
			idx++;
			if (next_token == NULL)
				break;

		}

		last_op->commands = malloc(sizeof(char **) * (idx + 1));
		last_op->size = idx;
		last_op->temp_ptr = temp;

		for (idy = idx; idy < 256; idy++)
			free(*(temp + idy));

		#ifdef DEBUG
		printf("size of array: %d\n", idx);
		#endif
		
		for (idy = 0; idy < idx; idy++)
			last_op->commands[idy] = temp[idy];

		last_op->commands[idy] = NULL;

		for (idy = 0; builtins[idy] != NULL; idy++)
		{
			if (str_comp(last_op->commands[0], builtins[idy]))
				last_op->function = func_builtins[idy];
			else
				last_op->function = func_builtins[0];
		}

		idx = 0;
		idy = 0;
		break;
	}


	return (head_op);
}


/**
 * exec_tree - executes tree from head operation
 * @head: start operation
 */
void exec_tree(operation *head)
{	
	char **temp = head->temp_ptr;
	int idx = 0;
	

	while (head != NULL)
	{
		head->function(head->commands, head->size);
		free(head->commands);
		head = head->next;
		free(head);
	}

	/*free(temp);*/
}