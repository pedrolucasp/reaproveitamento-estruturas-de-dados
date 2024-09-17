CC = cc
CFLAGS = -Iincludes -Wall -Wextra -std=c89 -pedantic
SRC_DIR = src
BIN_DIR = bin

all: $(BIN_DIR)/pilha $(BIN_DIR)/fila

$(BIN_DIR)/pilha: $(SRC_DIR)/pilha_teste.c $(SRC_DIR)/pilha.c includes/pilha.h
	$(CC) $(CFLAGS) -o $@ $(SRC_DIR)/pilha_teste.c $(SRC_DIR)/pilha.c

$(BIN_DIR)/fila: $(SRC_DIR)/fila_teste.c $(SRC_DIR)/fila.c includes/fila.h
	$(CC) $(CFLAGS) -o $@ $(SRC_DIR)/fila_teste.c $(SRC_DIR)/fila.c

clean:
	rm -rf $(BIN_DIR)/*

.PHONY: all clean
