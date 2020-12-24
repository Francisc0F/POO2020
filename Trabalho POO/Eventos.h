#pragma once
enum class tipoEvento {
	RecursoAbandonado,
	Invasao,
	Alianca,
	Nenhum
};

class Eventos
{
	Eventos();
	virtual tipoEvento getType()const = 0;
};

