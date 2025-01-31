#include <stdio.h>
#include <string.h>

// Funzione per eliminare un carattere dalla stringa
void elimina_carattere(char *str, char c) {
    int len = strlen(str);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] != c) {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0'; // Termina la stringa correttamente dopo l'eliminazione dei caratteri
}

// Funzione per eliminare un carattere in base alla sua posizione
void elimina_per_posizione(char *str, int posizione) {
    int len = strlen(str);
    if (posizione >= 0 && posizione < len) {
        for (int i = posizione; i < len - 1; i++) {
            str[i] = str[i + 1];
        }
        str[len - 1] = '\0'; // Termina la stringa correttamente dopo l'eliminazione del carattere
    }
}

// Funzione per aggiungere un carattere alla fine della stringa
void aggiungi_carattere(char *str, char c) {
    int len = strlen(str);
    str[len] = c;
    str[len + 1] = '\0'; // Termina la stringa correttamente dopo l'aggiunta del carattere
}

int main() {
    char stringa[100];
    printf("Inserisci una stringa: ");
    scanf("%s", stringa);

    // 1) Eliminare un carattere scelto dall'utente (o più di 1 se si ripetono)
    char carattere;
    printf("Inserisci il carattere da eliminare: ");
    scanf(" %c", &carattere);
    elimina_carattere(stringa, carattere);
    printf("Stringa dopo l'eliminazione del carattere: %s\n", stringa);

    // 2) Eliminare un carattere scelto dall'utente in base alla sua posizione
    int posizione;
    printf("Inserisci la posizione del carattere da eliminare: ");
    scanf("%d", &posizione);
    elimina_per_posizione(stringa, posizione);
    printf

