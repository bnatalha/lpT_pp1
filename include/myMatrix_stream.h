#ifndef MYMATRIX_STREAM_H
#define MYMATRIX_STREAM_H

#include "header.h"
#include <fstream>	//	para ifstream() e ofstream()
#include "myMatrix_vector.h"	//	para struct M_vector


enum M_type { A = 0, B, C };

using std::fstream;
/*
template <typename T>
void readM(T** &M_dxd, const int dimension, M_type param);
*/
template <typename T>
void streamM(T** &M_dxd, const int dimension, M_type param);

#include "myMatrix_stream.cpp"

#endif