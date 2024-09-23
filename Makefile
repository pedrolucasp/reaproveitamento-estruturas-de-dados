CC = cc
CFLAGS = -Iincludes -Wall -Wextra -std=c99 -pedantic
SRC_DIR = src
BIN_DIR = bin

all: $(BIN_DIR)/adoption

$(BIN_DIR)/adoption: $(SRC_DIR)/adoption.c $(SRC_DIR)/queue.c $(SRC_DIR)/heap.c includes/queue.h includes/heap.h includes/person.h includes/pet.h
	$(CC) $(CFLAGS) -o $@ $(SRC_DIR)/adoption.c $(SRC_DIR)/queue.c $(SRC_DIR)/heap.c

$(BIN_DIR)/stack: $(SRC_DIR)/stack_test.c $(SRC_DIR)/stack.c includes/stack.h
	$(CC) $(CFLAGS) -o $@ $(SRC_DIR)/stack_test.c $(SRC_DIR)/stack.c

$(BIN_DIR)/queue: $(SRC_DIR)/queue_test.c $(SRC_DIR)/queue.c includes/queue.h
	$(CC) $(CFLAGS) -o $@ $(SRC_DIR)/queue_test.c $(SRC_DIR)/queue.c

clean:
	rm -rf $(BIN_DIR)/*

.PHONY: all clean
