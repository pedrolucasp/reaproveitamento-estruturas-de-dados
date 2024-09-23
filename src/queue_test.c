#include <stdio.h>
#include "queue.h"

int main() {
	struct fila fila;
	int valor;

	inicializa_fila(&fila);

	printf("Enfileirando o valor 10\n");
	enfileira(&fila, 10);

	printf("Enfileirando o valor 90\n");
	enfileira(&fila, 90);

	printf("Enfileirando o valor 41\n");
	enfileira(&fila, 41);

	while (!fila_vazia(&fila)) {
		desenfileira(&fila, &valor);
		printf("Pegou o valor: %d\n", valor);
	}

	limpa_fila(&fila);

	return 0;
}
