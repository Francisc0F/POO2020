#include <string>
#include "GameState.h"

GameState::GameState(string nome, faseTurno fase, int anos, int turnos, Mundo mundo, Imperio imperio)
	:nome(nome), faseAtual(fase), ano(anos), turno(turnos){
	this->mundo = Mundo();
	this->imperio = Imperio();

	for (size_t i = 0; i < mundo.getTerritorios().size(); i++)
	{
		this->mundo.adicionarTerritorio(Mundo::copiaTerritorio(mundo.getTerritorios()[i]));
	}

}

string GameState::getNome() {
	return nome;
}