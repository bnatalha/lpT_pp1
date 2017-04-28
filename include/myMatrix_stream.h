#ifndef MYMATRIX_STREAM_CPP
#define MYMATRIX_STREAM_CPP

#include "header.h"
#include <fstream>	// para ifstream() e ofstream()

enum M_type { A = 0 };

using std::ifstream;
using std::ofstream;

template <typename T>
void readM(T**& M_dxd, const int dimension, M_type param);

//template <typename T>
//saveM(T**& M_dxd, const int dimension);

#endif