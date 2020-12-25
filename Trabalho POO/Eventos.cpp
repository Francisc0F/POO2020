#include "Eventos.h"

tipoEvento Eventos::validaEvento(string n) {
	if (n == "alianca") {
		return tipoEvento::Alianca;
	}
	else if (n == "invasao") {
		return tipoEvento::Invasao;
	}
	else if (n == "recurso") {
		return tipoEvento::RecursoAbandonado;
	}
	else {
		return tipoEvento::Invalido;
	}
}