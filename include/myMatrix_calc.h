#ifndef MYMATRIX_CALC_H
#define MYMATRIX_CALC_H

#include "myMatrix.h"

template <typename T>
T** multiplicaI(T** A, T** B, int n);

template <typename T>
T** somaI(T** A, T** B, int n);

template <typename T>
T** multiplicaR(T** A, T** B, int n);

#include "myMatrix_calc.cpp"

#endif