/* Su una somma di denaro (relativa all'acquito di un prodotto)
 si vuole applicare uno sconto in base all'importo inserito seguendo il seguente schema:
        da 0 a 500 sconto del 10%;
        da 501 a 1000 sconto del 20%;
        oltre i 1001 sconto 30%;
 Il programma dopo aver calcolato e visualizzato a video lo sconto ed il prezzo netto deve permettere di re-inserire
 ulteriori somme di denaro. */

#include <stdio.h>

void main() {
    float importo, sconto, importoSottratto, importoFinale;
    char continua;

    do {
        // Input dell'importo
        printf("Inserisci l'importo dell'articolo: ");
        scanf("%f", &importo);

        // Calcolo dello sconto in base all'importo
        if (importo <= 500) {
            sconto = 0.10;
        } 
		else if (importo <= 1000) {
            sconto = 0.20;
        } 
		else {
            sconto = 0.30;
        }

        // Calcolo dell'importo scontato e del prezzo netto
        importoSottratto = importo * sconto;
        importoFinale = importoFinale + importo - importoSottratto;

        // Visualizzazione dei risultati
        printf("Sconto applicato: %.2f%%\n", sconto * 100);
        printf("Importo sottratto: %.2f\n", importoSottratto);
        printf("Importo parziale: %.2f\n", importoFinale);

        // Chiedi se si vuole inserire un'altra somma di denaro
        printf("Vuoi inserire un'altra somma di denaro? (s/n): ");
        scanf(" %c", &continua);

    } while (continua == 's' || continua == 'S');
    
    printf("\n");
    printf("Importo finale : %.2f\n", importoFinale);
    printf("Arrivederci e grazie per aver acquistato da noi!\n");
}

