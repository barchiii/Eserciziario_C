#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char* argv[]) {

    if (argv != 2) 
    {
        printf ("Numero di argomenti sbagliato");
        exit(1);
    }

    char alfabeto [] = "abcdefghijklmnopqrstuvwxyz"
    int file = open(argv[1], O_CREAT | O_WRONLY, 07444);
    write (file, alfabeto, strlen(alfabeto));
    close(file);

    return 0;
}