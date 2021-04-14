#include "parser.h"
#include "strutils.h"

#ifdef DEBUG
#include <stdio.h>
#endif




operation *parse_list(Token *head)
{
	char *builtins[] = {"exec_shell", "env", NULL};
	void (*func_builtins[])(char **) = {exec_shell, env};

	Token *next_token = head;
	operation *head_op = NULL;
	operation *last_op = head_op;

	int first_op = 1;
	int idx;

    while (next_token != NULL)
    {
		
		if (first_op)
		{
			for (idx = 0, builtins[idx] != NULL; idx++)
				if (str_comp((char *)(next_token->value), builtins[idx]))
				{
					last_op->function = func_builtins[idx];
					break;
				}
				else
				{
					last_op->function = NULL;
				}
					
			if (last_op->function == NULL)
				last_op->function = func_builtins[0];

			last_op->head = malloc(str_len())
		}
	}

}