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
#include "myMatrix_vector.h"	// para build_vectorM(), delete_vectorM();
#include <chrono>	// para Marcar o tempo de execução em determinado intervalo no código
#include <fstream>

// Tipo para armazenar tempo da maquina em nanosegundo
typedef std::chrono::duration<double, std::nano> nanoTiming;

// nº de execuções que cada 'multiplicaX' da main vai realizar para diferentes mutipliações
int nEXECUCOES = 20;

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
//[!] Exceção_2 (Argumento invalido)
//[!] Se C ja tiver apontando pra 'algo', deletar 'algo' antes de apontar C para um novo lugar.
//[!] Modificar o tipo a ser lido atraves de uma especificação por terminal
	M_vector<int> *vA = NULL;
	M_vector<int> *vB = NULL;
	M_vector<int> *vC = NULL;
	int vSize = argc-1;
	int *vDimensions = new int[vSize];
	string dummy;
	
	// Criando um arranjo de inteiros contendo as dimensões passadas por terminal
	for (int i = 1; i < argc; ++i) {// pula o primeiro argumento (path do executavel)
		dummy = argv[i];		
		vDimensions[i-1] = std::stoi(dummy);
	}
	
	// Construindo vetores..
	build_vectorM(vA, vSize, vDimensions);
	build_vectorM(vB, vSize, vDimensions);
	vC = new M_vector<int>[vSize];

	// Atribuindo valores a vetores...
	for (int i = 0; i < vSize; ++i)	{
		streamM(vA[i].vectorM, vA[i].dimension, A);
		streamM(vB[i].vectorM, vB[i].dimension, B);
	}

	// Criando vetores que armazenaram tempos de execuções
	nanoTiming **TemposI = new nanoTiming*[vSize];
//	nanoTiming **TemposR = new nanoTiming*[vSize];
	for (int i = 0; i < vSize; ++i)	{	// Para cada dimensão disponivel:
		TemposI[i] = new nanoTiming[nEXECUCOES];	// Cria vetor de durações com tamanho 20.
//		TemposR[i] = new nanoTiming[nEXECUCOES];
	}

	// Calculando com multiplicaI e atribuindo em vC
	for (int i = 0; i < vSize; ++i)	{
		for (int j = 0; j < nEXECUCOES; ++j) {

			if(vC[i].vectorM != NULL) deleteM(vC[i].vectorM, vC[i].dimension);

			auto start = std::chrono::steady_clock::now();	// Salva o tempo atual do sistema em 'start'
			// === BEGINNING ===
			//
			vC[i].vectorM = multiplicaI(vA[i].vectorM, vB[i].vectorM, vA[i].dimension);
			//
			// ====== END ======
			auto end = std::chrono::steady_clock::now();	// Salva o tempo atual do sistema em 'end'
			auto timing = end - start;	// Salva o tempo que passou entre 'start' e 'end'
			TemposI[i][j] = nanoTiming(timing);	// Salva 'timing' em um array em TemposI;

			vC[i].dimension = vA[i].dimension;	// Salva a dimensão da matriz atual em vC (usado depois em streamM)
		}
	}

	print_vectorM(vC, vSize);

	// Printando valores de tempo
	cout << "timing:\n 0|\t1|..." << endl;
	for (int i = 0; i < nEXECUCOES; ++i)
	{
		for (int j = 0; j < vSize; ++j)
		{
			cout << TemposI[j][i].count() << "| ";
		}
		cout << endl;
	}
/*
	// Calculando com multiplicaR e atribuindo em vC(so começa a contar após deletar vC[i].vectorM)
	for (int i = 0; i < vSize; ++i)	{
		deleteM(vC[i].vectorM, vC[i].dimension);
		vC[i].vectorM = multiplicaR(vA[i].vectorM, vB[i].vectorM, vA[i].dimension);
		vC[i].dimension = vA[i].dimension;
	}

	// Gravando matrizes produtos
	for (int i = 0; i < vSize; ++i)
		streamM(vC[i].vectorM, vC[i].dimension, C);
*/
	// Deletando vA, vB, vC, TempoR, TempoI e vDimensions 
	delete_vectorM(vA, vSize);
	delete_vectorM(vB, vSize);
	delete_vectorM(vC, vSize);
	for (int i = 0; i < vSize; ++i)
	{
		delete[] TemposI[i];
//		delete[] TemposR[i];
	}
	delete[] TemposI;
//	delete[] TemposR;
	delete[] vDimensions;

	return 0;
}