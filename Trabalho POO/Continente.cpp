#pragma once
#include <string>
#include "Continente.h"
using namespace std;

Continente::Continente() {
	pontos = 1;
}


categoria Continente::getCategoria()const {
	return categoria::Continente;
}