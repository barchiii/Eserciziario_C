/* Scrivi il codice sorgente di un programma che
   permette al processo padre di generare un processo figlio:
   - sia padre che figlio visualizzano il proprio PID e il PID del proprio parente
   - padre conta da 0 a 19 (visualizza i numeri da 0 a 19)
   - padre conta da 0 a 9 (visualizza i numeri da 0 a 9)
   Manda in esecuzione più volte e descrivi il comportamento del programma */

#include <stdio.h>
#include <unistd.h>

int main() {
    // Creazione del processo figlio con la funzione fork
    pid = fork();

    if (pid < 0) {
        // Errore nella generazione del processo
        printf("Errore nella generazione del processo\n");
        exit(1);
    } 
    
    else if (pid == 0) {
        // generazione processo figlio
        printf("PID figlio: %d\nPID padre: %d\n", getpid(), getppid());
        
        // Il padre conta da 0 a 9
        for (int i = 0; i < 10; i++) {
            printf("Padre conta da 0 a 9: %d\n", i);
        }
        exit(0)
    } 
    
    else {
        // PID del processo padre e figlio
        printf("PID padre: %d\nPID figlio: \n", getpid(), pid);
        
        // Il padre conta da 0 a 19
        for (int i = 0; i < 20; i++) {
            printf("Padre conta da 0 a 19: %d\n", i);
        }
    }

    return 0;
}
