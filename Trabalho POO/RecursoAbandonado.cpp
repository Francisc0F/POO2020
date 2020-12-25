#include <sstream>
#include <string>
#include "RecursoAbandonado.h"

using namespace std;

RecursoAbandonado::RecursoAbandonado() {

}

string RecursoAbandonado::getDescricao()const {
	ostringstream oss;
	oss << "um recurso abandonado foi encontrado e fornece ao império" <<
		"uma unidade de produtos ou de ouro conforme for encontrado no primeiro ano do" << 
		"jogo(produto) ou no segundo(ouro). ";
	return oss.str();
}

tipoEvento RecursoAbandonado::getType()const {
	return tipoEvento::RecursoAbandonado;
}