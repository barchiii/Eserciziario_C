#include <stdio.h>

#define SIZE 10

int main() {
    int arr[SIZE], k;

    // Input dell'array
    printf("Inserisci 10 numeri: \n");
    for (int i = 0; i < SIZE; i++) {
        printf("\nInserisci il numero %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Input di K
    printf("\nInserisci K > 0: ");
    scanf("%d", &k);

    // Ruota l'array
    int temp[SIZE]; //array temporaneo per fare le operazioni
    k = k % SIZE; // Normalizza K per evitare spostamenti inutili

    if (k < 0) // Se K è negativo, lo convertiamo in positivo
        k += SIZE;

    // Sposta gli elementi
    for (int i = 0; i < SIZE; i++) {
        temp[(i + k) % SIZE] = arr[i]; // Sposta da i, posizione iniziale, a i + k posizione finale
    }

    // Copia i valori nell'array originale
    for (int i = 0; i < SIZE; i++) {
        arr[i] = temp[i];
    }

    // Output dell'array ruotato
    printf("Array dopo la rotazione: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d \t", arr[i]); // Stampa l'array, \t indica una tabulazione
    }

    return 0;
}