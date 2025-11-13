#include <stdio.h>
#include <stdlib.h>

#define MAX 100 //numero massimo elementi

//Funzioni

void stampaArr (int arr[],  int n) {
	for (int i = 0; i < n; i++) {
		printf("%d", arr[i]);
	}
	printf("\n");
}

void riempiArr(int arr[], int n){
	do {
		printf("quanti elementi vuoi generare? (n max %d)", MAX);
		scanf("%d", n);
	} while (n <= MAX && n > 0)
	
	for (int i = 0; i < n; i++) {
		arr[i] = (rand() % 100) + 1; //numeri casuali da 0 (+1) a 99 (+1)
	}
}

//cerca numeri, x = numero da trovare
int cercaNum(int arr[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == x) {
			return i;
		}
	}
	return -1;
}

void eliminaPosizioneArr(int arr[], int n, int pos) {
	for (int i = pos; i < n - 1; i++) {
		arr[i] = arr[i + 1];
	}
}

void ordinaArr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp
			}
		}
	}
}


int main(){
	
	int arr[MAX], n = 0, scelta;
	
	riempiArr(arr, n);
	
	
	do {
		printf("\n -- MENU --");
		printf("1) Visualizza Array\n");
		printf("2) Visualizza Array Invertito\n");
		printf("3) Somma e Media degli Elementi\n");
		printf("4) Visualizza Numeri Pari\n");
		printf("5) Visualizza Numeri Dispari\n");
		printf("6) Cerca Numero\n");
		printf("7) Elimina Elemento\n");
		printf("8) Scambia a due a due\n");
		printf("9) Ordina l'Array\n");
		scanf("%d", &scelta);
		
		if (scelta == 1) {
			stampaArr(arr, n);
		}
		
		else if (scelta == 2) {
			for (int i = n - 1; i >= 0; i--) {
				printf("%d", arr[i]);
			}
			printf("\n");
		}
		
		else if (scelta == 3) {
			int somma = 0;
			float media = 0;
			for (int i = 0; i < n; i++) {
				somma += arr[i];
			}
			
			media = somma / n;
			printf("Media: %f", media);
		}
		
		else if (scelta == 4) {
			printf ("Pari: ");
			for (int i = 0; i < n; i++) {
				if (arr[i] % 2 != 0) {
					printf(arr[i]);
				}
			}
		}
		
		
		else if (scelta == 5) {
			printf ("Dispari: ");
			for (int i = 0; i < n; i++) {
				if (arr[i] % 2 != 0) {
					printf(arr[i]);
				}
			}
		}
		
		else if (scelta == 6) {
			int x;
			printf ("Numero da cercare: ");
			scanf("%d", &x);
			int pos = cercaNum(v, n, x);
			if (pos != -1) {
				printf("Numero trovato in posizione %d", pos);
			}
			
			else {
				printf("Numero non trovato");
			}
		}
		
		else if (scelta == 7) {
            int x;
            printf("Numero da eliminare: ");
            scanf("%d", &x);
            int pos = cercaNum(v, n, x);
            if (pos != -1) {
                eliminaPosizioneArr(v, &n, pos);
                printf("Elemento eliminato.\n");
            } 
			else {
				printf("Non trovato.\n");
			}

        } 
		
		else if (scelta == 8) {
			for (int i = 0; i < n - 1; i += 2) {
				int temp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = temp;
			}
			
			stampaArr(v, n);

       } 
		
		else if (scelta == 9) {
			ordinaArr(v, n);
           stampaArr(v, n);
       } 
	   
	   else {
           printf("Uscita...\n");
		}
	   
	   } while (scelta != 0);

    return 0;
}