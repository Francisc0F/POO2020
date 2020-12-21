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
	AvancarTurno,
	AvancarFase,
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
	Menu();
	// comandos
	menuOpt static RecebeComandosJogo(vector<string> & values, faseTurno fase,Imperio I,  int turno);

	menuOpt static ProcessaComando(vector<string>& values, faseTurno fase, vector<string>& comand_tokens);

	bool static ExecutaComando(menuOpt opt, vector<string> & menuValues, Mundo & m, Imperio & I, int * turno);

	menuOpt static ComandosConfig(vector<string>& values);

	bool static isDebugComand(menuOpt cmd);
};

