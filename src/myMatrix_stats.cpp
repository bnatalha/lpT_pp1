
/**
* @file 	myMatrix_stats.cpp
* @brief	Onde fica a implementações das funções em myMatrix_stats.h
* @author	Natália Azevedo de Brito (https://github.com/bnatalha)
* @since	29/04/2017
* @date		--/05/2017
* @sa 	-- https://github.com/bnatalha/lpT_lab4
*/

#include "header.h"
#include "myMatrix_stats.h"
#include <cmath>
#include <fstream>

using std::fstream;


/**
* @brief	Função time_peaks
* @details	Calcula maior/menor tempo de multiplicação de determinado array em 'TempoX'
*/
double time_peaks(  myTiming *&vTime, const myStats_type &param )
{
	myTiming peakAmount = vTime[0];

	for (int i = 0; i < N_EXECUCOES; ++i)
		if( myCompare( vTime[i], peakAmount ) == param )
			peakAmount = vTime[i];
	return peakAmount.count();
}

/**
* @brief	Função sum_states
* @details	Calcúla a soma dos tempos de multiplicação para matrizes de uma certa dimensão 
*/
double sum_times( myTiming *&vTime)
{
	double sum = 0;

	for (int i = 0; i < N_EXECUCOES; ++i)
		sum += vTime[i].count();

	return sum;
}

/**
* @brief	Função desvp_states
* @details	Calcúla desvião padrão de tempos de execução de mutiplicação de matrizes de certa dimensão
*/
double desvp_times( myTiming *&vTime, const double &myMedia_times)
{
	double sum = 0;

	for (int i = 0; i < N_EXECUCOES; ++i)
	{
		sum += pow( vTime[i].count() - myMedia_times, 2);
	}

	//transformar myTiming em double

	return sqrt( sum / N_EXECUCOES );
}

void save_times( const myMatrix_Stats *vStats, const int &vSize, const int *vDim, const char *filename)
{

	fstream stats_stream;

	// Abre stream para arquivo ondeMatriz
	stats_stream.open(filename, std::fstream::out);

	// Caso a stream não tenha aberto com sucesso
	if(!stats_stream){
		cerr <<	"Houve algo errado ao tentar abrir " << filename << "." << endl;
		exit(1);
	}
	
	string stream_holder;
	
	for (int i = 0; i < vSize; ++i)
	{
		stats_stream << vDim[i] << " "
			<< vStats[i].min << " " 
			<< vStats[i].max << " "
			<< vStats[i].media << " "
			<< vStats[i].desvp << endl;
	}

	// Fecha a stream.
	stats_stream.close();
}

bool my_a (const myMatrix_Stats *&vStats ){ return true; }