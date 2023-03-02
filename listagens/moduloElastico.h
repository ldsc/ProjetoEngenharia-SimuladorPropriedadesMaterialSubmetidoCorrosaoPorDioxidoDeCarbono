#ifndef MODULOELASTICO_H
#define MODULOELASTICO_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
#include<fstream>
#include<cmath>



class moduloElastico
{
	double Area;
	double L0;
	std::vector<double> Tensao, Deformacao, MD;
	std::fstream f, fp;
public:
	moduloElastico();
	virtual ~moduloElastico();
	void inicializa(double area, double l0);
	void Calculo(std::vector<double> N, std::vector<double> L, std::vector<double> T);
	std::vector<double> getMD();
	
};

#endif // MODULOELASTICO_H
