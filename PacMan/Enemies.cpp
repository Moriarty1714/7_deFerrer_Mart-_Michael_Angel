#include <iostream>
#include <fstream>
#include "Map.h"
#include "Player.h"
#include "Enemies.h"
#include <Windows.h>

Enemies::Enemies () {
}

void Enemies::setPosEnemies(int _posX, int _posY){
	inky.posX = _posX;
	inky.posY = _posY;
}

