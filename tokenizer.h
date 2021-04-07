#ifndef TOKENIZER_H
#define TOKENIZER_H


typedef struct Token Token;

typedef struct Token
{
	char type;
	void *value;
	Token *next;
}Token;


Token *new_token(char type, void *value);
void free_tokens(Token *head);
void print_tokens(Token *head);
Token *append_token(Token *head, Token *new_token);
Token *make_tokens(char *src);

#endif
