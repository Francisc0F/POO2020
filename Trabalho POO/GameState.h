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
	GameState();
	//getters
	string getNome();
};

