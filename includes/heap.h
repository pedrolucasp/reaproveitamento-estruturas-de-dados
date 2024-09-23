#ifndef HEAP_H
#define HEAP_H

#include "pet.h"

#define HEAP_MAX 52

struct heap {
	struct pet data[HEAP_MAX];
	int size;
};


void climb_heap(struct heap *h, int index);
void heapify(struct heap *h, int index);
int add_to_heap(struct heap *h, struct pet new_pet);
int remove_from_heap(struct heap *h, struct pet *result);

#endif
