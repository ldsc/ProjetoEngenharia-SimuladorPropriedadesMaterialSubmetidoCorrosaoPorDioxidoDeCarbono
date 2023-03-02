#ifndef TAXADECORROSAO_H
#define TAXADECORROSAO_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
#include<fstream>
#include<cmath>




class TaxaDeCorrosao
{
	double W0, W1, T, P, S;
	std::fstream f, fp;
public:
	TaxaDeCorrosao();
	virtual ~TaxaDeCorrosao();
	void inicializa(double w0, double t, double p, double s);
	void Calculo(std::vector<double> W1, std::vector<double> Temp);

};

#endif // TAXADECORROSAO_H
