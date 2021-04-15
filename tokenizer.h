#ifndef TOKENIZER_H
#define TOKENIZER_H
#include "globals.h"


typedef struct Token
{
	char type;
	void *value;
	struct Token *next;
}Token;


Token *new_token(char type, void *value);
void free_tokens(Token *head);

Token *append_token(Token *head, Token *new_token);
Token *make_tokens(char *src);

#ifdef DEBUG
void print_tokens(Token *head);
#endif

#endif
