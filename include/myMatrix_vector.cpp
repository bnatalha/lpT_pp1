#ifndef MYMATRIX_VECTOR_CPP
#define MYMATRIX_VECTOR_CPP

#include "myMatrix_vector.h"

template <typename T>
void build_vectorM(M_vector<T> *&vM , const int &n, int *&vDim)
{
	// Aloca o vector de matrizes
	vM = new M_vector<T>[n];

	for (int i = 0; i < n; ++i)
	{
		// Guarda o tamanho da Matriz [i]
		vM[i].dimension = vDim[i];

		// Aloca a Matriz[i]
		buildM(vM[i].vectorM, vM[i].dimension);
	}
}

template <typename T>
void print_vectorM(M_vector<T> *&vM, const int &n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << "M[" << i <<"]" << vM[i].dimension << "_ :" << endl;
		printM(vM[i].vectorM, vM[i].dimension);
		cout << endl;
	}
}

template <typename T>
void delete_vectorM(M_vector<T> *&vM, const int &n)
{
	for (int i = 0; i < n; ++i)
		deleteM(vM[i].vectorM, vM[i].dimension);
	delete[] vM;

}


#endif