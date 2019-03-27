//Control i l�gica del jugador

#include "Player.h"


void player::setPos(int newpositionX, int newpositionY) //FUNCI�N PARA PONER LA POSICION DEL JUGADOR
{
	positionX = newpositionX;
	positionY = newpositionY;
}

void player::updateScore(int points) //FUNCI�N PARA AUMENTAR LA PUTUACI�N DEL JUGADOR CON LA PUNTUACION QUE QUERAMOS
{
	score = score + points;
}

void player::printScore()	//Funcion para printar el Score
{
	std::cout << score << "\n";
}