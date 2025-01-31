/* Scrivere un programma in C che, 
 dopo aver letto N numeri (n scelto dall'utente) 
 calcoli e visualizzi a video la somma dei numeri positivi, 
 la somma dei numeri negativi in valore assoluto, 
 il conteggio dei numeri negativi e positivi, 
 la media dei numeri positivi e negativi. */
 
#include <stdio.h>

void main() {
    int n, numero, i;
    int sommaPositivi = 0, sommaNegativi = 0;
    int conteggioPositivi = 0, conteggioNegativi = 0;
    float mediaPositivi, mediaNegativi;

    // Input del numero di elementi da analizzare
    printf("Inserisci il numero di elementi (N): ");
    scanf("%d", &n);

    // Leggi e elabora i numeri
    for (i = 0; i < n; i++) {
        printf("Inserisci il %d numero: ", i + 1);
        scanf("%d", &numero);

        if (numero >= 0) {
            // Numero positivo
            sommaPositivi = sommaPositivi + numero;
            conteggioPositivi++;
        } 
		else {
            // Numero negativo
            sommaNegativi = sommaNegativi + (numero * -1);
            conteggioNegativi++;
        }
    }

    // Output
    printf("\nSomma dei numeri positivi: %d\n", sommaPositivi);
    printf("Somma dei numeri negativi (valore assoluto): %d\n", sommaNegativi);
    printf("Conteggio dei numeri positivi: %d\n", conteggioPositivi);
    printf("Conteggio dei numeri negativi: %d\n", conteggioNegativi);
    
    // Stampo le medie solo se ci sono elementi positivi o negativi
    if (conteggioPositivi > 0) {
    	mediaPositivi = (float)sommaPositivi / conteggioPositivi;
		printf("Media dei numeri positivi: %.2f\n", mediaPositivi);
	}
	else {
		printf("Media dei numeri positivi: Non esiste");
	}
	
	if (conteggioNegativi > 0) {
    	mediaNegativi = (float)sommaNegativi / conteggioNegativi;
		printf("Media dei numeri negativi: %.2f\n", mediaPositivi);
	}
	else {
		printf("Media dei numeri negativi: Non esiste");
	}


    

    
}

