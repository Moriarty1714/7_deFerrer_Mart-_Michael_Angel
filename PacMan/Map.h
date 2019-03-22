#pragma once
#include <iostream>
#include "Player.h"
#include <ctime>

enum class Cell { STONE = '#', COINS = '$', NOTHING = ' ', PLAYER = '@' };

struct Map
{
	//Cell **tablero  ---> PODRÍA SER ASÍ
	char **tablero; //dos punteros señalan a una matriz!
	int rows;
	int columns;

	Map(); //CONSTRUCTOR del mapa 

	void mostrarTablero(); //funcion paa mostrar la matriz, a la que le pasamos los parametros de la matriz

//#pragma region COMPROBAR MOVIMIENTO
//	bool checkMovement(player &player1, Movement move) //FUNCIÓN PARA VERIFICAR QUE SEA POSIBLE EL MOVIMIENTO DEL JUGADOR Y LO REALICE
//	{
//		switch (move)
//		{
//		case Movement::UP:
//			player1.positionY++;
//			if (board[player1.positionX][player1.positionY] != Cell::STONE)
//			{
//				player1.setPos(player1.positionX, player1.positionY);
//				player1.updateScore(1);
//				return true;
//			}
//			else
//			{
//				player1.setPos(player1.positionX, player1.positionY--);
//				return false;
//			}
//			break;
//		case Movement::DOWN:
//			player1.positionY--;
//			if (board[player1.positionX][player1.positionY] != Cell::STONE)
//			{
//				player1.setPos(player1.positionX, player1.positionY);
//				player1.updateScore(1);
//				return true;
//			}
//			else
//			{
//				player1.setPos(player1.positionX, player1.positionY++);
//				return false;
//			}
//			break;
//		case Movement::LEFT:
//			player1.positionX--;
//			if (board[player1.positionX][player1.positionY] != Cell::STONE)
//			{
//				player1.setPos(player1.positionX, player1.positionY);
//				player1.updateScore(1);
//				return true;
//			}
//			else
//			{
//				player1.setPos(player1.positionX++, player1.positionY);
//				return false;
//			}
//			break;
//		case Movement::RIGHT:
//			player1.positionX++;
//			if (board[player1.positionX][player1.positionY] != Cell::STONE)
//			{
//				player1.setPos(player1.positionX, player1.positionY);
//				player1.updateScore(1);
//				return true;
//			}
//			else
//			{
//				player1.setPos(player1.positionX--, player1.positionY);
//				return false;
//			}
//			break;
//		default:
//			return 0;
//		}
//	}
//#pragma endregion
};