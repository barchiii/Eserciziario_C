/* Scrivi il codice sorgente di un prg in cui
   il processo padre P genera due processi figli: F1 e F2.
   F1 somma 1+2;
   F2 somma 3+4.
   Entrambi restituiscono al processo padre P il risultato ottenuto dall'operazione compiuta.
   Padre P somma tra loro i risultati che i due figli gli hanno restituito e
   visalizza il valore di tale somma.

   La prima cosa che ciascun processo deve fare, appena genera un processo figlio,
   Ã¨ dichiararsi nel modo seguente:
   "P: mio PID=..., mio figlio F1 ha PID=...
   La prima cosa che ciascun processo figlio deve fare appena Ã¨ stato generato,
   Ã¨ dichiararsi nel modo seguente:
   "F1: mio PID=..., mio padre P ha PID=..."

   Ogni volta che un processo visualizza qualcosa sullo schermo deve dichiararsi nel modo seguente:
   "P: quello che P deve visualizzare" */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pidF1, pidF2;
    int statusF1, statusF2;

    pidF1 = fork();
    if (pidF1 < 0) {
        perror("fork");
        exit(1);
    } else if (pidF1 == 0) {
        // F1 process
        printf("F1: mio PID=%d, mio padre P ha PID=%d\n", getpid(), getppid());
        int resultF1 = 1 + 2;
        exit(resultF1);
    } else {
        // P process
        printf("P: mio PID=%d, mio figlio F1 ha PID=%d\n", getpid(), pidF1);

        pidF2 = fork();
        if (pidF2 < 0) {
            perror("fork");
            exit(1);
        } else if (pidF2 == 0) {
            // F2 process
            printf("F2: mio PID=%d, mio padre P ha PID=%d\n", getpid(), getppid());
            int resultF2 = 3 + 4;
            exit(resultF2);
        } else {
            // P process
            printf("P: mio PID=%d, mio figlio F2 ha PID=%d\n", getpid(), pidF2);

            // Wait for F1
            waitpid(pidF1, &statusF1, 0);
            int resultF1 = WEXITSTATUS(statusF1);
            printf("P: risultato di F1=%d\n", resultF1);

            // Wait for F2
            waitpid(pidF2, &statusF2, 0);
            int resultF2 = WEXITSTATUS(statusF2);
            printf("P: risultato di F2=%d\n", resultF2);

            // Sum results
            int total = resultF1 + resultF2;
            printf("P: somma totale=%d\n", total);
        }
    }

    return 0;
}
