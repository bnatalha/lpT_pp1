#ifndef MYMATRIX_STATS_H
#define MYMATRIX_STATS_H

#include "header.h"

struct myMatrix_Stats{
	double min;
	double max;
	double media;
	double desvp;
};

enum myStats_type { Menor = -1, Maior =  1 };

template <typename T>
int myCompare( const T &a, const T &b);

#include "myMatrix_stats_comp.cpp"

double time_peaks( myTiming *&vTime, const myStats_type &param );
double sum_times( myTiming *&vTime);
double desvp_times( myTiming *&vTime, const double &myMedia_times);

// não reconhece interative como lvalue
void save_times( const myMatrix_Stats *vStats, const int &vSize, const int *vDim, const char *filename);


#endif