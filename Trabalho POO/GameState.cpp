#include <string>
#include "GameState.h"

GameState::GameState(string nome, faseTurno fase, int anos, int turnos, Mundo mundo, Imperio imperio)
	:mundo(mundo), imperio(imperio), nome(nome), faseAtual(fase), ano(anos), turno(turnos){

	this->imperio.getConquistados().clear();
	for (size_t i = 0; i < imperio.getConquistados().size(); i++)
	{
		for (size_t j = 0; j < this->mundo.getTerritorios().size(); j++)
		{
			if (imperio.getConquistados()[i]->getNome() == this->mundo.getTerritorios()[j]->getNome()) {
				this->imperio.addT(this->mundo.getTerritorios()[j]);
			}
		}
	}
	
}

string GameState::mostraGravacao() {
	ostringstream oss;
	oss << "----------------------------------------- GRAVACAO: "<< nome << endl
	<<  //mundo << 
		imperio <<
		   "-----------------------------------------   FIM   " << endl;
	return oss.str();
}

ostream& operator<< (ostream& os, GameState& i) {
	return os << i.mostraGravacao();
}

ostream& operator<< (ostream& os, GameState* i) {
	return os << i->mostraGravacao();
}


// getters
string GameState::getNome() {
	return nome;
}
int GameState::getTurno() {
	return turno;
}
int GameState::getAno() {
	return ano;
}
Mundo GameState::getMundo() {
	return mundo;
}

Imperio GameState::getImperio() {
	return imperio;
}

faseTurno GameState::getfaseAtual() {
	return faseAtual;
}