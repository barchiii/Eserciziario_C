#include <stdio.h>
#include <string.h>
#define MAX_AUTO 100

// Definizione struttura Auto
typedef struct {
    char ModelloAuto[50];
    char marca[50];
    int cilindrata;
    float prezzo;
    int anno_immatricolazione;
    char targa[20];
} Auto;

// Prototipi delle funzioni
void prezzo_max_min(Auto autoList[], int n);
void ordina_per_anno(Auto autoList[], int n);
void visualizza_auto_prezzo(Auto autoList[], int n, float prezzo);
void cerca_auto_targa(Auto autoList[], int n, char targa[]);
float media_prezzi(Auto autoList[], int n);
void visualizza_auto_anno(Auto autoList[], int n, int anno);

int main() {
    Auto autoList[MAX_AUTO];
    int n, scelta;
    printf("Quante auto vuoi inserire? ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        printf("\nAuto %d:\n", i+1);
        printf("Modello: ");
        scanf("%s", autoList[i].ModelloAuto);
        printf("Marca: ");
        scanf("%s", autoList[i].marca);
        printf("Cilindrata: ");
        scanf("%d", &autoList[i].cilindrata);
        printf("Prezzo: ");
        scanf("%f", &autoList[i].prezzo);
        printf("Anno immatricolazione: ");
        scanf("%d", &autoList[i].anno_immatricolazione);
        printf("Targa: ");
        scanf("%s", autoList[i].targa);
    }
    do {
        printf("\nMenu:\n");
        printf("1. Prezzo massimo e minimo\n");
        printf("2. Ordinare per anno immatricolazione\n");
        printf("3. Visualizza auto sopra un prezzo\n");
        printf("4. Cerca auto per targa\n");
        printf("5. Media prezzi\n");
        printf("6. Visualizza auto per anno\n");
        printf("0. Esci\n");
        printf("Scegli: ");
        scanf("%d", &scelta);
        switch(scelta) {
            case 1:
                prezzo_max_min(autoList, n);
                break;
            case 2:
                ordina_per_anno(autoList, n);
                printf("Auto ordinate per anno:\n");
                for(int i=0; i<n; i++)
                    printf("%s %d\n", autoList[i].ModelloAuto, autoList[i].anno_immatricolazione);
                break;
            case 3: {
                float prezzo;
                printf("Inserisci il prezzo minimo: ");
                scanf("%f", &prezzo);
                visualizza_auto_prezzo(autoList, n, prezzo);
                break;
            }
            case 4: {
                char targa[20];
                printf("Inserisci la targa: ");
                scanf("%s", targa);
                cerca_auto_targa(autoList, n, targa);
                break;
            }
            case 5:
                printf("Media prezzi: %.2f\n", media_prezzi(autoList, n));
                break;
            case 6: {
                int anno;
                printf("Inserisci l'anno: ");
                scanf("%d", &anno);
                visualizza_auto_anno(autoList, n, anno);
                break;
            }
        }
    } while(scelta != 0);
    return 0;
}

// Trova e visualizza il prezzo massimo e minimo con il modello
void prezzo_max_min(Auto autoList[], int n) {
    if(n == 0) return;
    float max = autoList[0].prezzo, min = autoList[0].prezzo;
    int idx_max = 0, idx_min = 0;
    for(int i=1; i<n; i++) {
        if(autoList[i].prezzo > max) {
            max = autoList[i].prezzo;
            idx_max = i;
        }
        if(autoList[i].prezzo < min) {
            min = autoList[i].prezzo;
            idx_min = i;
        }
    }
    printf("Prezzo massimo: %.2f, Modello: %s\n", max, autoList[idx_max].ModelloAuto);
    printf("Prezzo minimo: %.2f, Modello: %s\n", min, autoList[idx_min].ModelloAuto);
}

// Ordina la lista per anno di immatricolazione
void ordina_per_anno(Auto autoList[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(autoList[i].anno_immatricolazione > autoList[j].anno_immatricolazione) {
                Auto tmp = autoList[i];
                autoList[i] = autoList[j];
                autoList[j] = tmp;
            }
        }
    }
}

// Visualizza le auto con prezzo >= scelto
void visualizza_auto_prezzo(Auto autoList[], int n, float prezzo) {
    printf("Auto con prezzo >= %.2f:\n", prezzo);
    for(int i=0; i<n; i++) {
        if(autoList[i].prezzo >= prezzo)
            printf("%s\n", autoList[i].ModelloAuto);
    }
}

// Cerca auto per targa e visualizza tutti i campi
void cerca_auto_targa(Auto autoList[], int n, char targa[]) {
    for(int i=0; i<n; i++) {
        if(strcmp(autoList[i].targa, targa) == 0) {
            printf("Modello: %s\nMarca: %s\nCilindrata: %d\nPrezzo: %.2f\nAnno: %d\nTarga: %s\n",
                autoList[i].ModelloAuto, autoList[i].marca, autoList[i].cilindrata,
                autoList[i].prezzo, autoList[i].anno_immatricolazione, autoList[i].targa);
            return;
        }
    }
    printf("Auto con targa %s non trovata.\n", targa);
}

// Calcola la media dei prezzi
float media_prezzi(Auto autoList[], int n) {
    float somma = 0;
    for(int i=0; i<n; i++)
        somma += autoList[i].prezzo;
    return n ? somma/n : 0;
}

// Visualizza le auto con anno scelto
void visualizza_auto_anno(Auto autoList[], int n, int anno) {
    printf("Auto con anno %d:\n", anno);
    for(int i=0; i<n; i++) {
        if(autoList[i].anno_immatricolazione == anno)
            printf("%s\n", autoList[i].ModelloAuto);
    }
}