/**
* @file main.cpp
* @brief Onde fica a função principal.
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 25/04/2017
* @date --
* @sa --
*/
#include "header.h"
#include "myMatrix.h"	// para buildM(), fillM(), printM(), deleteM;
#include "myMatrix_calc.h"	// para multiplicaR(), multiplicaI();
#include "myMatrix_stream.h"	// para readM(), saveM();
#include "myMatrix_vector.h"	// para readM(), saveM();

/**
* @brief Função main
* @detail Calcula o tempo e calcula matriz. --
* @param argc Tamanho de 'argv'
* @param argv Ponteiro para um array de Char constante com --
*/
int main(int argc, char const *argv[])
{
	if(argc == 1)	// Exceção_1 (numero de argumentos insuficiente)
	{
		cerr << "Número de argumentos insuficiente."<< endl
			<< "Informe os numeros que reprensentam as dimensões das Matrizes (localizadas em 'data/input') a serem utilizadas." << endl
			<< "ex. Calcular usando matrizes de dimensões 2x2, 4x4 e 16x16:" << endl
			<< ">$ bin/main 2 16 4" << endl;
		exit(1);
	}
	//Exceção_2 (Argumento invalido)

//[!] Modificar o tipo a ser lido atraves de uma especificação por terminal
	M_vector<int> *vA = nullptr;
	M_vector<int> *vB = nullptr;
	int vSize = argc-1;
	int *vDimensions = new int[vSize];
	string dummy;

	// Criando um arranjo de inteiros contendo as dimensões passadas por terminal
	for (int i = 1; i < argc; ++i)	// pula o primeiro argumento (path do executavel)
	{
		dummy = argv[i];
		vDimensions[i] = std::stoi(dummy);

	}
	
	// Construindo vetores..
	build_vectorM(vA, vSize, vDimensions);

	//TEST
	for (int i = 0; i < vSize; ++i)
	{
		fillM(vA[i].vectorM, vA[i].dimension, i);
		cout << "M[" << i <<"]" << vA[i].dimension << "_ :" << endl;
		printM(vA[i].vectorM, vA[i].dimension, i)
		cout << endl;
	}

	delete_vectorM(vA, vSize);

	// Atribuindo valores a vetores...
	//readM()

//	C = multiplicaI(A,B,n);
//	cout << "C:" << endl;
//	printM(C,n);
	// Se C ja tiver apontando pra 'algo', deletar 'algo' antes de apontar C para um novo lugar.
//	deleteM(C,n);

	return 0;
}