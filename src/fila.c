#include <stdlib.h>
#include "fila.h"

void inicializa_fila(struct fila* f) {
	f->frente = NULL;
	f->atras = NULL;
}

int enfileira(struct fila *f, int valor) {
	struct nodo_fila *item = (struct nodo_fila*) malloc(sizeof(struct nodo_fila));

	if (!item) {
		return -1;
	}

	item->valor = valor;
	item->prox = NULL;

	if (f->atras != NULL) {
		f->atras->prox = item;
	}

	f->atras = item;

	if (f->frente == NULL) {
		f->frente = item;
	}

	return 0;
}

int desenfileira(struct fila *f, int *valor) {
	struct nodo_fila *temp;

	if (f->frente == NULL) {
		return -1;
	}

	temp = f->frente;
	*valor = temp->valor;
	f->frente = f->frente->prox;

	if (f->frente == NULL) {
		f->atras = NULL;
	}

	free(temp);

	return 0;
}

int fila_vazia(struct fila *f) {
	return f->frente == NULL;
}

void limpa_fila(struct fila *f) {
	struct nodo_fila *atual = f->frente;

	while (atual != NULL) {
		struct nodo_fila *temp = atual;
		atual = atual->prox;

		free(temp);
	}

	f->frente = NULL;
	f->atras = NULL;
}
