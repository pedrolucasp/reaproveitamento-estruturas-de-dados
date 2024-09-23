#ifndef FILA_H
#define FILA_H

#include "person.h"

struct queue_node {
    struct person data;

    struct queue_node *next;
    struct queue_node *prev;
};

struct queue {
    struct queue_node *front;
    struct queue_node *back;

    int size;
};

void initialize_queue(struct queue *q);
int enqueue(struct queue *q, struct person p);
int dequeue(struct queue *q, struct person *p);
int empty_queue(struct queue *q);
void list_queue(struct queue *q);
void free_queue(struct queue *q);

#endif

