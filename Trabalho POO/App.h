#pragma once

#include "Mundo.h"
#include "Imperio.h"
#include "Territorio.h"
#include "Eventos.h"
#include "Menu.h"
class App
{
	static int turnos;
	static int anos;

	static bool debugMode;

	static vector<Tecnologias*> CreateTecnoList();
	static vector<Tecnologias* > tecnologias;

	static vector<Eventos*> CreateEventosList();
	static vector<Eventos* > eventos;

	faseTurno faseAtual;
	Menu menu;
	Mundo mundo;
	Imperio imperio;

public:
	App(string mode);

	App(Mundo& m, Imperio& I, Menu& menu);

	void Jogo();

	menuOpt FaseRecolha(vector<string>& values, int  turno);

	void RecolherRecursoDoImperio();

	void AtualizarProducoes();

	void ConfigMundo();

	void FaseSeguinte(int* fase);

	void  TurnoSeguinte();

	void Carrega(string fich);

	void GerarEvento();

	static Tecnologias* getTec(tec t);

	static int getTurno();

	static int getAno();
};

