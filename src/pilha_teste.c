#include <stdio.h>
#include "pilha.h"

int main() {
	struct pilha pilha;
	int valor;

	inicializa_pilha(&pilha);

	printf("Empilhando o valor 1\n");
	empilha(&pilha, 1);

	printf("Empilhando o valor 5\n");
	empilha(&pilha, 5);

	printf("Empilhando o valor 10\n");
	empilha(&pilha, 10);

	while (!pilha_vazia(&pilha)) {
		desempilha(&pilha, &valor);
		printf("Pegou o valor: %d\n", valor);
	}

	limpa_pilha(&pilha);

	return 0;
}
