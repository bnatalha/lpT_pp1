##by @bnatalha.

# -ansi: "In C++ mode, it is equivalent to `-std=c++98'."
# https://gcc.gnu.org/onlinedocs/gcc-4.3.2/gcc/C-Dialect-Options.html#C-Dialect-Options

#CPPFLAGS += -Wall -std=c++11 -pedantic
CPPFLAGS += -Wall -std=c++11 -pedantic -O0 -g
INC =-I include

.PHONY: all init val clean test

#compilar tudo.
all: init bin/main clean

#compila test
test: init bin/counting clean

#roda test
vai: bin/counting
	bin/counting

#verifica se existe as pasta 'bin' no diretorio atual e, caso não exita, a cria.
#mesmo para a pasta 'output' em data/.
init:
	mkdir -p bin;\
	mkdir -p data/output

#verifica se existe as pasta docs/ no diretorio atual e, caso não exita, a cria;
#gera a documentação na pasta docs.
doc: Doxyfile
	mkdir -p docs ;\
	doxygen	

#checar vazamento de memoria.
val:
	valgrind --leak-check=yes bin/main 4

#gerar executaveis.
bin/main: bin/main.o
	g++ $^ -o $@

bin/counting: bin/counting.o
	g++ $^ -o $@

#gerar objetos.
bin/main.o: src/main.cpp
	g++ $(CPPFLAGS) $< $(INC) -c -o $@

bin/counting.o: test/counting.cpp
	g++ $(CPPFLAGS) $< $(INC) -c -o $@

#remover .o's.
clean:
	$(RM) bin/*.o