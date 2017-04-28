#ifndef MYMATRIX_STREAM_VECTOR_H
#define MYMATRIX_STREAM_VECTOR_H

#include "myMatrix.h"

template <typename T>
struct M_vector
{
	T** vectorM = NULL;
	int dimension;
};


template <typename T>
void build_vectorM(M_vector<T> *&vecM , const int &n, int *&vDim);

template <typename T>
void delete_vectorM(M_vector<T> *&vecM, const int &n);

#endif