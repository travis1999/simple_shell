#ifndef EXEC_H
#define EXEC_H

extern char **environ;

void env(char **args, int size);
void exec_shell(char **args, int size);

#endif