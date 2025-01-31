#include <stdio.h>
#include <string.h>

int main()
{

    char stringa[15];
    int lungh, i, ris;
    char stringa2[20];
    char stringa3[20];

    printf("Inserisci una stringa:\n");
    scanf("%s", stringa);

    printf("\n");
    printf("Hai inserito la seguente stringa: %s\n", stringa);
    printf("La quinta lettera della stringa e' la seguente: %c\n", stringa[4]);
    printf("La seconda lettera della stringa e' la seguente: %c\n", stringa[1]);
    // stringa[6]='\0';
    // printf("I primi 6 caratteri sono %s",stringa);

    printf("Funzioni principali: \n");
    printf("Lunghezza (strlen)\n");

    lungh = strlen(stringa);
    printf("La lunghezza della stringa inserita e': %d\n", lungh);
    printf("Inserisci una seconda stringa:\n");
    scanf("%s", stringa2);
    strcpy(stringa, stringa2);

    /*for(i=0;i<strlen(stringa2);i++){
    stringa[i]=stringa2[i];
    dive = 1;
    break;
    }*/
    printf("La stringa di destinazione: %s\n", stringa);

    printf("Inserisci una terza stringa:\n");
    scanf("%s", stringa3);
    ris = strcmp(stringa, stringa3);

    if (ris == 0)
        printf("Le stringhe sono uguali\n");

    else if (ris < 0)
        printf("La prima stinga è prima in ordine lessico grafico");

    else
        printf("La seconda stringa viene prima in ordine lessico grafico");

    strcat(stringa, stringa3);
    printf("La stringa concatenata e': %s\n", stringa);

    return 0;
}