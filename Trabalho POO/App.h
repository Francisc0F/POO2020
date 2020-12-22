#pragma once

#include "Mundo.h"
#include "Imperio.h"
#include "Territorio.h"
#include "Menu.h"
class App
{
	static int turnos;
	static int anos;
	faseTurno faseAtual;
	Menu menu;
	Mundo mundo;
	Imperio imperio;
	vector<Tecnologias* > tecnologias;

public :
	App();

	App(Mundo& m, Imperio& I, Menu & menu);

	void Jogo();

	menuOpt FaseRecolha(vector<string>& values, int  turno);

	void RecolherRecursoDoImperio();

	void AtualizarProducoes();

	void ConfigMundo();

	void FaseSeguinte(int * fase);

	void Carrega(string fich);

	static int getTurno();

	static int getAno();
};

