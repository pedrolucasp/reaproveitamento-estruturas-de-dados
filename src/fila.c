#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "pessoa.h"

void inicializa_fila(struct fila* f) {
	f->frente = NULL;
	f->atras = NULL;
}

int enfileira(struct fila *f, struct pessoa p) {
	struct nodo_fila *item = (struct nodo_fila*) malloc(sizeof(struct nodo_fila));

	if (!item) {
		return -1;
	}

	item->dado = p;
	item->prox = NULL;
	item->ant = f->atras;

	if (f->atras == NULL) {
		f->frente = item;
	} else {
		f->atras->prox = item;

	}

	f->atras = item;
	f->tamanho++;

	return 0;
}

int desenfileira(struct fila *f, struct pessoa *p) {
	struct nodo_fila *nodo_removido;

	if (f->frente == NULL) {
		return -1;
	}

	nodo_removido= f->frente;
	*p = nodo_removido->dado;

	f->frente = f->frente->prox;

	if (f->frente == NULL) {
		f->atras = NULL;
	}

	free(nodo_removido);
	f->tamanho--;

	return 0;
}

int fila_vazia(struct fila *f) {
	return f->tamanho == 0;
}

void exibir_fila(struct fila *f) {
	struct nodo_fila *atual = f->frente;
	printf("Fila de interessados:\n");
	if (f->tamanho == 0) {
		printf("Nenhum interessado na fila.\n");
		return;
	}

	while (atual != NULL) {
		printf("ID: %d, Nome: %s\n", atual->dado.id, atual->dado.nome);
		atual = atual->prox;
	}
}

void limpa_fila(struct fila *f) {
	struct pessoa p;

	while (!fila_vazia(f)) {
		desenfileira(f, &p);
	}

}
