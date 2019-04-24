#pragma once
#include <iostream>
#include "Player.h"
#include "Types.h"
#include <ctime>

class Enemies {
private:
	//struct blinky {
	//	int posX;
	//	int posY;
	//};
	//struct inky {
	//	int posX;
	//	int posY;
	//};
	//struct clyde {
	//	int posX;
	//	int posY;
	//};
	int posXInky;
	int posYInky;

	Enemies();
public:
	void setEnemies(int _posXInky, int _posYInky); //De momento vamos a leer solo a INKY e iniciaR SOLO A INKY
};