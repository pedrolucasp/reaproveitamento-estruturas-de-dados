#include <stdlib.h>
#include "stack.h"

void inicializa_pilha(struct pilha *p) {
	p->topo = NULL;
}

int empilha(struct pilha *p, int dado) {
	struct nodo *item = (struct nodo *) malloc(sizeof(struct nodo));

	if (!item) {
		return -1;
	}

	item->dado = dado;
	item->ant = NULL;
	item->prox = p->topo;

	if (p->topo) {
		p->topo->ant = item;
	}

	p->topo = item;

	return 0;
}

int desempilha(struct pilha *pilha, int *saida) {
	struct nodo *item;

	if (!pilha->topo) {
		return -1;
	}

	item = pilha->topo;

	*saida = item->dado;
	pilha->topo = pilha->topo->prox;

	if (pilha->topo) {
		pilha->topo->ant = NULL;
	}

	free(item);

	return 0;
}

int pilha_vazia(struct pilha *p) {
	return p->topo == NULL;
}

void limpa_pilha(struct pilha *p) {
	struct nodo *atual = p->topo;
	struct nodo *proximo;

	while (atual != NULL) {
		proximo = atual->prox;
		free(atual);
		atual = proximo;
	}

	p->topo = NULL;
}
