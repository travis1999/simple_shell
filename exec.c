#define _POSIX_SOURCE
#include "exec.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

/**
 * env - env func
 * @args: args to env
 * @size: size of env args
 * Return: None
 */
void env(char **args __attribute__((unused)), int size __attribute__((unused)))
{
	int i;
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
	}

	if (child_pid == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
			printf("\n%s", environ[i]);
		printf("\n");
		exit(0);
	}
	else
	{
		wait(&status);
	}
}

/**
 * exec_shell - env func
 * @args: args to env
 * @size: size of env args
 * Return: None
 */
void exec_shell(char **args, int size __attribute__((unused)))
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
	}

	if (child_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
			perror("Error");
		exit(0);
	}
	else
	{
		wait(&status);
	}
}
