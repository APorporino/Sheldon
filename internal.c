#include "shell.h"

void printDir() {
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("\nDirectory: %s \n\n", cwd);
}