#include "heap.h"

void climb_heap(struct heap *h, int index) {
	while (index > 0) {
		int parent_index = (index - 1) / 2;

		if (h->data[parent_index].urgency < h->data[index].urgency) {
			struct pet temp;
			temp = h->data[parent_index];

			h->data[parent_index] = h->data[index];
			h->data[index] = temp;
			index = parent_index;
		} else {
			break;
		}
	}
}

void heapify(struct heap *h, int index) {
	int left_child, right_child, biggest;

	while (1) {
		left_child = 2 * index + 1;
		right_child = 2 * index + 2;
		biggest = index;

		if (left_child < h->size &&
				h->data[left_child].urgency >
				h->data[biggest].urgency) {
			biggest = left_child;
		}

		if (right_child < h->size &&
				h->data[right_child].urgency >
				h->data[biggest].urgency) {
			biggest = right_child;
		}

		if (biggest != index) {
			struct pet temp;
			temp = h->data[index];

			h->data[index] = h->data[biggest];
			h->data[biggest] = temp;
			index = biggest;
		} else {
			break;
		}
	}
}

int add_to_heap(struct heap *h, struct pet new_pet) {
	if (h->size == HEAP_MAX) {
		return -1;
	}

	h->data[h->size] = new_pet;

	climb_heap(h, h->size);

	h->size++;

	return 0;
}

int remove_from_heap(struct heap *h, struct pet *result) {
	if (h->size == 0) {
		return -1;
	}

	*result = h->data[0];
	h->data[0] = h->data[h->size - 1];
	h->size--;

	heapify(h, 0);

	return 0;
}
