#ifndef FILA_H
#define FILA_H

struct nodo_fila {
    int valor;

    struct nodo_fila* prox;
};

struct fila {
    struct nodo_fila* frente;
    struct nodo_fila* atras;
};

void inicializa_fila(struct fila *f);
int enfileira(struct fila *f, int valor);
int desenfileira(struct fila *f, int *valor);
int fila_vazia(struct fila *f);
void limpa_fila(struct fila *f);

#endif

