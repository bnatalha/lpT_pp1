#ifndef HEADER_H
#define HEADER_H

#include <iostream>	//	para cout(), cin(), endl(), cerr();
#include <cstdlib>	//	para exit();
#include <string>	
#include <chrono>

#define N_EXECUCOES 20

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;

// Variaveis globais

//typedef std::chrono::duration<double> myTiming; // Tipo para armazenar tempo da maquina em segundos;
typedef std::chrono::duration< double, std::centi > myTiming; // Tempo em decimal

//int nEXECUCOES = 20; // nº de execuções que cada 'multiplicaX' da main vai realizar para diferentes mutipliações

#endif