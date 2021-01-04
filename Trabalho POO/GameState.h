#pragma once
#include "Imperio.h"
#include "Mundo.h"
#include "Menu.h"
class GameState
{
	string nome;

	int turno;
	int ano;
	Mundo mundo;
	faseTurno faseAtual;
	Imperio imperio;


public:
	GameState(string nome, faseTurno fase, int anos, int turnos, Mundo mundo, Imperio imperio);
	//getters
	string getNome();
};

