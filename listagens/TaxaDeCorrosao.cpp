#include "stdafx.h"
#include "TaxaDeCorrosao.h"

#include<iostream>
#include<cstdlib>
#include <vector>
#include<fstream>
#include<cmath>

using namespace std;


TaxaDeCorrosao::TaxaDeCorrosao()
{
	//ctor
}

TaxaDeCorrosao::~TaxaDeCorrosao()
{
	//dtor
}
void TaxaDeCorrosao::inicializa(double w0, double t, double p, double s) {
	W0 = w0;
	T = t;
	P = p;
	S = s;
}
void TaxaDeCorrosao::Calculo(vector<double> W1, vector<double> Temp) {
#ifdef WIN32
	f.open("Out\\TaxaCorrosao\\TaxaDeCorrosao.txt", ios_base::out);
	fp.open("Out\\TaxaCorrosao\\TaxaDeCorrosao.plt", ios_base::out);
#else
	f.open("./Out/TaxaCorrosao/TaxaDeCorrosao.txt", ios_base::out);
	fp.open("./Out/TaxaCorrosao/TaxaDeCorrosao.plt", ios_base::out);
#endif
	double sup, inf, Ws;
	int i = 0;
	fp << "reset" << endl;
	fp << "set title\"\"" << endl;
	fp << "set xlabel \"Temperatura (ºC)\"" << endl;
	fp << "set ylabel \"Taxa de Corrosão (mm/y)\"" << endl;
	fp << "f(x) = a*x + b" << endl;
	fp << "fit f(x) 'TaxaDeCorrosao.txt' via a,b " << endl;
	fp << "plot 'TaxaDeCorrosao.txt', f(x)" << endl;
	fp << "set term post eps enhanced color" << endl;
	fp << "set out 'TaxaDeCorrosao.eps' " << endl;
	fp.close();
	vector<double>::iterator itt = Temp.begin();
	cout << "Taxa de corrosao - Temperatura\n";
	//system("pause");
	for (vector<double>::iterator it = W1.begin(); it != W1.end(); ++it, ++itt) {
		Ws = W0 - (*it);
		sup = Ws * 1000 * 365 * 24;
		inf = T*P*S;
		cout << (sup / inf) << " " << *itt << endl;
		f << *itt << " " << (sup / inf) << endl;
		++i;
	}
	f.close();
	//system("pause");
#ifdef WIN32
	FILE *pipe = _popen("gnuplot\\bin\\gnuplot.exe -persist", "w");
	if (pipe != NULL) {
		fprintf(pipe, "cd 'Out/TaxaCorrosao'\n");
		//system("pause");
		fprintf(pipe, "load 'TaxaDeCorrosao.plt'\n");
		//system("pause");
		//fflush(pipe);
		//system("pause");
	}
	else {
		cout << "Script não carregado" << endl;
	}
	_pclose(pipe);
#else
	FILE *pipe = popen("gnuplot -persistent", "w");
	if (pipe != NULL) {
		fprintf(pipe, "cd 'Out/TaxaCorrosao'\n");
		fprintf(pipe, "load 'TaxaDeCorrosao.plt'\n");
		fflush(pipe);
	}
	else {
		cout << "Script não carregado" << endl;
	}
	pclose(pipe);
#endif
}
