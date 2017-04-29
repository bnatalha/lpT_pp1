#ifndef MYMATRIX_CPP
#define MYMATRIX_CPP
#include "myMatrix.h"

template <typename T>
void buildM(T **&M, const int n)
{
	M = new T*[n];
	for(int i = 0; i < n; i++) M[i] = new T[n];
}

//temporary
template <typename T>
void fillM(T **&M, const int n, T &soma)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			M[i][j] = soma++;
		}
	}
}

template <typename T>
void printM(T **M, const int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
}

template <typename T>
void deleteM(T **&M, const int n)
{
	for(int i = 0; i < n; i++) delete[] M[i];
	delete[] M;
}

template <typename T>
T** copyM(T **&M, const int n){
	if(n <= 0)
	{
		cerr << "em copyM: Tamanho inválido para soma de Matriz." << endl;
		exit(1);
	}
	//else
	T** M_copy;
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
template <typename T>
void copy_partitionM(
	T **&M, 
	T **&M_partition, 
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
	 		else //Unife
	 			M[lin+i][col+j] = M_partition[i][j];
		}
	}	
}

#endif