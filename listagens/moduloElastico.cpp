#include "stdafx.h"

#include "moduloElastico.h"
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <vector>
#include<fstream>
#include<cmath>

using namespace std;


moduloElastico::moduloElastico() {

}

moduloElastico::~moduloElastico() {
	//dtor
}
void moduloElastico::inicializa(double area, double l0) {
	Area = area;
	L0 = l0;
}
void moduloElastico::Calculo(vector<double> N, vector<double> L, vector<double> T) {
	int i = 0;
	double aux;
#ifdef WIN32
	f.open("Out\\ModuloElastico\\moduloElastico.txt", ios_base::out);
	fp.open("Out\\ModuloElastico\\ModuloElastico.plt", ios_base::out);
#else
	f.open("./Out/ModuloElastico/moduloElastico.txt", ios_base::out);
	fp.open("./Out/ModuloElastico/ModuloElastico.plt", ios_base::out);
#endif
	cout << "Modulo de distorcao - Temperatura\n";
	fp << "reset" << endl;
	fp << "set title\"\"" << endl;
	fp << "set xlabel \"Temperatura (ºC)\"" << endl;
	fp << "set ylabel \"Modulo Elastico (GPa)\"" << endl;
	fp << "f(x) = a*x + b" << endl;
	fp << "fit f(x) 'moduloElastico.txt' via a,b " << endl;
	fp << "plot 'moduloElastico.txt', f(x)" << endl;
	fp << "set term post eps enhanced color" << endl;
	fp << "set out 'ModuloElastico.eps' " << endl;
	fp.close();
	vector<double>::iterator itl = L.begin();
	vector<double>::iterator itt = T.begin();
	for (vector<double>::iterator it = N.begin(); it != N.end(); ++it, ++itl, ++itt) {
		aux = *it;
		Tensao.push_back(aux / Area);
		if (i == 0) {
			Deformacao.push_back(1);
		}
		else {
			Deformacao.push_back((*itl - L0) / L0);
		}
		MD.push_back((Tensao.at(i)) / (Deformacao.at(i)));
		cout << MD.at(i) << " " << *itt << endl;
		f << *itt << " " << MD.at(i) << endl;
		++i;
	}
	f.close();
#ifdef WIN32
	FILE *pipe = _popen("gnuplot\\bin\\gnuplot.exe -persist", "w");
	if (pipe != NULL) {
		fprintf(pipe, "cd 'Out/ModuloElastico'\n");
		fprintf(pipe, "load 'ModuloElastico.plt'\n");
		fflush(pipe);
	}
	else {
		cout << "Script não carregado" << endl;
	}
	_pclose(pipe);
#else
	FILE *pipe = popen("gnuplot -persistent", "w");
	if (pipe != NULL) {
		fprintf(pipe, "cd 'Out/ModuloElastico'\n");
		fprintf(pipe, "load 'ModuloElastico.plt'\n");
		fflush(pipe);
	}
	else {
		cout << "Script não carregado" << endl;
	}
	pclose(pipe);
#endif
}

std::vector<double> moduloElastico::getMD() {
	return MD;
}
