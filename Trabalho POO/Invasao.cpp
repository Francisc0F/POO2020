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
	oss << "um qualquer outro império concorrente, do qual nem sequer existe qualquer" << endl 
		<<  "registo, está a tentar conquistar um dos territórios do jogador.";
	return oss.str();
}