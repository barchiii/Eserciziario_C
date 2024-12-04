#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/wait.h>

void convertiStringa(char str[]) {

    int n = strlen(str);

    for(int i = 0; i < n; i++) {
        str[i] = toupper(str[i]);
    }
}

int main(int argc, char* argv[]) {

    char str[strlen(argv[1])];

    int pid = fork();

    if (pid == 0) {

        strcpy(str, argv[1]);
        convertiStringa(str);
        printf("\nLa stringa in maiuscolo: %s\n", str);
        sleep(60);
        exit(0);
    
    }

    else {

        wait(&pid);

    }

    printf("\nIl programma è terminato\n");

    return 0;
}

//./03_stringToupper ciao
