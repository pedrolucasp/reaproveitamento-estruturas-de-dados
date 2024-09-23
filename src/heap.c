#include "heap.h"

void subir_no_monte(struct monte *m, int indice) {
	while (indice > 0) {
		int indice_pai = (indice - 1) / 2;

		if (m->dados[indice_pai].urgencia < m->dados[indice].urgencia) {
			struct pet temp;
			temp = m->dados[indice_pai];

			m->dados[indice_pai] = m->dados[indice];
			m->dados[indice] = temp;
			indice = indice_pai;
		} else {
			break;
		}
	}
}

void organizar_monte(struct monte *m, int indice) {
	int filho_esquerdo, filho_direito, maior;

	while (1) {
		filho_esquerdo = 2 * indice + 1;
		filho_direito = 2 * indice + 2;
		maior = indice;

		if (filho_esquerdo < m->tamanho &&
				m->dados[filho_esquerdo].urgencia >
				m->dados[maior].urgencia) {
			maior = filho_esquerdo;
		}

		if (filho_direito < m->tamanho &&
				m->dados[filho_direito].urgencia >
				m->dados[maior].urgencia) {
			maior = filho_direito;
		}

		if (maior != indice) {
			struct pet temp;
			temp = m->dados[indice];

			m->dados[indice] = m->dados[maior];
			m->dados[maior] = temp;
			indice = maior;
		} else {
			break;
		}
	}
}

int inserir_no_monte(struct monte *m, struct pet novo_pet) {
	if (m->tamanho == MONTE_MAX) {
		return -1;
	}

	m->dados[m->tamanho] = novo_pet;

	subir_no_monte(m, m->tamanho);

	m->tamanho++;

	return 0;
}

int remover_do_monte(struct monte *m, struct pet *resultado) {
	if (m->tamanho == 0) {
		return -1;
	}

	*resultado = m->dados[0];
	m->dados[0] = m->dados[m->tamanho - 1];
	m->tamanho--;

	organizar_monte(m, 0);

	return 0;
}
