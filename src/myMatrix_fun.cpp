/**
* @file myMatriz_fun.cpp
* @brief --
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 25/04/2017
* @date --
* @sa --
*/
//================================================================================================================
//================================================================================================================
//================================================================================================================
// Taken from .pdf
/*
void MultiplicaMatrizesRecursivo( 
	myMatriz &A, // A possui dimensão m × p
	myMatriz &B, // B possui dimensão p × n
	myMatriz &C, // C possui dimensão m × n
	const int & n)
{
	if (n == 1)
		C[1,1] = A[1,1] * B[1,1];

	else
	{
		myMatriz A_11(n/2,n/2), A_12(n/2,n/2), A_21(n/2,n/2), A_22(n/2,n/2);	// Partições da Matriz A
		myMatriz B_11(n/2,n/2), B_12(n/2,n/2), B_21(n/2,n/2), B_22(n/2,n/2);	// Partições da Matriz B
		myMatriz C_11(n/2,n/2), C_12(n/2,n/2), C_21(n/2,n/2), C_22(n/2,n/2);	// Partições da Matriz C
		myMatriz P1(n/2,n/2),   P2(n/2,n/2),   P3(n/2,n/2),   P4(n/2,n/2), 		// Sub-Matrizes para Produtos
			P5(n/2,n/2), P6(n/2,n/2), P7(n/2,n/2), P8(n/2,n/2);

		MultiplicaMatrizesRecursivo(A_11, B_11, P1, n/2);
		MultiplicaMatrizesRecursivo(A_12, B_21, P2, n/2);
		MultiplicaMatrizesRecursivo(A_11, B_12, P3, n/2);
		MultiplicaMatrizesRecursivo(A_12, B_22, P4, n/2);
		MultiplicaMatrizesRecursivo(A_21, B_11, P5, n/2);
		MultiplicaMatrizesRecursivo(A_21, B_12, P6, n/2);
		MultiplicaMatrizesRecursivo(A_22, B_21, P7, n/2);
		MultiplicaMatrizesRecursivo(A_22, B_22, P8, n/2);

		C_11 = SomaMatrizes(P1,P2);
		C_12 = SomaMatrizes(P3,P4);
		C_21 = SomaMatrizes(P5,P6);
		C_22 = SomaMatrizes(P7,P8);

		// Agrupar as quatro sub-matrizes C 11 , C 12 , C 21 e C 22 na matriz produto C
	}
}
*/
/*
void MultiplicaMatrizesIterativo( 
	myMatriz &A, 
	myMatriz &B, 
	myMatriz &C, 
	const int & m,
	const int & n,
	const int & p)
{
	int i, j, k, ;

	for (int i = 1 ; i > m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			soma = 0;
			
			for (int k = 1; k < p; ++k)
			{
				soma += A[i,k] * B[k,j];
			}

			C[i,j] = soma;
		}
	}
}
*/