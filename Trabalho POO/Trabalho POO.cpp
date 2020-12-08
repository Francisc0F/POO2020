// Trabalho POO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <limits>
#include <sstream>
#include <fstream>
#include <limits>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
#include "Mundo.h"
#include "Menu.h"
#include "Territorio.h"
#include "Imperio.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main(){

	srand((unsigned)time(0));



	Mundo m = Mundo();

	Territorio* inicial = new Territorio("Pais", 9, 1, 1, 0);
	m.adicionarTerritorio(inicial);

	Imperio I = Imperio(inicial);
		
	

	int turno = 0;

	vector<string> menuValues;
	


	while (1) {
		menuOpt opt = Menu::verMenu(menuValues, turno);
		if (opt == menuOpt::Terminar) {
			break;
		}
		/*if (opt == menuOpt::Invalido) {
			cout << "apagar territorios" << endl;
			m.~Mundo();
			I.~Imperio();
		}*/
		if (opt != menuOpt::Invalido) {
			Menu::ExecutaComando(opt, menuValues, m, I, &turno);
		}
	}
	
}
