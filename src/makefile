CC = gcc  
CFLAGS = -Wall -Wextra -I./src  
SRC = funciones/funciones.c main.c  
BIN = suma_x_parametros  

all: $(BIN)  

$(BIN): $(SRC)  
	$(CC) $(CFLAGS) $^ -o $@  

clean:  
	rm -f $(BIN)  

.PHONY: all clean  