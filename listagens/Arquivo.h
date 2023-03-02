#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

class Arquivo
{
	std::string linha;
	double n, l, t;
	std::vector <double> N, L, T;
public:
	Arquivo();
	virtual ~Arquivo();
	int abrir(std::string nomearq);
	std::vector<double> getN();
	std::vector<double> getL();
	std::vector<double> getT();
};

#endif // ARQUIVO_H
