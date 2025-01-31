/* 1) Dopo aver caricato in memoria 
    2 vettori di uguale dimensione composti da numeri interi
    scrivere in output un terzo vettore 
    dato dalla somma delle componenti fatta a una a una (Vettore
    somma). */
#include <stdio.h>

int main ()
{
    int n, i;
    int v1[10], v2[10], vSomma[10]={0};

    printf("Quanti numeri vuoi inserire?\n");
    scanf("%d", &n);

    printf("Riempi il primo vettore: \n");
    for (i = 0; i < n; i++) {
        printf("Inserisci il numero in posizione %d: ", (i + 1));
        scanf("%d", &v1[i]);
    }

    printf("\nRiempi il secondo vettore: \n");
    for (i = 0; i < n; i++) {
        printf("Inserisci il numero in posizione %d: ", (i + 1));
        scanf("%d", &v2[i]);
    }

    for (i = 0; i < n; i++) {
        vSomma[i] = v1[i] + v2[i];
    }
    
    printf("Il vettore somma e':\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", vSomma[i]); 
    }
}