#include <stdio.h>

int main() 
{
    int n, i, v[10];

    do {
        printf("Quanti elementi vuoi inserire?\n");
        scanf("%d", &n);
    } while (n <= 0 || n > 10);

    for (i = 0; i < n; i++) {
        printf("Inserisci un numero di posione %d ", (i + 1));
        scanf("%d", &v[i]);
    }

    printf("Il vettore inserito è il seguente: \n");
    for (i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }

    return 0;
}