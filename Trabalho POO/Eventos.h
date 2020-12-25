#pragma once
#include <string>
using namespace std;
enum class tipoEvento {
	RecursoAbandonado,
	Invasao,
	Alianca,
	Nenhum
};

class Eventos
{
public:
	virtual tipoEvento getType()const = 0;

	virtual string getDescricao()const = 0;
};

