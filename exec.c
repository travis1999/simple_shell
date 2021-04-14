#include "exec.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>


void env(char **args, int size)
{
	int i;
	extern char **environ;
	pid_t child_pid;
	int return_status;

	child_pid = fork();

	if (child_pid == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
        	printf("\n%s", environ[i]);
	}
	else if(child_pid < 0)
	{
		perror("fork");
	}
	else
	{      
		waitpid(child_pid, &return_status, 0);
	}
}

void exec_shell(char **args, int size)
{
	pid_t child_pid;
	int return_status;

	child_pid = fork();

	if (child_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
        	perror("Error");
	}
	else if(child_pid < 0)
	{
		perror("fork");
	}
	else
	{      
		waitpid(child_pid, &return_status, 0);
	}
}