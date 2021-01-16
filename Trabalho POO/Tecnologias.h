#pragma once
#include <string>
#include <sstream>
using namespace std;

enum class tec {
	MisseisTeleguiados = 0,
	DronesMilitares,
	DefesasTerritoriais,
	BolsaDeValores,
	BancoCentral,
	Invalida,
};

class Tecnologias
{
protected:
	int custo;
public:
	virtual tec getType()const = 0;

	virtual string getDescricao()const = 0;

	tec static tecValida(string n);

	int getCusto()const;

	string getCustoAsString()const;

};
