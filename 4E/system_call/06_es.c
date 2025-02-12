/* Scrivere un programma in linguaggio C che legge da argv una serie di stringhe,
le ordina in senso crescente o decrescente in funzione del flag usato in argv[2].
Si utilizzi un algoritmo di ordinamento a scelta. Si scriva il risultato
sia a video che su un file il cui nome risiede in argv[1].

Esempio:
$ ./a.out file.txt --asc ciao a tutti
a
ciao
tutti

$ cat file.txt 
a
ciao
tutti

Esempio:
$ ./a.out file.txt --desc ciao a tutti
tutti
ciao
a

$ cat file.txt 
tutti
ciao
a */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

void swap(int argc, char *argv[], int ascending)
{
    int i, j;
    char *temp;

    for (i = 0; i < argc - 3; i++)
    {
        for (j = 3; j < (argc - i - 1); j++)
        {
            if ((ascending && strcmp(argv[j], argv[j + 1]) > 0) ||
                (!ascending && strcmp(argv[j], argv[j + 1]) < 0))
            {
                temp = argv[j];
                argv[j] = argv[j + 1];
                argv[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

    int ascending = strcmp("--asc", argv[2]) == 0;
    if (!ascending && strcmp("--desc", argv[2]) != 0)
    {
        printf("Ordinamento non valido\n");
        exit(1);
    }

    swap(argc, argv, ascending);

    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("Errore apertura file");
        exit(1);
    }

    for (int i = 3; i < argc; i++)
    {
        write(fd, argv[i], strlen(argv[i]));
        write(fd, "\n", 1);
    }

    close(fd);
    return 0;
}