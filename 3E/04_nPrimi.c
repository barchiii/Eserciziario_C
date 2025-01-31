#include <stdio.h>

int main()
{
    int N, somma = 0, num = 2, cont = 0, primo = 0;

    // Input del numero N
    do
    {
        printf("Inserisci un numero intero positivo N: \n");
        scanf("%d", &N);

        if (N <= 0)
            printf("Il numero deve essere positivo. Reinserisci\n");
        
    } while (N <= 0);

    // Calcolo della somma dei primi numeri primi alternati fino a N
    while (num <= N)
    {
        primo = 1; // Assume che il num sia primo

        // Verifica se numero_corrente e' divisibile per un numero tra 2 e num-1
        for (int i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                primo = 0; // Se e' divisibile, non e' primo
                break;
            }
        }

        if (primo==1)
        {
            cont++;
            if (cont % 2 == 1)
            {
                printf("Numero primo alternato: %d\n", num);
                somma += num;
            }
        }

        num++;
    }

    // Stampo la somma
    printf("La somma dei primi numeri primi alternati fino a %d e': %d\n", N, somma);

    return 0;
}
