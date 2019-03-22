#pragma once
#include <iostream>
enum class Movement { UP, DOWN, LEFT, RIGHT }; //ENUM CLASS DEL MOVIMIENTO POSIBLE

struct player
{
	int positionX;
	int positionY;
	int score = 0;

	void setPos(int newpositionX, int newpositionY); //FUNCIÓN PARA PONER LA POSICION DEL JUGADOR

	void updateScore(int points); //FUNCIÓN PARA AUMENTAR LA PUTUACIÓN DEL JUGADOR

};