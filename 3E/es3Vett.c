/* Scrivere un programma in c 
   che dopo aver inserito un vettore di N numeri 
   controlli l’esistenza di un numero 
   richiesto successivamente all’utente. 
   In caso affermativo visualizzare 
   quante volte si ripete il numero e 
   che posizione/i occupa nel vettore utilizzato. */

#include <stdio.h>

int main() {
    int N, num, i = 0, k = 0;

    // Input della dimensione del vettore
    printf("Inserisci la dimensione del vettore: ");
    scanf("%d", &N);
    
    int vett[N];

	// Riempimento del vettore
    printf("Inserisci i %d numeri del vettore: \n", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &vett[i]);
    }

    // Input del numero da cercare
    printf("Inserisci il numero da cercare: ");
    scanf("%d", &num);

    // Controlla se il numero è nel vettore
    for (i = 0; i < N; i++) {
        if (vett[i] == num) {
            k++;
            printf("Il numero %d si trova alla posizione %d nel vettore\n", num, i + 1);
        }
    }

    // Visualizza il numero di volte che appare
    if (k == 1) {
        printf("\nIl numero %d si ripete 1 volta nel vettore", num);
    } 
    
    else if (k > 1) {
    	printf("\nIl numero %d si ripete %d volte nel vettore", num, k);
	}
	else {
        printf("\nIl numero %d non si trova nel vettore", num);
    }

    return 0;
}
