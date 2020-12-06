#include "Imperio.h"
#include "Territorio.h"

using namespace std;

int Imperio::turnos = 1;

Imperio::Imperio( Territorio * inicial) {
	conquistados.push_back(inicial);
}

void Imperio::listaConquistados()  {
	vector<Territorio* >::iterator ptr;
	ptr = conquistados.begin();
	if (conquistados.empty()) {
		cout << "Ainda nao foram conquistados Territorios." << endl;
		return;
	}
	for (ptr = conquistados.begin(); ptr < conquistados.end(); ptr++) {
		cout << (*ptr)->getAsString() << endl;
	}
}

int Imperio::pesquisaTerritorio(string nome)const {

	for (unsigned int i = 0; i < conquistados.size(); i++) {
		if (conquistados[i]->getNome() == nome) {
			return i;
		}
	}
	return -1;
}

void Imperio::conquistaTerritorio(Territorio * t) {
	if (pesquisaTerritorio(t->getNome()) == -1) {
		conquistados.push_back(t);
		cout << "Territorio \"" << t->getNome() <<  "\" conquistado." << endl;
	}
	else {
		cout << "Este territorio ja foi conquistado." << endl;
	}
}


Imperio::~Imperio() {
	conquistados.clear();
}


