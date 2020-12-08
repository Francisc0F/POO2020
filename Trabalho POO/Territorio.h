#pragma once

#include <string>
#include <iostream>

using namespace std;

class Territorio
{
	string nome;
	int resistencia;

	int nProdutos;
	int nOuro;

	int pontos;
	static int numTerr;

public:

	Territorio(string nome = "Sem nome", int resistencia = ((rand() % 6) + 1), int nProdutos = 0, int nOuro = 0, int pontos = 0);

	//getters
	string getNome()const;
	int getnProdutos()const;
	int getnOuro()const;
	int getpontos()const;
	int getResistencia()const;
	string getAsString() const;

	//setters
	void setnProdutos(int n);
	void setResistencia(int n);
	void setnOuro(int n);
	void setpontos(int n);



};

