#include <string>
#include <sstream>
#include "AliancaDiplomatica.h"

using namespace std;
AliancaDiplomatica::AliancaDiplomatica() {

}

tipoEvento AliancaDiplomatica::getType()const {
	return tipoEvento::Alianca;
}

string AliancaDiplomatica::getDescricao() const{
	ostringstream oss;
	oss << "A força militar aumenta uma "
		 << "unidade, desde que não seja ultrapassado o máximo de unidades possíveis no império.";
	return oss.str();
}
