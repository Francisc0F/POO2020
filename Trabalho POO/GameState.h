#pragma once
#include "Imperio.h"
#include "Mundo.h"
#include "Menu.h"
class GameState
{
	string nome;

	int turno;
	int ano;
	Mundo  mundo;
	faseTurno faseAtual;
	Imperio imperio;


public:
	GameState(string nome, faseTurno fase, int anos, int turnos, Mundo mundo, Imperio imperio);
	//getters
	string getNome();

	int getTurno();

	int getAno();
	
	//Mundo& getMundo();
	//
	//Imperio& getImperio();
	
	faseTurno getfaseAtual();


	string mostraGravacao();

};


ostream& operator<<(ostream& os, GameState& i);

ostream& operator<<(ostream& os, GameState* i);
