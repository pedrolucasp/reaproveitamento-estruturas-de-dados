#ifndef PILHA_H
#define PILHA_H

struct nodo {
	int dado;

	struct nodo *ant;
	struct nodo *prox;
};

struct pilha {
	struct nodo *topo;
};

void inicializa_pilha(struct pilha *p);
int empilha(struct pilha *p, int dado);
int desempilha(struct pilha *p, int *saida);
int pilha_vazia(struct pilha *p);
void limpa_pilha(struct pilha *p);

#endif
