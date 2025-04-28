#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main (int argc, char* argv[]) {
    FILE *origine, *destinazione;
    unsigned char buffer[BUFFER_SIZE]; // Buffer per la lettura, unsigned char va da -128 a 127
    int n; // Numero di byte letti

    if (argc != 3) {
        printf("Errore: numero di argomenti non valido.\n");
        exit(1);
    }

    origine = fopen(argv[1], "r");
    if (origine == NULL) {
        printf("Errore: impossibile aprire il file di origine.\n");
        exit(1);
    }

    else {
        destinazione = fopen(argv[2], "w");
        if (destinazione == NULL) {
            printf("Errore: impossibile aprire il file di destinazione.\n");
            fclose(origine);
            exit(1);
        }

        else {
            while (!feof(origine)) {
                n = fread(buffer, 1, BUFFER_SIZE, origine); //al posto di 1(byte) possiamo mettere anche sizeof(unsigned char)
                
                if (n > 0) {
                    fwrite(buffer, 1, n, destinazione); //al posto di 1(byte) possiamo mettere anche sizeof(unsigned char)
                }
            }
        }
    }

    fclose(origine);
    fclose(destinazione);
    printf("Copia del file completata.\n");

    return 0;
}