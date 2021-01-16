#pragma once

#include <vector>
#include "Mundo.h"
using namespace std;

enum class menuOpt {
	CarregaComand = 0,
	CarregaFich,
	Cria,
	Conquista,
	Passa, 
	Lista, 
	Terminar,
	MaisProd,
	MaisOuro,
	MaisMilitar,
	AdquireTec,
	
	TomaTerr,
	TomaTec,
	ModificaOuro,
	ModificaProd,

	ForcaEvento,

	Grava,
	Ativa,
	Apaga,

	ListaGravacoes,

	Avanca,
	Invalido
};

enum class faseTurno {
	Config,
	Conquistar,
	Recolha,
	Comprar,
	Eventos
};

class Menu
{
	
public:
	static string mode;
	Menu();

	Menu(string mode);
	// comandos
	bool static isModeTest();

	menuOpt static RecebeComandosJogo(vector<string> & values, faseTurno fase,Imperio I,  int turno, int ano);

	menuOpt static ProcessaComando(vector<string>& values, faseTurno fase, vector<string>& comand_tokens);

	menuOpt static ComandosConfig(vector<string>& values);

	bool static isDebugComand(menuOpt cmd);
};

