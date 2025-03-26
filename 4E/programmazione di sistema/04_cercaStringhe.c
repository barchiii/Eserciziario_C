/* Si scriva un’applicazione concorrente che presenti la seguente interfaccia:

cercaStringhe FileIn.txt

dove FileIn.txt è un nome assoluto di file.

L’applicazione deve contare il numero di volte in cui un insieme di stringhe
che l’utente inserisce da terminale (una alla volta) compaiono all’interno
del file passato come parametro in argv[1].
L’applicazione termina quando l’utente inserisce la stringa “fine”.

L’applicazione deve visualizzare il numero di volte in cui ogni stringa
compare nel file e anche, al termine dell’esecuzione, il numero totale di
stringhe trovate nel file.

L'applicazione dovrà tenere conto dell'eventuale molteplicità di una parola
dentro alla stessa stringa, per fare questo si consiglia di invocare grep
con il flag -ow e redirezionare il suo output in wc (invocato con il flag -l). */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // controllo argomenti
    if (argc != 2)
    {
        printf("Argomenti errarti.\n");
        exit(1);
    }

    char stringa[100], file[100];
    int cnt = 0, p1p2[2], p2p0[2], pid;

    // ciclo di ricerca
    while(1)
    {
        printf("Inserisci la parola da cercare: ");
        scanf("%s", stringa);

        if(strcmp(string, "fine") == 0)
        {
            printf("Numero di parole trovate: %d\n", cnt);
            exit(0);
        }

        pipe(p1p2);
        pid = fork();

        // processo figlio grep
        if (pid == 0)
        {
            close(p1p2[0]);
            close(1);
            dup(p1p2[1]);
            close(p1p2[1]);
            execl("/bin/grep", "grep", "-ow", stringa, argv[1], (char *)0); // -ow cerca solo la parola intera
            return -1;
        }

        pipe(p2p0);
        pid = fork();

        // processo figlio wc
        if (pid == 0)
        {
            close(p1p2[1]);
            close(0);
            dup(p1p2[0]);
            close(p1p2[0]);

            close(p2p0[0]);
            close(1);
            dup(p2p0[1]);
            close(p2p0[1]);
            execl("/usr/bin/wc", "wc", "-l", (char *)0); // -l conta le linee
            return -1;
        }

        // chiusura finale processi ancora aperti
        close(p1p2[1]);
        close(p1p2[0]);
        close(p2p0[1]);
        
        read(p2p0[0], file, sizeof(file));
        close(p2p0[0]);
        printf("La parola %s compare %s volte nel file\n", stringa, file);
        cnt += atoi(file); // atoi converte una stringa in un intero

    }

    return 0;
}