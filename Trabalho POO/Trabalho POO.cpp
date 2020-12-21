// Trabalho POO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <limits>
#include <sstream>
#include <ctime>
#include <fstream>
#include <limits>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
#include "App.h"



using namespace std;

int main(){
	App jogo = App();
	jogo.Carrega("config3.txt");
	jogo.ConfigMundo();
	jogo.Jogo();


}
