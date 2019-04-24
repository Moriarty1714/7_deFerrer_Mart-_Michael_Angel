#include <iostream>
#include <fstream>
#include "Map.h"
#include "Player.h"
#include "Enemies.h"
#include <Windows.h>

Enemies::Enemies () {
}

void Enemies::setEnemies(int _posXInky, int _posYInky)
{
	posXInky = _posXInky;
	posYInky = _posYInky;
}

