#include "tokenizer.h"
#include <stdlib.h>

#ifdef DEBUG
#include <stdio.h>
#endif
#include "strutils.h"


/**
 * new_token - creates a new token structure
 * @type: type of token
 * @value: pointer to the value of the token
 * Return: the new created token
 */

Token *new_token(char type, void *value)
{
	Token *new_token = malloc(sizeof(Token));

	if (new_token == NULL)
		return (NULL);

	new_token->type = type;
	new_token->value = value;
	new_token->next = NULL;

	return (new_token);
}

/**
 * free_tokens - frees the tokens
 * @head: head of the tokens
 */

void free_tokens(Token *head)
{
	if (head->next != NULL)
		free_tokens(head->next);
	free(head->value);
	free(head);
}

/**
 * append_token - adds a new token to the linked list
 * @head: head of the list
 * @new_token: token to be added to linked list
 * Return: none
 */
Token *append_token(Token *head, Token *new_token)
{
	Token *next_token;

	if (head == NULL)
		head = new_token;
	else
	{
		next_token = head;
		while (1)
		{
			if (next_token->next == NULL)
			{
				next_token->next = new_token;
				break;
			}
			next_token = next_token->next;
		}
	}
	return (head);
}


Token *make_tokens(char *src)
{
	Token *head = NULL;
	Token *current_token;
	char *str;
	char temp[256];
	size_t size = 0;
	size_t idx;
	char type = 's';
	char *builtins[] = {"env", NULL};

	while (*src != '\0')
	{
		while (*src != '\0')
		{
			if (*src == ' ')
			{
				src++;
				break;
			}
			temp[size] = *src;
			src++;
			size++;
		}
		str = malloc(size + 1);
		for (idx = 0; idx < size; idx++)
		{
			str[idx] = temp[idx];
		}
		str[idx] = '\0';
		size = 0;
		if (str_exists(str, builtins))
			type = 'b';
		else
			type = 's';
		current_token = new_token(type, (void *)str);
		head = append_token(head, current_token);
	}

	return (head);
}

#ifdef DEBUG
/**
 * print_tokens -prints the tokens
 * @head: start of list
 * Return: None
 */
void print_tokens(Token *head)
{
	Token *next_token = head;

	printf("\n\ttokens\n");

	while (next_token != NULL)
	{
		if (next_token->type == 's')
			printf("Type: string, Value: %s, addr: %p\n",
			(char *)(next_token->value), next_token->value);

		if (next_token->type == 'i')
			printf("Type: integer, Value: %d, addr: %p\n",
			*(int *)(next_token->value), next_token->value);

		if (next_token->type == 'd')
			printf("Type: decimal, Value: %lf, addr: %p\n",
			*(double *)(next_token->value), next_token->value);

		next_token = next_token->next;
	}
}
#endif
