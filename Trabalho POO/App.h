#pragma once

#include "Mundo.h"
#include "Imperio.h"
#include "Territorio.h"
#include "Menu.h"
class App
{
	static int turnos;
	faseTurno faseAtual;
	Menu menu;
	Mundo mundo;
	Imperio imperio;

public :
	App();

	App(Mundo& m, Imperio& I, Menu & menu);

	void Jogo();

	menuOpt FaseRecolha(vector<string>& values, int  turno);

	void RecolherRecursoDoImperio();

	void ConfigMundo();

	void Carrega(string fich);
};

