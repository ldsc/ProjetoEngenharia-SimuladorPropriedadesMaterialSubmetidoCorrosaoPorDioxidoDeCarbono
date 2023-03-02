#include "stdafx.h"
#include "Arquivo.h"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

Arquivo::Arquivo()
{
	//ctor
}

Arquivo::~Arquivo()
{
	//dtor
}

int Arquivo::abrir(string nomearq) {
#ifdef WIN32
	string nomearqF = "In\\" + nomearq + ".txt";
#else
	std::string nomearqF = "In/" + nomearq + ".txt";
#endif
	ifstream inFile(nomearqF.c_str());
	if (!inFile) {
		cout << "Arquivo nao encontrado, programa encerrado!\n";
		inFile.clear();
		return -1;
	}
	cout << "Arquivo encontrado com sucesso!\n";
	string::size_type sz, sz2;
	while (!inFile.eof()) {
		getline(inFile, linha);
		if (!linha.empty()) {
			n = stod(linha, &sz);
			N.push_back(n);
			l = std::stod(linha.substr(sz), &sz2);
			L.push_back(l);
			t = std::stod(linha.substr(sz).substr(sz2));
			T.push_back(t);
		}
	}
	inFile.close();
	inFile.clear();
	return 0;
}



vector<double> Arquivo::getN() {

	return N;
}


vector<double> Arquivo::getL() {

	return L;
}


vector<double> Arquivo::getT() {

	return T;
}
