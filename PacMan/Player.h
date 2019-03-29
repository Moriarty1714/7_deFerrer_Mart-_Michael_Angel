#pragma once
#include <iostream>
#include "Types.h"


struct player
{
	int positionX;
	int positionY;
	int score = 0;

	void setPos(int newpositionX, int newpositionY); //FUNCIÓN PARA PONER LA POSICION DEL JUGADOR

	void updateScore(int points); //FUNCIÓN PARA AUMENTAR LA PUTUACIÓN DEL JUGADOR

	void printScore();
};