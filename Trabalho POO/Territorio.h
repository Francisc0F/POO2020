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
	Territorio(); //= delete;
	
	Territorio(string nome, int resistencia, int nProdutos, int pontos);

	
	//getters
	string getNome()const;
	int getnProdutos()const;
	int getnOuro()const;
	int getpontos()const;
	string getAsString() const;

	//setters
	void setnProdutos(int n);
	void setnOuro(int n);
	void setpontos(int n);



};

