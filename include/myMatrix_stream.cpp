#ifndef MYMATRIX_STREAM_CPP
#define MYMATRIX_STREAM_CPP

#include "myMatrix_stream.h"
/*
template <typename T>
void readM(T** &M_dxd, const int dimension, M_type param)
{
	// Monta o nome do arquivo de entrada a partir da dimensão e 'param' especificada
	string input_filename ("data/input/");
	input_filename += (param == A?'A':'B');
	input_filename += std::to_string(dimension);
	input_filename += 'x';
	input_filename += std::to_string(dimension);
	input_filename += ".txt";

	// Abre stream de entrada para leitura de Matriz
	ifstream M_input (input_filename.c_str());

	// Caso a stream não tenha aberto com sucesso
	if(!M_input){
		cerr <<	"Houve algo errado ao tentar abrir " << input_filename << "." << endl;
		exit(1);
	}
	
	string stream_holder;
	
	// Ignora primera linha
	getline(M_input, stream_holder);
//[!] Checar dimensões da Matriz() ?

	// Armazena tudo
	for (int i = 0; i < dimension; ++i)
	{
		for (int j = 0; j < dimension; ++j)
		{
			M_input >> M_dxd[i][j];
		}
	}

	// Fecha a stream.
	M_input.close();
}
*/
template <typename T>
void streamM(T** &M_dxd, const int dimension, M_type param)
{
	// Monta o nome do arquivo de saída a partir da dimensão especificada
	string stream_filename ("data/");
	if(param == C) stream_filename += "output/C";
	else stream_filename += (param == A?"input/A":"input/B");
	stream_filename += std::to_string(dimension);
	stream_filename += 'x';
	stream_filename += std::to_string(dimension);
	stream_filename += ".txt";

	// Abre stream para arquivo ondeMatriz

	fstream M_stream;

	if(param == C) M_stream.open(stream_filename, std::fstream::out);
	else M_stream.open(stream_filename, std::fstream::in);

	// Caso a stream não tenha aberto com sucesso
	if(!M_stream){
		cerr <<	"Houve algo errado ao tentar abrir " << stream_filename << "." << endl;
		exit(1);
	}
	
	string stream_holder;
	
	
	if(param == C) M_stream << dimension << " " << dimension << endl;	// Escreve as dimensões da Matriz
	else	getline(M_stream, stream_holder);	// Ignora primera linha do stream_filename
//[!] Checar dimensões da Matriz() ?

	// Armazena/Grava tudo
	for (int i = 0; i < dimension; ++i)
	{
		for (int j = 0; j < dimension; ++j)
		{
			if(param == C) M_stream << M_dxd[i][j];
			else M_stream >> M_dxd[i][j];
		}
	}

	// Fecha a stream.
	M_stream.close();


}

#endif