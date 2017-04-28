#ifndef MYMATRIX_STREAM_VECTOR_CPP
#define MYMATRIX_STREAM_VECTOR_CPP

#include "myMatrix_vector.h"

template <typename T>
void build_vectorM(M_vector<T> *&vecM , const int &n, int *&vDim)
{
	// Aloca o vector de matrizes
	vecM = new M_vector<T>[n];

	for (int i = 0; i < n; ++i)
	{
		// Guarda o tamanho da Matriz [i]
		vecM[i].dimension = vDim[i];
		// Aloca a Matriz[i]
		buildM(vecM[i].vectorM, vecM[i].dimension);
	}
	
}

template <typename T>
void delete_vectorM(M_vector<T> *&vecM, const int &n)
{
	for (int i = 0; i < n; ++i)
		deleteM(vecM[i].vectorM, vecM[i].dimension);
	delete[] vecM;

}


#endif