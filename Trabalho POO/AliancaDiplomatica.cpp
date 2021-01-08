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
	oss << "A for�a militar aumenta uma "
		 << "unidade, desde que n�o seja ultrapassado o m�ximo de unidades poss�veis no imp�rio.";
	return oss.str();
}
