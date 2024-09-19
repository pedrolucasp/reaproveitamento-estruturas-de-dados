#ifndef FILA_H
#define FILA_H

#include "pessoa.h"

struct nodo_fila {
    struct pessoa dado;

    struct nodo_fila *prox;
    struct nodo_fila *ant;
};

struct fila {
    struct nodo_fila *frente;
    struct nodo_fila *atras;

    int tamanho;
};

void inicializa_fila(struct fila *f);
int enfileira(struct fila *f, struct pessoa p);
int desenfileira(struct fila *f, struct pessoa *p);
int fila_vazia(struct fila *f);
void exibir_fila(struct fila *f);
void limpa_fila(struct fila *f);

#endif

