/*  Scrivere un programma in C che dopo aver inserito una stringa a piacere
    permetta di:
    1)Inserire un carattere, scelto dall’utente in una posizione sempre
        scelta dall’utente;
    2)Sostituisca un carattere, scelto dall’utente, con il seguente: X.
*/

#include <stdio.h>
#include <string.h>

void main() {
    char* str[40];
    int pos = 0, scelta = 0;
    char inserire, sostituire;

    printf("Inserisci una stringa\n");
    scanf("%s",&str);

    do {
        printf("Scegli cosa vuoi fare\n");
        printf("1)Inserisci il carattere in una posizione a piacere \n2)Sostituisci un carattere con 'X'\n");
        scanf("%d",&scelta);
    }while (scelta < 1 || scelta > 2);

    switch (scelta) {
        case 1: 
            printf("Che carattere vuoi inserire\n");
            scanf("%c",&inserire);

            printf("In che posizione vuoi inserirlo?\n");
            scanf("%d",&pos);

            str[pos] = inserire; //sbagliato, va aumentata la stringa

            break;

        case 2: 
            printf("Che carattere vuoi sostituire?\n");
            scanf("%c",&sostituire);

            for(int i = 0; i < strlen(str); i++) {
                if (str[i] = sostituire) {
                    str[i] = 'X';
                    break;
                }
            }
            break;

        default: 
            printf("errore");
    }
}