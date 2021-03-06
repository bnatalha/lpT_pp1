/**
* @brief myMatrix_calc.tpp
* @details Implementaões das funções em myMatrix_calc.h
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 27/04/17
* @date --
* @sa http://stackoverflow.com/questions/495021/
*/
#ifndef MYMATRIX_CALC_CPP
#define MYMATRIX_CALC_CPP
#include "myMatrix_calc.h"

/**
* @brief Projeto de Programação I
* @param Funcao que multiplica duas matrizes quadradas de dimensao n x n de forma iterativa
* @param A Matriz de entrada
* @param B Matriz de entrada
* @param n Dimensao das matrizes de entrada
* @return Matriz produto resultante da multiplicacao
*/
template <typename T>
T** multiplicaI(T** A, T** B, int n)
{
	if(n <= 0)
	{
		cerr << "em multiplicaI: Tamanho inválido para soma de Matriz." << endl;
		exit(1);
	}

	T** C = NULL;	// Ponteiro para Matriz resultante

	buildM(C,n);	// Aloca C dinamicamente

	for (int i = 0 ; i < n; ++i)
	{
		for (int j = 0, sum = 0; j < n; ++j)
		{
			sum = 0;
			
			for (int k = 0; k < n; ++k)
			{
				sum += A[i][k] * B[k][j];
			}

			C[i][j] = sum;
		}

	}

	return C;
}

/**
* @brief Funcao que soma duas matrizes quadradas de dimensao n x n de forma recursiva
* @param A Matriz de entrada
* @param B Matriz de entrada
* @param n Dimensao das matrizes de entrada
* @return Matriz resultante da soma
*/
template <typename T>
T** somaI(T** A, T** B, int n)
{	
	if(n <= 0)
	{
		cerr << "em somaI: Tamanho inválido para soma de Matriz." << endl;
		exit(1);
	}

	T** C = NULL;	// Ponteiro para Matriz resultante

	buildM(C,n);	// Aloca C dinamicamente
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			C[i][j] = A[i][j] + B[i][j]; 
	}

	return C;
}

/**
* @brief Funcao que multiplica duas matrizes quadradas de dimensao n x n de forma recursiva
* @param A Matriz de entrada
* @param B Matriz de entrada
* @param n Dimensao das matrizes de entrada
* @return Matriz produto resultante da multiplicacao
*/
template <typename T>
T** multiplicaR(T** A, T** B, int n)
{
	if(n <= 0)
	{
		cerr << "em MultiplicarR: Tamanho inválido para soma de Matriz." << endl;
		exit(1);
	}

	T** C = NULL;	// Ponteiro para Matriz resultante
	buildM(C,n);	// Aloca C dinamicamente

	if (n == 1)
		C[0][0] = A[0][0] * B[0][0];
	else
	{
		T** A_11 = NULL; T** A_12 = NULL; T** A_21 = NULL; T** A_22 = NULL;	// Partições da Matriz A
		T** B_11 = NULL; T** B_12 = NULL; T** B_21 = NULL; T** B_22 = NULL;	// Partições da Matriz B		
		T** C_11 = NULL; T** C_12 = NULL; T** C_21 = NULL; T** C_22 = NULL;	// Partições da Matriz C

		T** P1 = NULL; T** P2 = NULL; T** P3 = NULL; T** P4 = NULL; 		// Sub-Matrizes para Produtos
		T** P5 = NULL; T** P6 = NULL; T** P7 = NULL; T** P8 = NULL;

		// Building A, B and C Partitions...
		buildM(A_11,n/2); buildM(A_12,n/2); buildM(A_21,n/2); buildM(A_22,n/2);
		buildM(B_11,n/2); buildM(B_12,n/2); buildM(B_21,n/2); buildM(B_22,n/2);

		//filling A and B partitions...
		copy_partitionM(A, A_11, n/2,   0,   0, Divide);
		copy_partitionM(A, A_12, n/2,   0, n/2, Divide);
		copy_partitionM(A, A_21, n/2, n/2,   0, Divide);
		copy_partitionM(A, A_22, n/2, n/2, n/2, Divide);
		//
		copy_partitionM(B, B_11, n/2,   0,   0, Divide);
		copy_partitionM(B, B_12, n/2,   0, n/2, Divide);
		copy_partitionM(B, B_21, n/2, n/2,   0, Divide);
		copy_partitionM(B, B_22, n/2, n/2, n/2, Divide);

		//calculating P's
		P1 = multiplicaR(A_11, B_11, n/2);
		P2 = multiplicaR(A_12, B_21, n/2);
		P3 = multiplicaR(A_11, B_12, n/2);
		P4 = multiplicaR(A_12, B_22, n/2);
		P5 = multiplicaR(A_21, B_11, n/2);
		P6 = multiplicaR(A_22, B_21, n/2);
		P7 = multiplicaR(A_21, B_12, n/2);
		P8 = multiplicaR(A_22, B_22, n/2);

		// Calculating C partitions...
		C_11 = somaI(P1,P2,n/2); C_12 = somaI(P3,P4,n/2);
		C_21 = somaI(P5,P6,n/2); C_22 = somaI(P7,P8,n/2);

		// Agrupar as quatro sub-matrizes C_11 , C_12 , C_21 e C_22 na matriz produto C
		copy_partitionM(C, C_11, n/2,   0,   0, Unite);
		copy_partitionM(C, C_12, n/2,   0, n/2, Unite);
		copy_partitionM(C, C_21, n/2, n/2,   0, Unite);
		copy_partitionM(C, C_22, n/2, n/2, n/2, Unite);

		//Deleting A and B partitions (not needed anymore)...
		deleteM(A_11,n/2); deleteM(A_12,n/2); deleteM(A_21,n/2); deleteM(A_22,n/2);
		deleteM(B_11,n/2); deleteM(B_12,n/2); deleteM(B_21,n/2); deleteM(B_22,n/2);

		// Deleting C partitions (not needed anymore)...
		deleteM(C_11,n/2); deleteM(C_12,n/2); deleteM(C_21,n/2); deleteM(C_22,n/2);

		// Delete P's (not needed anymore)...
		deleteM(P1,n/2);   deleteM(P2,n/2);   deleteM(P3,n/2);   deleteM(P4,n/2);
		deleteM(P5,n/2);   deleteM(P6,n/2);   deleteM(P7,n/2);   deleteM(P8,n/2);

	}

	return C;
}

#endif