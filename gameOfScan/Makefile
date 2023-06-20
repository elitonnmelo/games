TARGET = solver

# Compilador que será utilizado
CC = g++

# Opções de compilação
CFLAGS = -std=c++17 -Wall -Wextra -Werror

# Bibliotecas a serem vinculadas
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Arquivo fonte do seu programa
SOURCE = solver.cpp

# Regra para limpar o arquivo executável
all: main

# Regra para a compilação do programa
main: $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) $(LIBS) -o $(TARGET)

# Regra para limpar o arquivo
clean:
	rm -f *.o

# Regra para rodar o programa
run: solver
	./solver
