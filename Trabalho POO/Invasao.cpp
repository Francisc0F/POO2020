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
	oss << "um qualquer outro imp�rio concorrente, do qual nem sequer existe qualquer" << endl 
		<<  "registo, est� a tentar conquistar um dos territ�rios do jogador.";
	return oss.str();
}