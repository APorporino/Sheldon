#ifndef SHELL
#define SHELL

#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LENGTH 1024

void init_shell();
void printDir();
int getUserInput(char* inputString);
int handleInput(char* input);

#endif