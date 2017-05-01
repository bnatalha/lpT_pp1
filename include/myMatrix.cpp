#ifndef MYMATRIX_CPP
#define MYMATRIX_CPP
#include "myMatrix.h"

template <typename T>
void buildM(T **&M, const int n)
{
	M = new T*[n];
	for(int i = 0; i < n; i++) M[i] = new T[n];
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