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
#include "myMatrix_stats.h"
#include <chrono>	// para Marcar o tempo de execução em determinado intervalo no código
#include <fstream>


/**
* @brief Função main
* @detail Calcula o tempo e calcula matriz. --
* @param argc Tamanho de 'argv'
* @param argv Ponteiro para um array de Char constante com --
*/
int main(int argc, char const *argv[])
{
	auto comeco = std::chrono::steady_clock::now();

	if(argc == 1)	// Exceção_1 (numero de argumentos insuficiente)
	{
		cerr << "Número de argumentos insuficiente."<< endl
			<< "Informe os numeros que reprensentam as dimensões das Matrizes (localizadas em 'data/input') a serem utilizadas." << endl
			<< "ex. Calcular usando matrizes de dimensões 2x2, 4x4 e 16x16:" << endl
			<< ">$ bin/main 2 16 4" << endl;
		exit(1);
	}
//[!] Exceção_2 (Argumento invalido)
//[!] Se vC ja tiver apontando pra 'algo', deletar 'algo' antes de apontar vC para um novo lugar.
//[!] Modificar o tipo a ser lido atraves de uma especificação por terminal

	M_vector<int> *vA = NULL;
	M_vector<int> *vB = NULL;
	M_vector<int> *vC = NULL;
	int vSize = argc-1;
	int *vDimensions = new int[vSize];
	string dummy;
	
	// Criando um arranjo de inteiros contendo as dimensões passadas por terminal
	cout << "(01) Reading dimensions...";
	for (int i = 1; i < argc; ++i) {// pula o primeiro argumento (path do executavel)
		dummy = argv[i];		
		vDimensions[i-1] = std::stoi(dummy);
	}
	cout << "Done.";

	cout << "\t[ ";
	for (int i = 0; i < vSize; ++i)
	{
		cout << vDimensions[i] << ", ";
	}
	cout << "];\n";
	
	// Construindo vetores..
	cout << "(02) Building vA, vB and creating vC...";
	build_vectorM(vA, vSize, vDimensions);
	build_vectorM(vB, vSize, vDimensions);
	vC = new M_vector<int>[vSize];
	cout << "Done" << endl;

	// Atribuindo valores a vetores...
	cout << "(03) Reading and saving values for vA and vB...";
	for (int i = 0; i < vSize; ++i)	{
		streamM(vA[i].vectorM, vA[i].dimension, A);
		streamM(vB[i].vectorM, vB[i].dimension, B);
	}
	cout << "Done" << endl;

	// Criando vetores que armazenaram tempos de execuções
	cout << "(04) Allocating **myTiming...";
	myTiming **TemposI = new myTiming*[vSize];
	myTiming **TemposR = new myTiming*[vSize];
	for (int i = 0; i < vSize; ++i)	{	// Para cada dimensão disponivel:
		TemposI[i] = new myTiming[N_EXECUCOES];	// Cria vetor de durações com tamanho 20.
 		TemposR[i] = new myTiming[N_EXECUCOES];
	}
	cout << "Done" << endl;

	// ======================================================================================
	// ================================ INTERATIVO ==========================================
	// ======================================================================================
	//
	// Calculando com multiplicaI e atribuindo em vC
	cout << "(05)\n>>>Calculating vC[i].vectorM with mutilplicaI()...\n";
	cout << "\n\t\tI--------------------------------I--------------------------------I\n";
	for (int i = 0; i < vSize; ++i)	{
		cout << "Current dimension: " << vDimensions[i] << "x" << vDimensions[i] << endl;
		//cout << "Counting 'till 19: ";
		for (int j = 0; j < N_EXECUCOES; ++j) {
			cout << "cycle: " << j;

			if(vC[i].vectorM != NULL) {
				cout << "\t>Deleting vC[" << j << "].vectorM...";
				deleteM(vC[i].vectorM, vC[i].dimension);
				cout << "Done\t";
			}

			auto start = std::chrono::steady_clock::now();	// Salva o tempo atual do sistema em 'start'
			// === BEGINNING ================================================
			//

			vC[i].vectorM = multiplicaI(vA[i].vectorM, vB[i].vectorM, vA[i].dimension);

			//
			// ====== END ===================================================
			auto end = std::chrono::steady_clock::now();	// Salva o tempo atual do sistema em 'end'
			auto timing = end - start;	// Salva o tempo que passou entre 'start' e 'end'

			TemposI[i][j] = std::chrono::duration<double,std::centi> (timing);	// Salva 'timing' em um array em TemposI;

			vC[i].dimension = vA[i].dimension;	// Salva a dimensão da matriz atual em vC (usado depois em streamM)
			
			if( j == 0 ) cout << "\t\t\t\t\t";
			cout << "\t...Done cycle(" 
				<< std::chrono::duration<double,std::centi> (timing).count() <<"cs) ("// << endl;
				<< std::chrono::duration<double,std::deci> (timing).count() <<"ds) ("
				<< std::chrono::duration_cast<std::chrono::seconds> (timing).count() <<"s)" << endl;
		}
		cout << "Done dimension.\n\n";
	}
	cout << "\n\t\tI--------------------------------I--------------------------------I\n";
	
	// ======================================================================================
	// ================================= RECURSIVO ==========================================
	// ======================================================================================
	//
	// Calculando com multiplicaR e atribuindo em vC(so começa a contar após deletar vC[i].vectorM)
	cout << "\n>>>Calculating vC[i].vectorM with mutilplicaR()...\n";
	cout << "\n\t\tR--------------------------------R--------------------------------R\n";
	for (int i = 0; i < vSize; ++i)	{
		cout << "Current dimension: " << vDimensions[i] << "x" << vDimensions[i] << endl;
		//cout << "Counting 'till 19: ";
		for (int j = 0; j < N_EXECUCOES; ++j) {
			cout << "cycle: " << j;

			if(vC[i].vectorM != NULL) {
				cout << "\t>Deleting vC[" << j << "].vectorM...";
				deleteM(vC[i].vectorM, vC[i].dimension);
				cout << "Done\t";
			}

			auto start = std::chrono::steady_clock::now();	// Salva o tempo atual do sistema em 'start'
			// === BEGINNING ================================================
			//

			vC[i].vectorM = multiplicaR(vA[i].vectorM, vB[i].vectorM, vA[i].dimension);

			//
			// ====== END ===================================================
			auto end = std::chrono::steady_clock::now();	// Salva o tempo atual do sistema em 'end'
			auto timing = end - start;	// Salva o tempo que passou entre 'start' e 'end'

			TemposR[i][j] = std::chrono::duration<double,std::centi> (timing);	// Salva 'timing' em um array em TemposI;

			vC[i].dimension = vA[i].dimension;	// Salva a dimensão da matriz atual em vC (usado depois em streamM)
			
			cout << "\t...Done cycle(" 
				<< std::chrono::duration<double,std::centi> (timing).count() <<"cs) ("
				<< std::chrono::duration<double,std::deci> (timing).count() <<"ds) ("
				<< std::chrono::duration_cast<std::chrono::seconds> (timing).count() <<"s)" << endl;
		}
		cout << "Done dimension.\n\n";		
	}
	cout << "\n\t\tR--------------------------------R--------------------------------R\n";
	cout << "...Done.\n=========================================================================================================\n";

	// Gravando matrizes produtos
	cout << "(06) Recording data/input/Cixi.txt files...";
	for (int i = 0; i < vSize; ++i)
		streamM(vC[i].vectorM, vC[i].dimension, C);
	cout << "Done" << endl;

	// Criando vetores que armazenarão estatisticas sobre tempos de execuções
	cout << "(07) Allocating *myMatrix_Stats...";
	myMatrix_Stats *stats_ite = new myMatrix_Stats[vSize];
	myMatrix_Stats *stats_rec = new myMatrix_Stats[vSize];
	cout << "Done" << endl;

	// Gerando estatisticas
	cout << "(08) Calculating and storing statistcs at *myMatrix_Stats...";
	for (int i = 0; i < vSize; ++i)
	{
		stats_ite[i].min = time_peaks(TemposI[i],Menor);
		stats_rec[i].min = time_peaks(TemposR[i],Menor);

		stats_ite[i].max = time_peaks(TemposI[i],Maior);
		stats_rec[i].max = time_peaks(TemposR[i],Maior);

		stats_ite[i].media = sum_times(TemposI[i]) / N_EXECUCOES;
		stats_rec[i].media = sum_times(TemposR[i]) / N_EXECUCOES;

		stats_ite[i].desvp = desvp_times(TemposI[i], stats_ite[i].media);
		stats_rec[i].desvp = desvp_times(TemposR[i], stats_rec[i].media);
	}
	cout << "Done" << endl;

	cout << ">>>\tstats:" << endl;
	for (int i = 0; i < vSize; ++i)
	{
		cout << "I\t" 
			<< vDimensions[i] << "x" << vDimensions[i] 
			<< ": min=" << stats_ite[i].min
			<< " max=" << stats_ite[i].max 
			<< " media=" << stats_ite[i].media
			<< " desvp=" << stats_ite[i].desvp << endl;
		cout << "R\t" 
			<< vDimensions[i] << "x" << vDimensions[i] 
			<< ": min=" << stats_rec[i].min
			<< " max=" << stats_rec[i].max 
			<< " media=" << stats_rec[i].media
			<< " desvp=" << stats_rec[i].desvp << endl;
	}
		for (int i = 0; i < vSize; ++i)
	{

	}

	// Gravando estatisticas
	cout << "\n(09) Recording stats files...";
	save_times(stats_ite, vSize, vDimensions, "data/stats-ite.dat");
	save_times(stats_rec, vSize, vDimensions, "data/stats-rec.dat");
	cout << "Done" << endl;

	// Deletando vA, vB, vC, TempoR, TempoI, stats_ite, stats_rec e vDimensions 
	cout << "\nDeleting alocated memory...";
	delete_vectorM(vA, vSize);
	delete_vectorM(vB, vSize);
	delete_vectorM(vC, vSize);
	for (int i = 0; i < vSize; ++i)
	{
		delete[] TemposI[i];
		delete[] TemposR[i];
	}
	delete[] TemposI;
	delete[] TemposR;
	delete[] stats_ite;
	delete[] stats_rec;
	delete[] vDimensions;
	cout << "Done" << endl<<endl;


	auto fim = std::chrono::steady_clock::now();

	auto total = fim - comeco;

	auto tempo = std::chrono::duration_cast<std::chrono::minutes> (total);

	if(tempo.count() > 0 ) cout << tempo.count() << "minutes and";
	cout << std::chrono::duration_cast<std::chrono::seconds> (total).count() % 60 << "seconds." << endl;


	return 0;
}