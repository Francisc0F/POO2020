#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <limits>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

class Territorio;

class Imperio
{
	int armazem,capacidadeMaxArmazem;
	int cofre, capacidadeMaxCofre;
	int exercito, capacidadeMaxExercito;

	static int turnos;

	vector<Territorio *> conquistados;

public:
	Imperio();

	void conquistaTerritorio(Territorio * t);

	int pesquisaTerritorio(string nome);

	~Imperio();
};

