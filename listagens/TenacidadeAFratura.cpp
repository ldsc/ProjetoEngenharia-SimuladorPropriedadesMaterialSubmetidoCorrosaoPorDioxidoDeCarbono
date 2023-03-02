#include "stdafx.h"
#include "TenacidadeAFratura.h"

#include<iostream>
#include<cstdlib>
#include<cmath>
#include <vector>
#include<fstream>

using namespace std;


TenacidadeAFratrura::TenacidadeAFratrura()
{
	//ctor
}

TenacidadeAFratrura::~TenacidadeAFratrura()
{
	//dtor
}
void TenacidadeAFratrura::inicializa(double c, double d) {
	C = c;
	D = d;
}
void TenacidadeAFratrura::Calculo(vector<double> N, vector<double> T, vector<double> MD) {
	int i = 0;
	double EP, sup, inf;
#ifdef WIN32
	f.open("Out\\Tenacidade\\tenacidadeAFratura.txt", ios_base::out);
	fp.open("Out\\Tenacidade\\TenacidadeAFratura.plt", ios_base::out);
#else
	f.open("./Out/Tenacidade/tenacidadeAFratura.txt", ios_base::out);
	fp.open("./Out/Tenacidade/TenacidadeAFratura.plt", ios_base::out);
#endif
	fp << "reset" << endl;
	fp << "set title\"\"" << endl;
	fp << "set xlabel \"Temperatura (ºC)\"" << endl;
	fp << "set ylabel \"Tenacidade a fratura (MPa m^0.5)\"" << endl;
	fp << "f(x) = a*x + b" << endl;
	fp << "fit f(x) 'tenacidadeAFratura.txt' via a,b " << endl;
	fp << "plot 'tenacidadeAFratura.txt', f(x)" << endl;
	fp << "set term post eps enhanced color" << endl;
	fp << "set out 'TenacidadeAFratura.eps' " << endl;
	fp.close();
	vector<double>::iterator itmd = MD.begin();
	vector<double>::iterator itt = T.begin();
	cout << "Tenacidade a fratura - Temperatura\n";
	for (vector<double>::iterator it = N.begin(); it != N.end(); ++it, ++itmd, ++itt) {
		EP = (*it)*(*itmd);
		sup = 0.294*D*sqrt(EP);
		inf = powf(C, 1.5);
		cout << (sup / inf) << " " << *itt << endl;
		f << *itt << " " << (sup / inf) << endl;
		++i;
	}
	f.close();
#ifdef WIN32
	FILE *pipe = _popen("gnuplot\\bin\\gnuplot.exe -persist", "w");
	if (pipe != NULL) {
		fprintf(pipe, "cd 'Out/Tenacidade'\n");
		fprintf(pipe, "load 'TenacidadeAFratura.plt'\n");
		fflush(pipe);
	}
	else {
		cout << "Script não carregado" << endl;
	}
	_pclose(pipe);
#else
	FILE *pipe = popen("gnuplot -persistent", "w");
	if (pipe != NULL) {
		fprintf(pipe, "cd 'Out/Tenacidade'\n");
		fprintf(pipe, "load 'TenacidadeAFratura.plt'\n");
		fflush(pipe);
	}
	else {
		cout << "Script não carregado" << endl;
	}
	pclose(pipe);
#endif
}
