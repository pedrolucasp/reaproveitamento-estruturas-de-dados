#include <stdio.h>
#include <string.h>

#include "fila.h"
#include "monte.h"

int main() {
	int executando = 1;
	struct fila fila_interessados;
	struct monte pets;

	inicializa_fila(&fila_interessados);
	pets.tamanho = 0;

	while (executando) {
		printf("\nMenu:\n");
		printf("1. Adicionar interessado à fila de adoção\n");
		printf("2. Adicionar pet à fila de prioridade\n");
		printf("3. Atender próximo interessado\n");
		printf("4. Exibir fila de interessados\n");
		printf("5. Exibir pets urgentes\n");
		printf("6. Sair\n");

		int opcao;
		scanf("%d", &opcao);

		switch (opcao) {
			case 1: {
					struct pessoa nova_pessoa;
					printf("Nome do interessado: ");
					scanf("%s", nova_pessoa.nome);
					nova_pessoa.id = fila_interessados.tamanho + 1; // ID automático
					if (enfileira(&fila_interessados, nova_pessoa) == 0) {
						printf("Interessado %s adicionado à fila.\n", nova_pessoa.nome);
					} else {
						printf("Erro: falha ao adicionar à fila.\n");
					}
					break;
				}
			case 2: {
					struct pet novo_pet;
					printf("Nome do pet: ");
					scanf("%s", novo_pet.nome);
					printf("Nível de urgência (1-10): ");
					scanf("%d", &novo_pet.urgencia);
					novo_pet.id = pets.tamanho + 1; // ID automático
					if (inserir_no_monte(&pets, novo_pet) == 0) {
						printf("Pet %s adicionado ao monte com urgência %d.\n",
								novo_pet.nome,
								novo_pet.urgencia);
					} else {
						printf("Erro: monte cheio.\n");
					}
					break;
				}
			case 3: {
					struct pet pet_para_adocao;
					struct pessoa pessoa_para_adocao;

					int remocao;
					int desenfileiramento;

					remocao = remover_do_monte(&pets, &pet_para_adocao);
					desenfileiramento = desenfileira(&fila_interessados, &pessoa_para_adocao);

					if (remocao == 0 && desenfileiramento == 0) {

						printf("Interessado %s adotou o pet %s com urgência %d.\n",
								pessoa_para_adocao.nome,
								pet_para_adocao.nome,
								pet_para_adocao.urgencia);
					} else {
						printf("Nenhum pet ou interessado disponível.\n");
					}
					break;
				}
			case 4: {
					exibir_fila(&fila_interessados);
					break;
				}
			case 5: {
					printf("Pets com urgência:\n");
					if (pets.tamanho == 0) {
						printf("Nenhum pet na fila de urgência.\n");
					} else {
						for (int i = 0; i < pets.tamanho; i++) {
							printf("ID: %d, Nome: %s, Urgência: %d\n",
									pets.dados[i].id,
									pets.dados[i].nome,
									pets.dados[i].urgencia);
						}
					}
					break;
				}
			case 6: {
					limpa_fila(&fila_interessados);
					executando = 0;
					break;
				}
			default:
				printf("Opção inválida.\n");
				break;
		}
	}
}
