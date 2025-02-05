/* Si vuole realizzare in linguaggio C un software monoprocesso che implementi il seguente comando:
$ cat file1.txt file2.txt file3.txt /tmp/file4.txt | grep “c”

Dove file[N].txt con N maggiore uguale a 1 sono una serie di files scelti dall'utente e il carattere
"c" è a scopo esemplificativo e potrebbe essere qualsiasi carattere.

Si utilizzino le system call al fine di leggere tutti i file di testo e, per ogni file, ricercare il carattere.
Al termine dell’esecuzione il software dovrà mostrare a video il numero di occorrenze trovate nei files e
dovrà contemporaneamente scrivere l’output su un file di testo il cui path sarà letto da argv.

Esempio:
$ ./a.out file1.txt file2.txt file3.txt k occorrenze.txt
$ Il carattere k compare 10 volte nei files: file1.txt, file2.txt, file3.txt
$ cat occorrenze.txt
$ Il carattere k compare 10 volte nei files: file1.txt, file2.txt, file3.txt

Esempio:
$ ./a.out file1.txt file2.txt file3.txt /tmp/file3.txt q /tmp/occorrenze.txt                                                                     
$ Il carattere q compare 18 volte nei files: file1.txt file2.txt file3.txt /tmp/file3.txt 
$ cat /tmp/occorrenze.txt                                                                                             
$ Il carattere q compare 18 volte nei files: file1.txt file2.txt file3.txt /tmp/file3.txt


Osservazioni:
essendo il software monoprocesso non è necessario usare le pipe
prestare attenzione all’uso corretto di argv
si ricorda che il software deve funzionare per un numero arbitrario di files di input.
i percorsi dei files possono essere sia assoluti che relativi 
 

Suggerimento:
Per facilitare la ricerca è possibile leggere un singolo carattere per volta usando la funzione read.
Utilizzare la funzione strcat per concatenare due stringhe. */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int lunghezza_stringa(int argc, char *argv[]);
{
    int dim = 0;
    for (int i = 1; i < argc - 2; i++) // -2 per escludere il carattere e il file di output
    {
        dim = dim + strlen(argv[1]) + 1;
    }
    return dim;
}

void crea_stringa_file(int argc, char *argv[], char str[])
{
    str[0] = '\0'; // inizializzo la stringa
    for (int i = 1; i < argc - 2; i++)
    {
        strcat(stringa, argv[i]);
        strcat(stringa, " ");
    }
    strcat(str, "\n"); // aggiungo un a capo
}

int main () {

    if (argc < 4) // controllo il numero di argomenti
    {
        printf("Errore: numero di argomenti sbagliato\n");
        exit(1);
    }

    int dim = lunghezza_stringa(argc, argv); // calcolo la lunghezza della stringa

    char stringa[dim], carattere; // dichiaro la stringa e il carattere da trovare
    stringa[dim] = crea_stringa_file(argc, argv, stringa); // creo la stringa con i nomi dei file

    int file, occorenze = 0; // dichiaro il file descriptor e il contatore
    char output[dim + 100]; // dichiaro la stringa di output

    for (int i = 0; i < argc - 2; i++)
    {
        file = open(argv[i], O_RDONLY); // apro il file in sola lettura 

        if (file < 0) // controllo se il file è stato aperto correttamente
        {
            printf("Errore nell'apertura del file %s\n", argv[i]);
            exit(2);
        }

        while (read(file, &carattere, sizeof(carattere)) > 0) // leggo un carattere alla volta
        {
            if (carattere == argv[argc - 2][0]) // controllo se il carattere è uguale a quello cercato
            {
                occorenze++;
            }
        }
        close(file); // chiudo il file
    }

    sprintf(output, "Il carattere %c compare %d volte nei file: %s", argv[argc - 2], occorenze, stringa); // creo la stringa di output

    file = open(argv[argc - 1], O_WRONLY | O_CREAT, 0666); // apro il file di output
    write(file, output, strlen(output)); // scrivo la stringa nel file
    close(file); // chiudo il file

    write(1, output, strlen(output)); // stampo la stringa a video

    return 0;
}