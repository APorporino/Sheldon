#include "shell.h"

char userName[MAX_LENGTH] = {0};

int main(int argc, char* argv[]) {
    init_shell();

    while (1) {
        printf("%s-SHELDON >> ", userName);
        char userInput[MAX_LENGTH];
        int not_valid = getUserInput(userInput);
        if (not_valid) continue;

        if (handleInput(userInput)) {
            printf("did nothing\n");
        } else {
            printf("soemthign\n");
            pid_t pid = fork();
            if (pid == -1) {
                printf("Forking failed");
            } else if (pid == 0) {
                //handleInput(userInput);
                printf("MY-CHILD\n");
                return 0;
            } else {
                wait(NULL);
                printf("MY-PARENT\n");
            }
        }
    }

    return 0;
}

void init_shell() {
    // can load a config file here
    // if find sheldon_profile here, read it line by line and run the code
    // .sheldon_profile

    printf("*******  WELCOME TO SHELDON!  ********\n");
    printf("****  v1. anthony porporino 2020  ****\n");
    printf("**********  a simple shell  ********** \n");
    printf("\nWhat is your name? : ");
    // this line stores users input into userName. The %*c removes the \n char from stdin
    scanf("%s%*c", userName);
}

int getUserInput(char* inputString) {
    // char* buf;
    // buf = readline("");

    fgets(inputString, MAX_LENGTH, stdin);
    if (strlen(inputString) != 0) {
        // add_history(buf);
        // strcpy(inputString, buf);
        return 0;
    } else {
        return 1;
    }
}

// goals: open apps ex: open chrome. Alias commands, make folders
int handleInput(char* input) {
    if (strcmp(input, "help\n") == 0) {
        printf("HELP ON THE WAY\n");
        return 1;
    } else if (strcmp(input, "cwd\n") == 0) {
        printDir();
        return 1;
    } else if (strcmp(input, "quit\n") == 0) {
        printf("Goodbye...\n");
        exit(0);
    } else {
        return 0;
    }
}
