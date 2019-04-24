#pragma once
#include <iostream>
#include "Player.h"
#include "Types.h"
#include "Enemies.h"
#include <ctime>


struct Map
{
	Cell **board; // ---> PODRÍA SER ASÍ
	 //dos punteros señalan a una matriz!
	int rows;
	int columns;



	Map(); //CONSTRUCTOR del mapa 

	void mostrarTablero(); //funcion paa mostrar la matriz, a la que le pasamos los parametros de la matriz


	bool checkMovement(player &player1, Movement move); //FUNCIÓN PARA VERIFICAR QUE SEA POSIBLE EL MOVIMIENTO DEL JUGADOR Y LO REALICE
	bool existCoin(player &player1, Movement move); //FUNCIÓN PARA VERIFICAR SI EL SIGUIENTE MOVIMIENTO ES UNA MONEDA
	void setPlayer(player &player1);
	void movePlayer(player & player1, Movement newmovement); //FUNCIÓN PARA MOVER EL PERSONAJE EN EL TABLERO Y ESTE ESTAR REPRESENTADO
	void gameState(GameStates _gameState); //FUNCIÓN PARA TENER EL CONTROL DE LOS ESTDOS DEL JUEGO

	void setEnemiesInky(Enemies &Inky, int _posXInky, int _posYInky); //INICIA INKY de momento
};