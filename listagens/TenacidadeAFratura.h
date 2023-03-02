#ifndef TENACIDADEAFRATRURA_H
#define TENACIDADEAFRATRURA_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>



class TenacidadeAFratrura
{
	float C, D;
	std::fstream f, fp;
public:
	TenacidadeAFratrura();
	virtual ~TenacidadeAFratrura();
	void inicializa(double c, double d);
	void Calculo(std::vector<double> N, std::vector<double> T, std::vector<double> MD);
};

#endif // TENACIDADEAFRATRURA_H
