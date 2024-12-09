/* Scriva un programma C che dato un array prestabilito, prenda in input da
riga di comando un numero e lo ricerchi all'interno dell'array.
La ricerca deve essere demandata ad un processo figlio e deve essere
implementata attraverso un'apposita funzione di nome ricerca. */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <ctype.h>
#include <string.h>

int cercaNumero(int numeri[], int n, int num)
{

	for (int i = 0; i < n; i++)
	{
		if (numeri[i] == num)
		{
			return i;
		}
	}

	return -1;
}

int main(int argc, char *argv[])
{

	int numeri[] = {1, 2, 3};
	int num = atoi(argv[1]);
	int pos;

	int pid = fork();

	if (pid == 0)
	{

		pos = cercaNumero(numeri, 3, num);

		if (pos > -1)
			printf("\nil numero %d è nella posizione %d dell'array\n", num, pos);
		else
			printf("\nIl numero %d non è presente nell'array\n", num);

		exit(1);

	}

    else
    {

        wait(&pid);

    }

    printf("\nProgramma terminato\n");

	return 0;
}