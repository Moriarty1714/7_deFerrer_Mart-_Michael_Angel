#pragma once
#include <iostream>
enum class Movement { UP, DOWN, LEFT, RIGHT }; //ENUM CLASS DEL MOVIMIENTO POSIBLE

struct player
{
	int positionX;
	int positionY;
	int score = 0;

	void setPos(int newpositionX, int newpositionY); //FUNCI�N PARA PONER LA POSICION DEL JUGADOR

	void updateScore(int points); //FUNCI�N PARA AUMENTAR LA PUTUACI�N DEL JUGADOR

};