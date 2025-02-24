/* Scrivi il codice sorgente di un prg in cui
   il processo padre P genera due figli: F1 e  F2.

   A F1 assegna un tempo t di sleep(t) (ritardo) 2 secondi;
   F1 deve restituire al padre P il numero 2.
   A F2 assegna un tempo t di sleep(t) (ritardo) 4 secondi;
   F2 deve restituire al padre P il numero 4.

   Padre P deve attendere la terminazione del figlio che dorme di più, ossia F2, e
   deve scrivere quanti secondi ha dormito tale figlio.

   La prima cosa che ciascun processo deve fare, appena genera un processo figlio,
   è dichiararsi nel modo seguente:
   "P: mio PID=..., mio figlio F1 ha PID=...
   La prima cosa che ciascun processo figlio deve fare appena è stato generato,
   è dichiararsi nel modo seguente:
   "F1: mio PID=..., mio padre P ha PID=..."

   Ogni volta che un processo visualizza qualcosa sullo schermo deve dichiararsi nel modo seguente:
   "P: quello che P deve visualizzare"
   "..." */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void processF1() {
    // F1: dichiarazione
    printf("F1: mio PID=%d, mio padre P ha PID=%d\n", getpid(), getppid());
    sleep(2); // F1 dorme per 2 secondi
    printf("F1: restituisco il numero 2\n");
    exit(2); // F1 restituisce il numero 2
}

void processF2() {
    // F2: dichiarazione
    printf("F2: mio PID=%d, mio padre P ha PID=%d\n", getpid(), getppid());
    sleep(4); // F2 dorme per 4 secondi
    printf("F2: restituisco il numero 4\n");
    exit(4); // F2 restituisce il numero 4
}

int main(int argc, char* argv[]) {
    pid_t pidF1, pidF2;
    int statusF1, statusF2;

    // P: dichiarazione iniziale
    printf("P: mio PID=%d\n", getpid());

    // Creazione del primo figlio F1
    pidF1 = fork();
    if (pidF1 == 0) {
        // Questo codice viene eseguito dal figlio F1
        processF1();
    } else if (pidF1 < 0) {
        perror("Errore nella creazione di F1");
        exit(1);
    }

    // Creazione del secondo figlio F2
    pidF2 = fork();
    if (pidF2 == 0) {
        // Questo codice viene eseguito dal figlio F2
        processF2();
    } else if (pidF2 < 0) {
        perror("Errore nella creazione di F2");
        exit(1);
    }

    // P: attende la terminazione dei figli
    pid_t pid_terminato = waitpid(pidF2, &statusF2, 0); // Attende il figlio che dorme di più (F2)
    if (pid_terminato == pidF2) {
        printf("P: F2 ha dormito per 4 secondi\n");
    }

    // P: attende la terminazione dell'altro figlio (F1)
    waitpid(pidF1, &statusF1, 0);

    return 0;
}
