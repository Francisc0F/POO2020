#pragma once
#include <string>
using namespace std;
enum class tipoEvento {
	RecursoAbandonado,
	Invasao,
	Alianca,
	Nenhum,
	Invalido
};

class Eventos
{
public:
	virtual tipoEvento getType()const = 0;

	static tipoEvento validaEvento(string n);

	virtual string getDescricao()const = 0;
};

