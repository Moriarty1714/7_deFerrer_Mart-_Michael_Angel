#pragma once
#include <iostream>
#include "Player.h"
#include "Types.h"
#include <ctime>

class Enemies {
public:

	struct blinky {
		int posX;
		int posY;
	}blinky; //per accedir a la posició del personatge
	struct inky {
		int posX;
		int posY;
	}inky;	//per accedir a la posició del personatge
	struct clyde {
		int posX;
		int posY;
	}clyde;	//per accedir a la posició del personatge
	

	Enemies();

	void setPosEnemies(int _posX, int _posY); //De momento vamos a leer solo a INKY e iniciaR SOLO A INKY
};