#ifndef PARSER_H
#define PARSER_H
#include "globals.h"
#include "tokenizer.h"
#include "exec.h"
#include <stdlib.h>


typedef struct oparation operation;

typedef struct oparation
{
	char **commands;
	char **temp_ptr;
	int size;
	operation *next;
	void (*function)(char**, int size);
}oparation;

oparation *parse_list(Token *head);
void exec_tree(operation *head);


#endif
