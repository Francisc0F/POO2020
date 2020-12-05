#include "Imperio.h"
#include "Territorio.h"

using namespace std;

int Imperio::turnos = 1;

Imperio::Imperio() {

}

int Imperio::pesquisaTerritorio(string nome) {

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
		cout << "Nao foi possivel conquistar territorio." << endl;
	}
	
}


Imperio::~Imperio() {

}


