#include "stdafx.h"

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include <vector>

#include "moduloElastico.h"
//#include "moduloElastico.cpp"
#include "TenacidadeAFratura.h"
//#include "TenacidadeAFratrura.cpp"
#include "TaxaDeCorrosao.h"
//#include "TaxaDeCorrosao.cpp"
#include "Arquivo.h"
//#include "Arquivo.cpp"

using namespace std;

int main() {
	int op;
	double vc, l, temp, area, l0, cp, peso0, tI, d, dens, s, p;
	std::vector<double> N, L, T, peso1;
	string nomearq;
	moduloElastico mE;
	TenacidadeAFratrura tF;
	TaxaDeCorrosao tC;
	Arquivo arq;
	cout << "Universidade Estadual Norte Fluminence Darcy Ribeiro \n Laboratorio de Engenharia e Exploracao de Petroleo \n Simulador de Propriedades Mecanicas de Material \n Submetido ao Processo de Corrosao por Dioxido de Carbono-Versao 1.0 \n Programacao Pratica Prof. Andre Duarte Bueno \n copyright Thayna Angelo dos Reis \n" << "Licenca GNU/GPL v2.0\n"<<endl;
	cout << "Entre com o numero respectivo a operacao desejada:\n 1- Usar dados de arquivo\n 2- Entrar com dados manualmente\n 3- Encerrar programa\n";
	cin >> op;
	switch (op) {
	case(1) :
#ifdef WIN32
		system("cls");
#endif
		cout << "Entre com o nome do arquivo sem extensao .txt, que esta localizado na pasta In e a seguir tecle enter:\n";
		cin >> nomearq;
		if (arq.abrir(nomearq) == -1) {
#ifdef WIN32
			system("pause");
#endif
			return 0;
		}
		N = arq.getN();
		L = arq.getL();
		T = arq.getT();
		cout << "Informe a area original [mm^2] da secao transversal do material:\n";
		cin >> area;
		cin.ignore();
		//setbuf(stdin, NULL);
		cout << "Informe o comprimento inicial [mm] do material:\n";
		cin >> l0;
		cin.ignore();
		//setbuf(stdin, NULL);
		cout << "Informe o comprimento da fenda [m]:\n";
		cin >> cp;
		cin.ignore();
		//setbuf(stdin, NULL);
		cout << "Informe o comprimento diagonal de indentacao [m]:\n";
		cin >> d;
		cin.ignore();
		//setbuf(stdin, NULL);
		cout << "Informe o peso original da especie [g]:\n";
		cin >> peso0;
		cin.ignore();
		//setbuf(stdin, NULL);
		cout << "Informe o peso final da especie [g] em relacao a seguinte temperatura:\n";
		for (vector<double>::iterator it = T.begin(); it != T.end(); ++it) {
			cout <<"T[°C]= "<< *it << " Peso[g]= ";
			cin >> p;
			peso1.push_back(p);
		}
		cin.ignore();
		//setbuf(stdin, NULL);
		cout << "Informe o tempo de imensao [h]:\n";
		cin >> tI;
		cin.ignore();
		//setbuf(stdin, NULL);
		cout << "Informe a densidade do material [g/mm^3]:\n";
		cin >> dens;
		cin.ignore();
		//setbuf(stdin, NULL);
		cout << "Informe a area da superficie exposta do material [mm^2]:\n";
		cin >> s;
		cin.ignore();
		//setbuf(stdin, NULL);
		mE.inicializa(area, l0);
		tF.inicializa(cp, d);
		tC.inicializa(peso0, tI, dens, s);
		cout << "Fazendo calculos...\n\n";
		mE.Calculo(N, L, T);
		tF.Calculo(N, T, mE.getMD());
		tC.Calculo(peso1, T);
		break;

	case(2) :
#ifdef WIN32
		system("cls");
#endif
		cout << "Entre com o valor de carga [N], comprimento [mm] e temperatura[Celsius] respectivamente:" << endl;
		cin >> vc >> l >> temp;
		setbuf(stdin, NULL);
		do {
			N.push_back(vc);
			L.push_back(l);
			T.push_back(temp);
			system("cls");
			cout << "Entre com o valor de carga [N], comprimento [mm] e temperatura[Celsius]respectivamente, ou todos os valores iguais a 0 para encerrar:" << endl;
			cin >> vc >> l >> temp;
			setbuf(stdin, NULL);
		} while (vc != 0 && l != 0 && temp != 0);
		cout << "Informe a area original [mm^2] da secao transversal do material:\n";
		cin >> area;
		setbuf(stdin, NULL);
		cout << "Informe o comprimento inicial [mm] do material:\n";
		cin >> l0;
		setbuf(stdin, NULL);
		cout << "Informe o comprimento da fenda [m]:\n";
		cin >> cp;
		setbuf(stdin, NULL);
		cout << "Informe o comprimento diagonal de indentacao[m]:\n";
		cin >> d;
		setbuf(stdin, NULL);
		cout << "Informe o peso original da especie [g]:\n";
		cin >> peso0;
		setbuf(stdin, NULL);
		cout << "Informe o peso final da especie [g] em relacao a seguinte temperatura:\n";
		for (vector<double>::iterator it = T.begin(); it != T.end(); ++it) {
			cout <<"T[°C]= "<< *it << " Peso[g]= ";
			cin >> p;
			peso1.push_back(p);
		}
		setbuf(stdin, NULL);
		cout << "Informe o tempo de imensao [h]:\n";
		cin >> tI;
		setbuf(stdin, NULL);
		cout << "Informe a densidade do material [g/mm^3]:\n";
		cin >> dens;
		setbuf(stdin, NULL);
		cout << "Informe a area da superficie exposta do material [mm^2]:\n";
		cin >> s;
		setbuf(stdin, NULL);
		mE.inicializa(area, l0);
		tF.inicializa(cp, d);
		tC.inicializa(peso0, tI, dens, s);
		cout << "Fazendo calculos...\n\n";
		mE.Calculo(N, L, T);
		tF.Calculo(N, T, mE.getMD());
		tC.Calculo(peso1, T);
		break;

	case(3) :
		exit(0);
	default:
		cout << "Entrada invalida! Programa encerrado.";
	}
#ifdef WIN32
	system("pause");
#endif
	return 0;
}
