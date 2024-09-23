#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "person.h"

void initialize_queue(struct queue* q) {
	q->front = NULL;
	q->back = NULL;
}

int enqueue(struct queue *q, struct person p) {
	struct queue_node *item = (struct queue_node*) malloc(sizeof(struct queue_node));

	if (!item) {
		return -1;
	}

	item->data = p;
	item->next = NULL;
	item->prev = q->back;

	if (q->back == NULL) {
		q->front = item;
	} else {
		q->back->next = item;

	}

	q->back = item;
	q->size++;

	return 0;
}

int dequeue(struct queue *q, struct person *p) {
	struct queue_node *node_removed;

	if (q->front == NULL) {
		return -1;
	}

	node_removed = q->front;
	*p = node_removed->data;

	q->front = q->front->next;

	if (q->front == NULL) {
		q->back = NULL;
	}

	free(node_removed);
	q->size--;

	return 0;
}

int empty_queue(struct queue *q) {
	return q->size == 0;
}

void list_queue(struct queue *q) {
	struct queue_node *current = q->front;

	printf("Fila de interessados:\n");

	if (q->size == 0) {
		printf("Nenhum interessado na fila.\n");
		return;
	}

	while (current != NULL) {
		printf(
			"ID: %d, Nome: %s\n",
			current->data.id, current->data.name
		);

		current = current->next;
	}
}

void free_queue(struct queue *q) {
	struct person p;

	while (!empty_queue(q)) {
		dequeue(q, &p);
	}
}
