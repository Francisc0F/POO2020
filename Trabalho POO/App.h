#pragma once

#include "Mundo.h"
#include "Imperio.h"
#include "Territorio.h"
#include "GameState.h"
#include "Eventos.h"
#include "Menu.h"
class App
{
	int turnos;
	int anos;



	static vector<Tecnologias*> CreateTecnoList();
	static vector<Tecnologias* > tecnologias;

	static vector<Eventos*> CreateEventosList();
	static vector<Eventos* > eventos;

	vector<GameState*> saves;

	faseTurno faseAtual;
	Menu menu;
	Mundo mundo;
	Imperio imperio;

public:

	const static bool debugMode;

	App(string mode);

	void Jogo();

	void LoadGameState(GameState * state);

	menuOpt FaseRecolha(vector<string>& values, int  turno);

	void RecolherRecursoDoImperio();

	void AtualizarProducoes();

	void ConfigMundo();

	void FaseSeguinte(int* fase);

	void  TurnoSeguinte();

	void Carrega(string fich);

	void GerarEvento(string & evento);

	static Tecnologias* getTec(tec t);

	int getTurno();

	int getAno();

	bool ExecutaComando(menuOpt opt, vector<string>& menuValues);

	bool LerComandosFich(string nomef);
	// eventos
	void EventoAlianca();
	
	void EventoInvasao(string& info);

	void EventoRecursoAbandonado();

	int ValidaGravacao(string nome);

	int calculaPontuacaoFinal(bool * bonusCientifico, bool * bonusImperadorSupremo);

	string RelatorioFinal(bool ganhou);
};