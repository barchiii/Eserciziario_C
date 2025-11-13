/*
Scrivere un programma in C che dopo aver dichiarato una struttura denominata Persona con i
seguenti campi: Nome, Cognome, età, codice fiscale, reddito annuo, anno_nascita,residenza(città) ;
determini:
1) La persona con reddito annuo più alto e quella con reddito annuo più basso.Visualizzare
per entrambe: nome, cognome, città e reddito.
2) Ordinare la lista delle persone in base all’anno di nascita** (dal più anziano al più
giovane), e visualizzarla.
3) Consentire all’utente di cercare una persona inserendo il codice fiscale..
4) Visualizzare tutte le persone con reddito superiore o uguale a un valore scelto dall’utente.
5) Calcolare la media dei redditi delle persone registrate nel sistema.
6) Visualizzare tutte le persone nate in un anno specifico, scelto dall’utente;
7) Visualizzare l'elenco delle persone raggruppate per città di residenza, indicando per
ciascuna città: Quante persone vi risiedono, L’età media dei residenti

*/

#include <stdio.h>
#include <string.h>
#define MAX_PERSONE 20

// Definizione struttura Persona
typedef struct Persona {
    char Nome[50];
    char Cognome[50];
    int eta;
    char codice_fiscale[20];
    float reddito_annuo;
    int anno_nascita;
    char residenza[50];
} Persona;

// Funzioni
void reddito_max_min(Persona persone[], int n) {
    if (n == 0) {
        return;
    }
    float max = persone[0].reddito_annuo, min = persone[0].reddito_annuo;
    int index_max = 0, index_min = 0;
    for (int i = 1; i < n; i++) {
        if (persone[i].reddito_annuo > max) {
            max = persone[i].reddito_annuo;
            index_max = i;
        }
        if (persone[i].reddito_annuo < min) {
            min = persone[i].reddito_annuo;
            index_min = i;
        }
    }
    printf("\tReddito massimo: %.2f, Persona: %s %s, Città: %s\n", max, persone[index_max].Nome, persone[index_max].Cognome, persone[index_max].residenza);
    printf("\tReddito minimo: %.2f, Persona: %s %s, Città: %s\n", min, persone[index_min].Nome, persone[index_min].Cognome, persone[index_min].residenza);
}

void ordinaAnno(Persona persone[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (persone[i].anno_nascita > persone[j].anno_nascita) {
                Persona tmp = persone[i];
                persone[i] = persone[j];
                persone[j] = tmp;
            }
        }
    }
    printf("Elenco ordinato per anno di nascita:\n");
    for (int i = 0; i < n; i++) {
        printf("\t%s %s, Anno: %d\n", persone[i].Nome, persone[i].Cognome, persone[i].anno_nascita);
    }
}

void cercaCodiceFiscale(Persona persone[], int n, char codice[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(persone[i].codice_fiscale, codice) == 0) {
            printf("\tTrovato: %s %s, Età: %d, Codice: %s, Reddito: %.2f, Anno: %d, Città: %s\n",
                   persone[i].Nome, persone[i].Cognome, persone[i].eta, persone[i].codice_fiscale,
                   persone[i].reddito_annuo, persone[i].anno_nascita, persone[i].residenza);
            return;
        }
    }
    printf("\tCodice fiscale non trovato.\n");
}

void visualizzaReddito(Persona persone[], int n, float valore) {
    printf("Persone con reddito >= %.2f:\n", valore);
    for (int i = 0; i < n; i++) {
        if (persone[i].reddito_annuo >= valore) {
            printf("\t%s %s, Reddito: %.2f\n", persone[i].Nome, persone[i].Cognome, persone[i].reddito_annuo);
        }
    }
}

float mediaRedditi(Persona persone[], int n) {
    float somma = 0;
    for (int i = 0; i < n; i++) {
        somma += persone[i].reddito_annuo;
    }
    return n ? somma / n : 0;
}

void visualizzaAnno(Persona persone[], int n, int anno) {
    printf("Persone nate nell'anno %d:\n", anno);
    for (int i = 0; i < n; i++) {
        if (persone[i].anno_nascita == anno) {
            printf("\t%s %s\n", persone[i].Nome, persone[i].Cognome);
        }
    }
}

void raggruppaCitta(Persona persone[], int n) {
    char citta[MAX_PERSONE][50];
    int count[MAX_PERSONE] = {0};
    int sommaEta[MAX_PERSONE] = {0};
    int numCitta = 0;
    for (int i = 0; i < n; i++) {
        int trovato = 0;
        for (int j = 0; j < numCitta; j++) {
            if (strcmp(persone[i].residenza, citta[j]) == 0) {
                count[j]++;
                sommaEta[j] += persone[i].eta;
                trovato = 1;
                break;
            }
        }
        if (!trovato) {
            strcpy(citta[numCitta], persone[i].residenza);
            count[numCitta] = 1;
            sommaEta[numCitta] = persone[i].eta;
            numCitta++;
        }
    }
    printf("Raggruppamento per città:\n");
    for (int i = 0; i < numCitta; i++) {
        printf("\tCittà: %s, Persone: %d, Età media: %.2f\n", citta[i], count[i], count[i] ? (float)sommaEta[i] / count[i] : 0);
    }
}

int main() {
    Persona persone[MAX_PERSONE] = {
        {"Mario", "Rossi", 45, "RSSMRA80A01H501U", 25000, 1980, "Milano"},
        {"Luca", "Bianchi", 30, "BNCLCU95B12F205X", 32000, 1995, "Roma"},
        {"Anna", "Verdi", 55, "VRDANN70C23L219Z", 18000, 1970, "Milano"},
        {"Giulia", "Neri", 40, "NERGLI85D14H501V", 40000, 1985, "Torino"},
        {"Paolo", "Gialli", 60, "GLIPAO65E05F205Y", 15000, 1965, "Roma"},
        {"Sara", "Blu", 25, "BLUSAR00A01H501U", 27000, 2000, "Napoli"},
        {"Francesco", "Viola", 35, "VIOFRA90B12F205X", 35000, 1990, "Firenze"},
        {"Elena", "Marrone", 50, "MARELE75C23L219Z", 22000, 1975, "Milano"},
        {"Alessandro", "Argento", 28, "ARGALE97D14H501V", 41000, 1997, "Torino"},
        {"Martina", "Oro", 38, "OROMAR85E05F205Y", 16000, 1985, "Roma"},
        {"Davide", "Bronzo", 42, "BRNDAV81A01H501U", 26000, 1981, "Napoli"},
        {"Chiara", "Rame", 33, "RAMCHI90B12F205X", 33000, 1990, "Firenze"},
        {"Simone", "Acciaio", 48, "ACCSIM75C23L219Z", 21000, 1975, "Milano"},
        {"Valentina", "Piombo", 29, "PIBVAL94D14H501V", 42000, 1994, "Torino"},
        {"Giorgio", "Zinco", 59, "ZINGIO64E05F205Y", 14000, 1964, "Roma"},
        {"Federica", "Alluminio", 27, "ALLFED96A01H501U", 28000, 1996, "Napoli"},
        {"Matteo", "Titanio", 36, "TITMAT87B12F205X", 36000, 1987, "Firenze"},
        {"Ilaria", "Platino", 53, "PLAILA70C23L219Z", 19000, 1970, "Milano"},
        {"Stefano", "Mercurio", 41, "MERSTE82D14H501V", 39000, 1982, "Torino"},
        {"Roberta", "Cobalto", 61, "COBROB62E05F205Y", 13000, 1962, "Roma"}
    };
    int n = 20;
    int scelta;
    do {
        printf("\nMenu:\n");
        printf("1. Reddito massimo e minimo\n");
        printf("2. Ordinare per anno di nascita\n");
        printf("3. Cerca per codice fiscale\n");
        printf("4. Visualizza per reddito minimo\n");
        printf("5. Media redditi\n");
        printf("6. Visualizza per anno di nascita\n");
        printf("7. Raggruppa per città\n");
        printf("0. Esci\n");
        printf("Scegli: ");
        scanf("%d", &scelta);
        switch (scelta) {
            case 1:
                reddito_max_min(persone, n);
                break;
            case 2:
                ordinaAnno(persone, n);
                break;
            case 3: {
                char codice[20];
                printf("Inserisci codice fiscale: ");
                scanf("%s", codice);
                cercaCodiceFiscale(persone, n, codice);
                break;
            }
            case 4: {
                float valore;
                printf("Inserisci reddito minimo: ");
                scanf("%f", &valore);
                visualizzaReddito(persone, n, valore);
                break;
            }
            case 5:
                printf("Media redditi: %.2f\n", mediaRedditi(persone, n));
                break;
            case 6: {
                int anno;
                printf("Inserisci anno di nascita: ");
                scanf("%d", &anno);
                visualizzaAnno(persone, n, anno);
                break;
            }
            case 7:
                raggruppaCitta(persone, n);
                break;
        }
    } while (scelta != 0);
    return 0;
}
