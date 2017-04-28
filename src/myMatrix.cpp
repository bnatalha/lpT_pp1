#include "myMatrix.h"

void buildM(int **&M, const int n){

	M = new int*[n];
	for(int i = 0; i < n; i++) M[i] = new int[n];
}

//temporary
void fillM(int **&M, const int n, int &soma){
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			M[i][j] = soma++;
		}
	}
}

void printM(int **M, const int n){

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
}

void deleteM(int **&M, const int n){

	for(int i = 0; i < n; i++) delete[] M[i];
	delete[] M;
}

int** copyM(int **&M, const int n){
	if(n <= 0)
	{
		cerr << "em copyM: Tamanho inválido para soma de Matriz." << endl;
		exit(1);
	}
	//else
	int** M_copy;
	buildM(M_copy,n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			M_copy[i][j] = M[i][j];
		}
	}

	return M_copy;
}

//transforma em copyM, passando tambem o tamanho da partição
void copy_partitionM(
	int **&M, 
	int **&M_partition, 
	const int &partition_size, 
	const int &lin, 
	const int &col, 
	const operationM &param)
{
	for (int i = 0; i < partition_size; ++i)
	{
		for (int j = 0; j < partition_size; ++j)
		{
			if(param == Divide)
	 			M_partition[i][j] = M[lin+i][col+j];
	 		else //unify
	 			M[lin+i][col+j] = M_partition[i][j];
		}
	}	
}