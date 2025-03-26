/* Si scriva un’applicazione concorrente che presenti la seguente interfaccia:

cercaStringhe FileIn

dove FileIn è un nome assoluto di file.

L’applicazione deve contare il numero di volte in cui un insieme di stringhe
che l’utente inserisce da terminale (una alla volta) compaiono all’interno
del file passato come parametro in argv[1].
Se in una riga del file una parola compare più volte, al fine del conteggio,
considerare solamente la prima occorrenza. 
L’applicazione termina quando l’utente inserisce la stringa “fine”.
L’applicazione deve visualizzare il numero di volte in cui ogni stringa
compare nel file e anche, al termine dell’esecuzione, il numero totale di
stringhe trovate nel file. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    // controllo argomenti
    if (argc != 2)
    {
        printf("Numero argomenti errato\n");
        exit(1);
    }

    char stringa[100], file[100];
    int pipe(p1p0), cont, pid;

    // dichiarazione pipe
    pipe(p1p0);

    //ciclo di ricerca
    while (1)
    {
        printf("Inserisci la parola da cercare : ");
        scanf("%s", stringa);

        if (strcmp(stringa, "fine") == 0)
        {
            close(p1p0[1]);
            close(p1p0[0]);
            printf("Numero di parole trovate: %d\n", cont);
            exit(0);
        }

        pid = fork();

        // processo figlio grep
        if (pid == 0)
        {
            close(p1p0[0]);
            close(1);
            dup(p1p0[1]);
            close(p1p0[1]);
            execl("/bin/grep", "grep", "-o", stringa, argv[1], (char *)0);
            return -1;
        }

        // processo padre, stampa a video il numero di occorrenze
        read(pipe[0, file, sizeof(file)]);
        printf("La parola %s compare %d volte nel file\n", stringa, file);
        cont += file;
    }
}