#ifndef PARSER_H
#define PARSER_H
#include "globals.h"
#include "tokenizer.h"
#include "exec.h"


typedef struct oparation operation;

typedef struct oparation
{
	char *head;
	operation *next;
	void (*function)(char**);
}oparation;

oparation *parse_list(Token *head);


#endif
