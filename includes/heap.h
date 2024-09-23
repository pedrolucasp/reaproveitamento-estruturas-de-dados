#ifndef MONTE_H
#define MONTE_H

#include "pet.h"

#define MONTE_MAX 52

struct monte {
	struct pet dados[MONTE_MAX];
	int tamanho;
};


void subir_no_monte(struct monte *m, int indice);
void descer_no_monte(struct monte *m, int indice);
int inserir_no_monte(struct monte *m, struct pet novo_pet);
int remover_do_monte(struct monte *m, struct pet *resultado);

#endif
