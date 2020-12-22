#pragma once

#include <string>
#include <iostream>

using namespace std;

enum class tipoTerritorio {
	Inicial,

	Planicie,
	Montanha,
	Fortaleza,
	Mina,
	Duna,
	Castelo,

	Refugio,
	Pescaria,

	Invalido
};


class Territorio
{
protected:
	string nome;

	int resistencia;

	int nProdutos;

	int nOuro;

	int pontos;

public:

	//Territorio(string nome = "Sem nome", int resistencia = ((rand() % 6) + 1), int nProdutos = 0, int nOuro = 0, int pontos = 0);

	//getters
	string getNome()const;
	int getnProdutos()const;
	int getnOuro()const;
	virtual tipoTerritorio getType()const = 0;

	int getpontos()const;
	int getResistencia()const;
	string getAsString() const;

	//setters
	void setnProdutos(int n);
	void setResistencia(int n);
	void setnOuro(int n);
	void setpontos(int n);

	static Territorio* mapper(tipoTerritorio t);

	static tipoTerritorio  validaTipoTerritorio(string tipo);
};

