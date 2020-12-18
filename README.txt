Sheldon is a simple shell written in C.

#MAKEFILE:
Makefile supports:
    make sheldon: compile the program into executable sheldon

Supports the following internal commands:


Uses readline GNU library for command parsing and history.

All other commands are executed using execvl system call.
