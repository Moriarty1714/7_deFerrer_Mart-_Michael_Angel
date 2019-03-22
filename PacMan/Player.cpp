//Control i lògica del jugador

#include "Player.h"

void player::setPos(int newpositionX, int newpositionY) //FUNCIÓN PARA PONER LA POSICION DEL JUGADOR
{
	positionX = newpositionX;
	positionY = newpositionY;
}

void player::updateScore(int points) //FUNCIÓN PARA AUMENTAR LA PUTUACIÓN DEL JUGADOR
{
	score++;
}