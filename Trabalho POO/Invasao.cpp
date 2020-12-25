#include <string>
#include <sstream>

#include "Invasao.h"
using namespace std;


Invasao::Invasao() {

}
tipoEvento Invasao::getType()const {
	return tipoEvento::Invasao;
}


string Invasao::getDescricao()const {
	ostringstream oss;
	oss << "um recurso abandonado foi encontrado e fornece ao império" <<
		"uma unidade de produtos ou de ouro conforme for encontrado no primeiro ano do" <<
		"jogo(produto) ou no segundo(ouro). ";
	return oss.str();
}