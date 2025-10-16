#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Funzione che controlla se una stringa contiene solo lettere
int soloLettere(char s[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (!isalpha(s[i])) {
            return 0; // trovato un carattere non alfabetico
        }
    }
    return 1;
}

// Funzione che conta quante volte compare una lettera scelta
int contaLettera(char s[], char c) {
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) count++;
    }
    return count;
}

// Funzione che divide la stringa in lettere di posizione pari e dispari
void separaPariDispari(char s[], char pari[], char dispari[]) {
    int p = 0, d = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (i % 2 == 0) pari[p++] = s[i];
        else dispari[d++] = s[i];
    }
    pari[p] = '\0';
    dispari[d] = '\0';
}

// Funzione che controlla se la stringa contiene doppie
int contieneDoppie(char s[]) {
    for (int i = 0; s[i+1] != '\0'; i++) {
        if (s[i] == s[i+1]) return 1; // trovata doppia
    }
    return 0;
}

// Funzione che conta vocali e consonanti
void contaVocaliConsonanti(char s[], int *vocali, int *consonanti) {
    *vocali = 0; *consonanti = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = tolower(s[i]);
        if (isalpha(c)) {
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                (*vocali)++;
            else
                (*consonanti)++;
        }
    }
}

// Funzione che stampa le lettere comuni tra due stringhe
void lettereComuni(char s1[], char s2[]) {
    int stampate[256] = {0}; // evitiamo di stampare lettere duplicate
    printf("Lettere comuni: ");
    for (int i = 0; s1[i] != '\0'; i++) {
        for (int j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j] && !stampate[s1[i]]) {
                printf("%c ", s1[i]);
                stampate[s1[i]] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    char str1[100], str2[100], pari[100], dispari[100];
    char c;

    // Inserimento della prima stringa
    printf("Inserisci la prima stringa: ");
    scanf("%s", str1);

    // --- PUNTO 1: Verifica che contenga solo lettere ---
    if (soloLettere(str1))
        printf("La stringa contiene solo lettere.\n");
    else
        printf("La stringa contiene anche caratteri non alfabetici.\n");

    // --- PUNTO 2 e 3: Conta una lettera scelta dall’utente ---
    printf("Inserisci la lettera da contare: ");
    scanf(" %c", &c);
    printf("La lettera '%c' compare %d volte.\n", c, contaLettera(str1, c));

    // --- PUNTO 3: Creazione stringhe di lettere pari e dispari ---
    separaPariDispari(str1, pari, dispari);
    printf("Lettere in posizione pari: %s\n", pari);
    printf("Lettere in posizione dispari: %s\n", dispari);

    // --- PUNTO 4: Verifica se contiene doppie ---
    if (contieneDoppie(str1))
        printf("La stringa contiene doppie.\n");
    else
        printf("La stringa NON contiene doppie.\n");

    // Inserimento della seconda stringa
    printf("\nInserisci la seconda stringa: ");
    scanf("%s", str2);

    // --- PUNTO 1 (seconda parte): Stringa più lunga/corta ---
    if (strlen(str1) > strlen(str2))
        printf("La prima stringa è più lunga.\n");
    else if (strlen(str1) < strlen(str2))
        printf("La seconda stringa è più lunga.\n");
    else
        printf("Le due stringhe hanno la stessa lunghezza.\n");

    // --- PUNTO 2: Lettere contenute in entrambe ---
    lettereComuni(str1, str2);

    // --- PUNTO 3 e 4: Confronto vocali e consonanti ---
    int v1, c1, v2, c2;
    contaVocaliConsonanti(str1, &v1, &c1);
    contaVocaliConsonanti(str2, &v2, &c2);

    if (v1 > v2)
        printf("La prima stringa contiene più vocali.\n");
    else if (v1 < v2)
        printf("La seconda stringa contiene più vocali.\n");
    else
        printf("Le due stringhe hanno lo stesso numero di vocali.\n");

    if (c1 > c2)
        printf("La prima stringa contiene più consonanti.\n");
    else if (c1 < c2)
        printf("La seconda stringa contiene più consonanti.\n");
    else
        printf("Le due stringhe hanno lo stesso numero di consonanti.\n");

    return 0;
}