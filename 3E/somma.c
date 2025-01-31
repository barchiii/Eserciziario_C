/* Programma che legge N numeri interi, con N scelto dall'utente,
   e calcola la somma e la media dei numeri inseriti
   visualizzandone i risultati a video */

#include <stdio.h>
#define nome 10 // Dichiarazione di una costante, fuori dall'inizio del main.
void main()
{
    // Dichiarazione e inizializzazione delle variabili
    int n, num, somma = 0, n2, i = 0; // Somma va inizializzata
    float media;
    printf("Quanti numeri vuoi inserire?\n"); // Stampa a video della richiesta
    scanf("%d", &n);                          // Acquisizione dei valori in input
    n2 = n;
    while (n2 > 0)
    {
        i = i + 1;
        printf("Inserisci il numero %d\n", i);
        scanf("%d", &num);
        somma = somma + num; // Se non inizializzamo somma il computer gli assegna un valore a random
        n2--;
    }

    media = (float)somma / n; // Casting, non si possono usare variabili di deu tipi diversi in una stessa assegnazione
    printf("\n");
    printf("La somma risulta: %d\n", somma);
    printf("La media risulta: %.2f\n", media);
    printf("La costante ha valore: %d\n", nome);
}