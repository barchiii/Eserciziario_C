/* Leggi il file numeri.txt composto da una sequenza di numeri separati da uno spazio.
Scrivi due file, pari.txt e dispari.txt, nei quali inserisci i numeri letti a seconda del loro valore pari o dispari. */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main()
{
    FILE *inputFile, *pariFile, *dispariFile;
    char buffer[BUFFER_SIZE];
    int num;
    char *carattere;

    // Apri i file
    inputFile = fopen("numeri.txt", "r");
    if (inputFile == NULL)
    {
        printf("Errore apertura numeri.txt");
        return 1;
    }

    pariFile = fopen("pari.txt", "w");
    if (pariFile == NULL)
    {
        printf("Errore apertura pari.txt");
        fclose(inputFile);
        return 1;
    }

    dispariFile = fopen("dispari.txt", "w");
    if (dispariFile == NULL)
    {
        printf("Errore apertura dispari.txt");
        fclose(inputFile);
        fclose(pariFile);
        return 1;
    }

    // Leggi la riga
    if (fgets(buffer, BUFFER_SIZE, inputFile) != NULL)
    {
        carattere = buffer;

        // Estrai numeri uno alla volta
        while (scanf(carattere, "%d", &num) == 1)
        {
            if (num % 2 == 0)
            {
                printf(pariFile, "%d ", num);
            }
            else
            {
                printf(dispariFile, "%d ", num);
            }

            // Vai avanti nella stringa
            while (*carattere != ' ' && *carattere != '\0' && *carattere != '\n')
            {
                carattere++;
            }
            if (*carattere == ' ')
            {
                carattere++;
            }
        }
    }

    // Chiudi i file
    fclose(inputFile);
    fclose(pariFile);
    fclose(dispariFile);

    return 0;
}