#ifndef MYMATRIX_STREAM_H
#define MYMATRIX_STREAM_H

template <typename T>
void readM(T**& M_dxd, const int dimension, M_type param)
{
	// Monta o nome do arquivo a partir da dimensão especificada
	string input_filename ("data/");
	input_filename += (param == A?'A':'B');
	input_filename += std::to_string(dimension);
	input_filename += 'x';
	input_filename += std::to_string(dimension);
//[!]

	// Abre stream de entrada para leitura de Matriz
	ifstream M_input (input_filename.c_str())

	if(!M_input){
		cerr <<	"Houve algo errado ao tentar abrir " << input_filename << "." << endl;
		exit(1);
	}
	//else
	string stream_holder;
	
	// Ignora primera linha
	getline(M_input, stream_holder);
//[!] Checar dimensões da Matriz()

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

#endif