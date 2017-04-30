#ifndef MYMATRIX_STATS_COMP_CPP
#define MYMATRIX_STATS_COMP_CPP

template <typename T>
int myCompare( const T &a, const T &b)
{
	if( a > b ) return 1;
	if( a < b ) return -1;
	return 0;
}

#endif