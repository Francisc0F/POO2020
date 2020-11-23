#pragma once

#include <string>
#include <iostream>
class Territorio
{
	std::string nome;
	int resistencia;
	
	int nProdutos;
	int nOuro;
	int pontos;

	static int numTerr;

public:
	Territorio(); //= delete;
	
	Territorio(string nome, int resistencia, int nProdutos, int pontos);

	std::string getAsString() const;
	
	//getters
	string getNome()const;
	int getnProdutos()const;
	int getnOuro()const;
	int getpontos()const;

	//setters
	void setnProdutos(int n);
	void setnOuro(int n);
	void setpontos(int n);


	int LerFich(FILE* fp);

};

