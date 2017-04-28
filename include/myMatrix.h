#ifndef MYMATRIX_H
#define MYMATRIX_H

#include "header.h"

enum operationM{
	Divide = 0,
	Unite = 1
};

void buildM(int **&M, const int n);
void fillM(int **&M, const int n, int &soma);
void printM(int **M, const int n);
void deleteM(int **&M, const int n);
int** copyM(int **&M, const int n);
void copy_partitionM(
	int **&M, 
	int **&M_partition, 
	const int &partition_size, 
	const int &col, 
	const int &lin, 
	const operationM &param);

#include "myMatrix_fun.h"

#endif