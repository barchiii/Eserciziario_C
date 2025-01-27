#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{

    int n;

    do
    {
        printf("P1: Inserisci un numero tra 0 e 10: ");
        scanf("%d", &n);
    } while (n < 0 || n > 10);

    int p2 = fork();
    if (p2 != 0)
    {
        printf("P1: mio PID=%d, mio figlio P2 ha PID=%d\n", getpid(), p2);
    }

    if (p2 == 0)
    {
        printf("P2: mio PID=%d, mio padre P1 ha PID=%d\n", getpid(), getppid());

        int p4 = fork();
        if (p4 != 0)
        {
            printf("P2: mio PID=%d, mio figlio P4 ha PID=%d\n", getpid(), p4);
        }
        if (p4 == 0)
        {
            printf("P4: mio PID=%d, mio padre P2 ha PID=%d\n", getpid(), getppid());

            for (int i = n; i >= 0; i--)
            {
                printf("P4: %d \n", i);
                sleep(1);
            }

            exit(0);
        }

        wait(0);
        int p5 = fork();
        if (p5 != 0)
        {
            printf("P2: mio PID=%d, mio figlio P5 ha PID=%d\n", getpid(), p5);
        }
        if (p5 == 0)
        {
            printf("P5: mio PID=%d, mio padre P2 ha PID=%d\n", getpid(), getppid());

            for (int i = 0; i <= n; i++)
            {
                printf("P5: %d \n", i);
                sleep(1);
            }

            exit(0);
        }
        wait(0);
        wait(0);
        exit(0);
    }

    int p3 = fork();
    if (p3 != 0)
    {
        printf("P1: mio PID=%d, mio figlio P3 ha PID=%d\n", getpid(), p3);
    }
    if (p3 == 0)
    {

        printf("P3: mio PID=%d, mio padre P1 ha PID=%d\n", getpid(), getppid());
        printf("P3: numero da elevare al quadrato:  %d \n", n);
        int p6 = fork();
        if (p6 != 0)
        {
            printf("P3: mio PID=%d, mio figlio P6 ha PID=%d\n", getpid(), p6);
        }
        if (p6 == 0)
        {
            printf("P6: mio PID=%d, mio padre P3 ha PID=%d\n", getpid(), getppid());
            int quadrato = n * n;
            printf("P6: %d\n", quadrato);
            exit(0);
        }

        wait(0);
        exit(0);
    }

    wait(0);
    wait(0);
    exit(0);
    exit(0);

    return 0;
}
