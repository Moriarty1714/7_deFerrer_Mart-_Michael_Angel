//Control i lògica del mapa

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
	
} // código que lee el archivo CONFIG.TXT (SE ENCUENTRA DENTRO DE LA CARPETA PACMAN)




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
			////el *(tablero+i) señala a la fila y le añadimos *(....+j) para que señale la columna
		}
	}
}


//bool checkMovement(player &player1, Movement move) //FUNCIÓN PARA VERIFICAR QUE SEA POSIBLE EL MOVIMIENTO DEL JUGADOR Y LO REALICE
//{
//	switch (move)
//	{
//	case Movement::UP:
//		player1.positionY++;
//		if (board[player1.positionX][player1.positionY] != Cell::STONE)
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
//		if (board[player1.positionX][player1.positionY] != Cell::STONE)
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
//		if (board[player1.positionX][player1.positionY] != Cell::STONE)
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
//		if (board[player1.positionX][player1.positionY] != Cell::STONE)
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

