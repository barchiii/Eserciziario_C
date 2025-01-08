#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{

    int dim = 3;
    int array[dim];
    int j = 1;

    for (int i = 0; i < dim; i++)
    {
        array[i] = j;
        j++;
    }

    int p2, p3;

    printf("P1: mio PID = %d, mio figlio P2 ha PID = %d\n", getpid(), p2);

    p2 = fork();

    if (p2 < 0)
    {
        printf("Errore nella generazione del processo figlio di P2");
    }

    else if (p2 == 0)
    {
        // processo figlio che genera p4 (prodotto)
        printf("P2: mio PID = %d, mio padre P1 ha PID = %d\n", getpid(), getppid());

        int p4 = fork();
        if (p4 == 0)
        {
            printf("P4: mio PID=%d, mio padre P2 ha PID=%d\n", getpid(), getppid());

            int prodotto = 0;

            for (int i = 0; i < dim; i++)
            {
                prodotto += array[i] * array[i + 1];
            }

            printf("P4: Prodotto delle componenti dell'array: %d\n", prodotto);
        }

        exit(0);
    }

    else
    {
        wait(&p2);
    }

    p3 = fork();

    if (p3 < 0)
    {
        printf("Errore nella generazione del processo figlio di P3");
    }

    else if (p3 == 0)
    {
        printf("P3: mio PID = %d, mio padre P1 ha PID = %d\n", getpid(), getppid());

        int p5 = fork();

        if (p5 == 0)
        {

            printf("P5: mio PID = %d, mio padre P3 ha PID = %d\n", getpid(), getppid());
            int somma = 0;

            for (int i = 0; i < dim; i++)
            {
                somma += array[i];
            }

            double media = somma / dim;

            printf("P5: Media delle componenti dell'array: %.2f\n", media);
        }

        exit(0);
    }

    else
    {
        wait(&p3);
    }

    return 0;
}