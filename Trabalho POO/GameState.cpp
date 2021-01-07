#include <string>
#include "GameState.h"

GameState::GameState(string nome, faseTurno fase, int anos, int turnos, Mundo* mundo, Imperio* imperio)
	:nome(nome), faseAtual(fase), ano(anos), turno(turnos){

	
	//if()
	/*for (size_t i = 0; i < mundo.getTerritorios().size(); i++)
	{
		this->mundo.adicionarTerritorio(Mundo::copiaTerritorio(mundo.getTerritorios()[i]));
	}*/

	//this->imperio = Imperio(this->mundo.getTerritorios()[0], imperio.getProdutos(), imperio.getCofre());

	//for (size_t i = 0; i < imperio.getConquistados().size(); i++)
	//{
	//	for (size_t j = 0; j < this->mundo.getTerritorios().size(); j++)
	//	{
	//		if (imperio.getConquistados()[i]->getNome() == this->mundo.getTerritorios()[j]->getNome()) {
	//			this->imperio.addT(this->mundo.getTerritorios()[j]);
	//		}
	//	}
	//}
	
}

void GameState::mostraGravacao() {
	cout << "GRAVACAO ------------------" << endl;
	mundo->listaTerritorios();
	//imperio.listaConquistados();
	cout << "FIM -----------------------" << endl;
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
//Mundo& GameState::getMundo() {
//	return mundo;
//}
//
//Imperio& GameState::getImperio() {
//	return imperio;
//}

faseTurno GameState::getfaseAtual() {
	return faseAtual;
}