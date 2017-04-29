#ifndef MYMATRIX_VECTOR_H
#define MYMATRIX_VECTOR_H

#include "myMatrix.h"

template <typename T>
struct M_vector
{
	T** vectorM = NULL;
	int dimension;
};


template <typename T>
void build_vectorM(M_vector<T> *&vM , const int &n, int *&vDim);

template <typename T>
void print_vectorM(M_vector<T> *&vM, const int &n);

template <typename T>
void delete_vectorM(M_vector<T> *&vM, const int &n);

#include "myMatrix_vector.cpp"

#endif