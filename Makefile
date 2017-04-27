##by @bnatalha.

CPPFLAGS += -Wall -std=c++11 -ansi -pedantic -O0 -g
INC =-I include

.PHONY: all init val clean

#compilar tudo.
all: init bin/main clean

#verifica se existe as pasta bin no diretorio atual e, caso não exita, a cria.
init:
	mkdir -p bin

#verifica se existe as pasta docs/ no diretorio atual e, caso não exita, a cria;
#gera a documentação na pasta docs.
doc: Doxyfile
	mkdir -p docs ;\
	doxygen	

#checar vazamento de memoria.
val:
	valgrind --leak-check=yes bin/main

#gerar executaveis.
bin/main: bin/main.o bin/myMatrix.o
	g++ $^ -o $@

#gerar objetos.
bin/main.o: src/main.cpp
	g++ $(CPPFLAGS) $< $(INC) -c -o $@

bin/myMatrix.o: src/myMatrix.cpp
	g++ $(CPPFLAGS) $< $(INC) -c -o $@

#bin/myMatrix_fun.o: src/myMatrix_fun.cpp
#	g++ $(CPPFLAGS) $< $(INC) -c -o $@

#remover .o's.
clean:
	$(RM) bin/*.o