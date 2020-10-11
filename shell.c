#include "shell.h"

int main(int argc, char *argv[]) {
    // can load a config file here

    char userInput[MAX_LENGTH] = {0};
    char userName[MAX_LENGTH] = {0};

    printf("*******  WELCOME TO SHELDON!  ********\n****  v1. anthony porporino 2020  ****\n**********  a simple shell  ********** \n\n What is your name?\n");

    // this line stores users input into userName. The %*c removes the \n char from stdin
    scanf("%s%*c", userName);
    // the %*c in scanf replaces the next line

    while (strcmp(userInput, "quit") != 0) {
        printf("%s-SHELDON >>", userName);
        fgets(userInput, MAX_LENGTH, stdin);

        int pid;

        if ((pid = fork()) == 0) {
            printf("\nYOUR COMMAND WAS: %s\n", userInput);
        }

        wait(NULL);
    }
    return 0;
}
