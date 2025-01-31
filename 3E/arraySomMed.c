/* Programma che legge N numeri interi, con N scelto dall'utente
(N max 20), e calcola la somma e media dei numeri inseriti maggiori di 5
visualizzandone i risultati a video
*/
// ctrl + maiusc + i per formattazione automatica

#include <stdio.h>
void main()
{
    // Dichiarazione e inizializzazione delle variabili e array
    int n, num, somma = 0, vett[30], i, cont = 0;
    float media;

    do
    {
        printf("Quanti numeri vuoi inserire?\n");
        scanf("%d", &n);
    } while (n <= 0 || n > 20);

    for (i = 0; i < n; i++)
    {
        printf("Inserisci un numero\n");
        scanf("%d", &vett[i]); // Prendo il vettore nella posizione i, cosi si andrà a riempire ogni posizione ogni volta che inseriamo un numero
        if (vett[i] > 5)
        {
            cont++;
            somma = somma + vett[i]; // Se non inizializzamo somma il computer gli assegna un valore a random
        }
    }

        printf("\n");
    if (cont > 0)
    {
        media = (float)somma / cont; // Casting, non si possono usare variabili di deu tipi diversi in una stessa assegnazione
        printf("La media dei numeri maggiori di 5 risulta: %.2f\n", media);
    }

    else
        printf("Non ci sono numeri maggiori di 5\n");
    printf("La somma dei numeri maggiori di 5 risulta: %d\n", somma);
}