/* array di struttura di N città contenente
   Nome, Regione, numero abitani anno precedente, numero abitanti anno corrente
   permette di:
   1- Inserire una o più città
   2- calcolare la media del numero di abitanti dell'anno precedente
   3- visualizzare le città di una certa regione scelta dall'utente
   4- calcolare l'incremento (o il decremento) per ogni città del numero di abitanti
   5- eliminare una città scelta dall'utente
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITTA 10 //numero massimo di citta inseribili

typedef struct Citta {
    char nome[30];
    char regione[30];
    int nAbitantiAnnoPrecedente;
    int nAbitantiAnnoCorrente;
} Citta;

void menu() { //funzione per mostrare il menu
    printf("\nMenu:\n");
    printf("1- Inserire una o più città\n");
    printf("2- Calcolare la media del numero di abitanti dell'anno precedente\n");
    printf("3- Visualizzare le città di una certa regione scelta dall'utente\n");
    printf("4- Calcolare l'incremento (o il decremento) per ogni città del numero di abitanti\n");
    printf("5- Eliminare una città scelta dall'utente\n");
    printf("0- Uscire\n");
    printf("Scegli un'opzione: ");
}

int main() {

    Citta citta[MAX_CITTA];
    int scelta = 0; //variabile per il menu
    int cont = 0; //contatore città inserite
    int somma = 0, differenza = 0;
    double media;
    char sceltaRegione[30];
    char sceltaCitta[30];

    do {
        menu(); //mostra il menu
        scanf("%d", &scelta); //legge la scelta dell'utente
        switch (scelta) {
            case 1: //inserisci citta
                printf("Quante citta vuoi inserire?\n");
                scanf("%d", &cont);
                for (int i = 0; i < cont; i++) {
                    if (cont < MAX_CITTA) {
                        //inserimento nome
                        printf("Inserisci il nome della città\n");
                        scanf("%s", &citta[i].nome);
                        //inserimento regione
                        printf("Inserisci la regione della citta\n");
                        scanf("%s", &citta[i].regione);
                        //inserimento numero di abitanti dell'anno precedente
                        printf("Inserisci il numero di abitanti dell'anno precedente della citta\n");
                        scanf("%d", &citta[i].nAbitantiAnnoPrecedente);
                        //inserimento numero di abitanti dell'anno corrente
                        printf("Inserisci il numero di abitanti dell'anno corrente\n");
                        scanf("%d", &citta[i].nAbitantiAnnoCorrente);
                    }
                    printf("\nInserimento andato a buon fine\n");
                }
                break;

            case 2: //calcola media numero abitanti anno precedente di tutte le citta
                for (int i = 0; i < cont; i++) {
                    somma += citta[i].nAbitantiAnnoPrecedente; //calcolo la somma degli abitanti
                }
                media = somma / cont; //calcolo la media

                printf("\nLa media degli abitanti dell'anno precedente è %.2f\n", media); //stampa la media a due cifre decimali
                break;

            case 3: //visualizzare le citta di una certa regione
            
                printf("\nDi che regione vuoi visualizzare le citta?\n");
                scanf("%s", &sceltaRegione);
                for (int i = 0; i < cont; i++) {
                    if (strcmp(citta[i].regione, sceltaRegione) == 0) { //confronto le stringhe per trovare le citta della regione scelta
                        printf("\nCittà: %s\n", citta[i].nome);
                    }
                }

                break;

            case 4: //calcolare l'incremento o il decremento per ogni citta del numero di abitanti tra anno precedente e anno corrente
                for (int i = 0; i < cont; i++) {
                    differenza = citta[i].nAbitantiAnnoCorrente - citta[i].nAbitantiAnnoPrecedente; //calcolo la differenza tra anno corrente e anno precedente
                    if (differenza > 0) {
                        printf("La città di %s ha avuto un incremento di %d abitanti nel corso di un anno\n", citta[i].nome, differenza); //stampo l'incremento
                    }
                    else if (differenza < 0) {
                        printf("La città di %s ha avuto un decremento di %d abitanti nel corso di un anno\n", citta[i].nome, -differenza); //stampo il decremento
                    }
                    else {
                        printf("La città di %s non ha avuto variazioni nel numero di abitanti nel corso di un anno\n", citta[i].nome); //stampo nessuna variazione
                    }
                }
                break;

            case 5: //eliminare una citta scelta dall'utente
                printf("Quale città vuoi eliminare?\n"); 
                scanf("%s", &sceltaCitta);
                for (int i = 0; i < cont; i++) {
                    if (strcmp(citta[i].nome, sceltaCitta) == 0) {
                        for (int j = i; j < cont - 1; j++) {
                            citta[j] = citta[j + 1]; //sposto tutti gli elementi successivi di una posizione indietro
                        }
                        cont--; //decremento il contatore delle città
                        printf("Città eliminata con successo\n");
                    }
                    else {
                        printf("Città non trovata\n");
                    }
                }
                break;

            case 0:
                printf("Uscita in corso...\n"); //messaggio di uscita
                break;
        }
    } while(scelta != 0); //continua finché l'utente non sceglie di uscire

    return 0;
    //possibile miglioria, aggiungere un visualizzatore di tutte le città inserite
}