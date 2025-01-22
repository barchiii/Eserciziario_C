#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char* argv[]){
    int n;
    do{
        printf("P1: Inserisci un numero tra 0 e 10\n");
        scanf("%d", &n);
    }while(n<0 || n>10);

    pid_t p2 = fork();
    printf("P1: mio PID=%d, mio figlio P2 ha PID=%d\n", getpid(), -1);

    if(p2==0){
        printf("P2: mio PID: %d, mio padre P1 ha PID:%d\n", getpid(), getppid());
        
        pid_t p4 = fork();
        if(p4==0){
            printf("P4: mio PID: %d, mio padre P2 ha PID:%d\n", getpid(), getppid());
            for(int i=0; i>=0; i--){
                printf("Figlio P4: %d\n", i);
                sleep (1);
            }
            exit(0);
        }

        pid_t p5 = fork();
        if(p5==0){
            printf("P5: mio PID: %d, mio padre P2 ha PID:%d\n", getpid(), getppid());
            for(int i=0; i<= n; i++){
                printf("Figlio P5: %d\n", i);
                sleep (1);
            }
            exit(0);
        }

        wait(NULL);
        wait(NULL);

        exit(0);
    }else{
        pid_t p3 = fork();

        if(p3==0){
            printf("P3: mio PID: %d, mio padre P1 ha PID:%d\n", getpid(), getppid());
            printf("P3: numero = %d\n", n);

            pid_t p6 = fork();
            if(p6==0){
                printf("P6: mio PID: %d, mio padre P3 ha PID:%d\n", getpid(), getppid());
                exit(0);
            }
        }
        wait(NULL);
    }
}