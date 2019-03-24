//Control i l�gica del mapa

#include <iostream>
#include <fstream>
#include "Map.h"
#include "Player.h"

Map::Map() 
{
	
	char character;
	

	std::ifstream myFile("config.txt");
	if (myFile.is_open())
	{
		myFile >> rows;
		myFile >> columns;

		tablero = new char*[rows]; //Reservando memoria para cada Fila y cada una de las filas apuntara (variable puntero) a su vez a un sitio

		for (int i = 0; i <= rows; i++)
		{
			tablero[i] = new char[columns]; //Rservando memoria para cada Columna
			//la Fila tiene puntero porque apunta hacia las columnas (no tienen puntero)
			myFile.getline(tablero[i], columns + 1);
		}
	
		myFile.close();
	}
	
} // c�digo que lee el archivo CONFIG.TXT (SE ENCUENTRA DENTRO DE LA CARPETA PACMAN)




void Map::mostrarTablero() //funcion para mostrar la matriz, a la que le pasamos los parametros de la matriz
{
	for (int i = 0; i <= rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << tablero [i][j];

			if (j == columns - 1)
			{
				std::cout << '\n';
			}//Esto es lo mismo que decir con punteros
			////el *(tablero+i) se�ala a la fila y le a�adimos *(....+j) para que se�ale la columna
		}
	}
}

//LOS NOMBERS DE LAS FUNCIONES DEBERIAN IR AL HEADER
//#pragma region COMPROBAR MOVIMIENTO
//bool Map::checkMovement(player &player1, Movement move) //FUNCI�N PARA VERIFICAR QUE SEA POSIBLE EL MOVIMIENTO DEL JUGADOR Y LO REALICE
//{
//	switch (move)
//	{
//	case Movement::UP:
//		player1.positionY++;
//		if (tablero[player1.positionX][player1.positionY] != 'X')
//		{
//			player1.setPos(player1.positionX, player1.positionY);
//			player1.updateScore(1);
//			return true;
//		}
//		else
//		{
//			player1.setPos(player1.positionX, player1.positionY--);
//			return false;
//		}
//		break;
//	case Movement::DOWN:
//		player1.positionY--;
//		if (tablero[player1.positionX][player1.positionY] != 'X')
//		{
//			player1.setPos(player1.positionX, player1.positionY);
//			player1.updateScore(1);
//			return true;
//		}
//		else
//		{
//			player1.setPos(player1.positionX, player1.positionY++);
//			return false;
//		}
//		break;
//	case Movement::LEFT:
//		player1.positionX--;
//		if (tablero[player1.positionX][player1.positionY] != 'X')
//		{
//			player1.setPos(player1.positionX, player1.positionY);
//			player1.updateScore(1);
//			return true;
//		}
//		else
//		{
//			player1.setPos(player1.positionX++, player1.positionY);
//			return false;
//		}
//		break;
//	case Movement::RIGHT:
//		player1.positionX++;
//		if (tablero[player1.positionX][player1.positionY] != 'X')
//		{
//			player1.setPos(player1.positionX, player1.positionY);
//			player1.updateScore(1);
//			return true;
//		}
//		else
//		{
//			player1.setPos(player1.positionX--, player1.positionY);
//			return false;
//		}
//		break;
//	default:
//		return 0;
//	}
//}
//#pragma endregion
//
//#pragma region CONTAR SI HAY *
//bool Map::existCoin(player &player1, Movement move) //FUNCI�N PARA VERIFICAR SI EL SIGUIENTE MOVIMIENTO ES UNA MONEDA
//{
//	switch (move)
//	{
//	case Movement::UP:
//	case Movement::DOWN:
//	case Movement::LEFT:
//	case Movement::RIGHT:
//		if (tablero[player1.positionX][player1.positionY] == '*')
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//		break;
//	default:
//		break;
//	}
//}
//#pragma endregion
//
//#pragma region COLOCAR AL PLAYER EN EL TABLERO
//void Map::setPlayer(player &player1)
//{
//	player1.positionX = 4; //DETERMINAR DONDE COLOCARLO?
//	player1.positionY = 5;
//}
//#pragma endregion
//
//#pragma region MOVER PLAYER
//void Map::movePlayer(player & player1, Movement newmovement) //FUNCI�N PARA MOVER EL PERSONAJE EN EL TABLERO Y ESTE ESTAR REPRESENTADO
//{
//	if (checkMovement(player1, newmovement))
//	{
//		tablero[player1.positionX][player1.positionY] = '<';
//	}
//}
//#pragma endregion 

