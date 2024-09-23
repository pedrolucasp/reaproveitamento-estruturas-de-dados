#include <stdio.h>
#include <string.h>

#include "queue.h"
#include "heap.h"

int main() {
	int running = 1;
	struct queue peoples_queue;
	struct heap pets;

	initialize_queue(&peoples_queue);
	pets.size = 0;

	while (running) {
		printf("\nMenu:\n");
		printf("1. Adicionar interessado à fila de adoção\n");
		printf("2. Adicionar pet à fila de prioridade\n");
		printf("3. Atender próximo interessado\n");
		printf("4. Exibir fila de interessados\n");
		printf("5. Exibir pets urgentes\n");
		printf("6. Sair\n");

		int option;
		scanf("%d", &option);

		switch (option) {
			case 1: {
					struct person new_person;
					printf("Nome do interessado: ");
					fflush(stdout);
					scanf("%s", new_person.name);
					new_person.id = peoples_queue.size + 1;
					if (enqueue(&peoples_queue, new_person) == 0) {
						printf("Interessado %s adicionado à fila.\n", new_person.name);
					} else {
						printf("Erro: falha ao adicionar à fila.\n");
					}
					break;
				}
			case 2: {
					struct pet new_pet;
					printf("Nome do pet: ");
					fflush(stdout);
					scanf("%s", new_pet.name);

					printf("Nível de urgência (1-10): ");
					fflush(stdout);
					scanf("%d", &new_pet.urgency);

					new_pet.id = pets.size + 1;
					if (add_to_heap(&pets, new_pet) == 0) {
						printf("Pet %s adicionado ao monte com urgência %d.\n",
								new_pet.name,
								new_pet.urgency);
					} else {
						printf("Erro: monte cheio.\n");
					}
					break;
				}
			case 3: {
					struct pet adopted;
					struct person adopter;

					int removal_status;
					int dequeue_status;

					if (pets.size == 0 || peoples_queue.size == 0) {
						printf("Fila de interessados ou pets insuficientes");
						break;
					}

					removal_status = remove_from_heap(&pets, &adopted);
					dequeue_status = dequeue(&peoples_queue, &adopter);

					if (removal_status == 0 && dequeue_status == 0) {

						printf("Interessado %s adotou o pet %s com urgência %d.\n",
								adopter.name,
								adopted.name,
								adopted.urgency);
					} else {
						printf("Nenhum pet ou interessado disponível.\n");
					}
					break;
				}
			case 4: {
					list_queue(&peoples_queue);
					break;
				}
			case 5: {
					printf("Pets com urgência:\n");
					if (pets.size == 0) {
						printf("Nenhum pet na fila de urgência.\n");
					} else {
						for (int i = 0; i < pets.size; i++) {
							printf("ID: %d, Nome: %s, Urgência: %d\n",
									pets.data[i].id,
									pets.data[i].name,
									pets.data[i].urgency);
						}
					}
					break;
				}
			case 6: {
					free_queue(&peoples_queue);
					running = 0;
					break;
				}
			default:
				printf("Opção inválida.\n");
				break;
		}
	}
}
