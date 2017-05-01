#ifndef MYMATRIX_H
#define MYMATRIX_H

#include "header.h"

enum operationM{
	Divide = 0,
	Unite = 1
};

template <typename T>
void buildM(T **&M, const int n);

template <typename T>
void printM(T **M, const int n);

template <typename T>
void deleteM(T **&M, const int n);

template <typename T>
void copy_partitionM(
	T **&M, 
	T **&M_partition, 
	const int &partition_size, 
	const int &col, 
	const int &lin, 
	const operationM &param);

#include "myMatrix.cpp"

#endif