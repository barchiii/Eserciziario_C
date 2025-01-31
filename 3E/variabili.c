// Programma variabili e operatori

#include <stdio.h>
void main()
{
    int num;          // dichiarazione variabile intera
    float numReale;   // dichiarazione variabile reale
    double numGrande; // dichiarazione variabile intera doppia
    char lettera;     // dichiarazione variabile carattere
    char parola[10];  // dichiarazione variabile parola, tra le parentesi quadre va la lunghezza
    int lettera2;     // dichiarazione variabile

    printf("Inserisci un numero\n");
    scanf("%d", &num);
    lettera = 'a';
    lettera2 = 'a'; // In questo modo visualizza il codice nella tabella ascii della lettera
    printf("Il numero inserito e': %d\n", num);
    printf("\n");
    printf("La lettera inserita e': %c\n", lettera);
    printf("Il codice della lettera e': %d \n", lettera2);
}