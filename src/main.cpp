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
//#include "myMatrix_fun.h"	// para multiplicaR(), multiplicaI();

/**
* @brief Função main
* @detail Calcula o tempo e calcula matriz. --
* @param argc Tamanho de 'argv'
* @param argv Ponteiro para um array de Char constante com --
*/
int main(int argc, char const *argv[])
{
	
	int **A = NULL;
	int **B = NULL;
	int n = 4;
	int soma = 0;

	buildM(A,n);
	buildM(B,n);

	fillM(A,n,soma);
	fillM(B,n,soma);

	cout << "A:" << endl;
	printM(A,n);
	cout << "B:" << endl;
	printM(B,n);

	int **C = NULL;

//	C = multiplicaI(A,B,n);
//	cout << "C:" << endl;
//	printM(C,n);
	// Se C ja tiver apontando pra 'algo', deletar 'algo' antes de apontar C para um novo lugar.
//	deleteM(C,n);

	C = multiplicaR(A,B,n);
	cout << "C:" << endl;
	printM(C,n);

	deleteM(A,n);
	deleteM(B,n);
	deleteM(C,n);

	return 0;
}