//Control i lògica del mapa

#include <iostream>
#include <fstream>
#include "Map.h"
#include "Player.h"
#include <Windows.h>

Map::Map()
{

	char character;

	char **cTablero; //Creo una array dinàmica para guardar el char

	char separador;

	std::ifstream myFile("config.txt");
	if (myFile.is_open())
	{
		myFile >> rows;
		myFile >> separador; //para coger el char de ';' (separa ambos números)
		myFile >> columns;
		myFile >> separador;

		cTablero = new char*[rows]; //Reservando memoria para cada Fila y cada una de las filas apuntara (variable puntero) a su vez a un sitio

		for (int i = 0; i <= rows; i++)
		{
			cTablero[i] = new char[columns]; //Rservando memoria para cada Columna
			//la Fila tiene puntero porque apunta hacia las columnas (no tienen puntero)
			myFile.getline(cTablero[i], columns + 1);
		}
		myFile.close();

		//Convertir los chars en Cell
		tablero = new Cell *[rows];
		for (int i = 0; i <= rows; i++)
		{
			tablero[i] = new Cell[columns]; //Rservando memoria para cada Columna
		}


		for (int i = 0; i <= rows; i++)
		{
			for (int j = 0; j <= columns; j++)
			{
				switch (cTablero[i][j]) {
				case 'X': {
					tablero[i][j] = Cell::STONE;
					break;
				}
				case '*': {
					tablero[i][j] = Cell::COINS;
					break;
				}
				case '<': {
					tablero[i][j] = Cell::PLAYER;
					break;
				}
				default:
				{
					tablero[i][j] = Cell::NOTHING;
					break;
				}
				}
			}
		}

	}
}// código que lee el archivo CONFIG.TXT (SE ENCUENTRA DENTRO DE LA CARPETA PACMAN)




void Map::mostrarTablero() //funcion para mostrar la matriz, a la que le pasamos los parametros de la matriz
{
	for (int i = 0; i <= rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (tablero[i][j]==Cell::STONE) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 17); //Da color azul a las piedras
				std::cout << (char)tablero[i][j];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Volver al color estándar
			}
			else if (tablero[i][j] == Cell::PLAYER) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); //Da color amarillo al jugador
				std::cout << (char)tablero[i][j];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Volver al color estándar
			}
			else {
				std::cout << (char)tablero[i][j];
			}

			if (j == columns - 1)
			{
				std::cout << '\n';
			}//Esto es lo mismo que decir con punteros
			////el *(tablero+i) señala a la fila y le añadimos *(....+j) para que señale la columna
		}
	}
}


bool Map::checkMovement(player &player1, Movement move) //FUNCIÓN PARA VERIFICAR QUE SEA POSIBLE EL MOVIMIENTO DEL JUGADOR Y LO REALICE
{
	tablero[player1.positionX][player1.positionY] = Cell::NOTHING;	//Convierte la casilla donde estava en nada
	switch (move)
	{
	case Movement::RIGHT:
		player1.positionY++;
		if (tablero[player1.positionX][player1.positionY] != Cell::STONE)
		{
			if (player1.positionY > columns-1)
			{
				player1.positionY = 0;
				if (tablero[player1.positionX][player1.positionY] == Cell::STONE)
				{
					player1.positionY = columns-1;
				}
			}
			player1.setPos(player1.positionX, player1.positionY);
			existCoin(player1, move)? player1.updateScore(1): player1.updateScore(0);
			return true;
		}
		else
		{
			player1.positionY--;
			tablero[player1.positionX][player1.positionY] = Cell::PLAYER; //Poner otra vez el player en la posicion que estava
			return false;
		}
		break;
	case Movement::LEFT:
		player1.positionY--;
		if (tablero[player1.positionX][player1.positionY] != Cell::STONE)
		{
			if (player1.positionY < 0)
			{
				player1.positionY = columns-1;
				if (tablero[player1.positionX][player1.positionY] == Cell::STONE)
				{
					player1.positionY = 0;
				}
			}
			player1.setPos(player1.positionX, player1.positionY);
			existCoin(player1, move) ? player1.updateScore(1) : player1.updateScore(0);
			return true;
		}
		else
		{
			player1.positionY++;
			player1.setPos(player1.positionX, player1.positionY);
			tablero[player1.positionX][player1.positionY] = Cell::PLAYER; //Poner otra vez el player en la posicion que estava
			return false;
		}
		break;
	case Movement::UP:
		player1.positionX--;
		if (tablero[player1.positionX][player1.positionY] != Cell::STONE)//NOS DA UN ERROR ......
		{
			if (player1.positionX < 0)
			{
				player1.positionX = rows - 1;
				if (tablero[player1.positionX][player1.positionY] == Cell::STONE)
				{
					player1.positionX = 0;
				}
			}
			player1.setPos(player1.positionX, player1.positionY);
			existCoin(player1, move) ? player1.updateScore(1) : player1.updateScore(0);
			return true;
		}
		else
		{
			player1.positionX++;
			player1.setPos(player1.positionX, player1.positionY);
			tablero[player1.positionX][player1.positionY] = Cell::PLAYER; //Poner otra vez el player en la posicion que estava
			return false;
		}
		break;
	case Movement::DOWN:
		player1.positionX++;
		if (tablero[player1.positionX][player1.positionY] != Cell::STONE)
		{
			if (player1.positionX > rows-1)
			{
				player1.positionX = 0;
				if (tablero[player1.positionX][player1.positionY] == Cell::STONE)
				{
					player1.positionX = rows-1;
				}
			}
			player1.setPos(player1.positionX, player1.positionY);
			existCoin(player1, move) ? player1.updateScore(1) : player1.updateScore(0);
			return true;
		}
		else
		{
			player1.positionX--;
			player1.setPos(player1.positionX, player1.positionY);
			tablero[player1.positionX][player1.positionY] = Cell::PLAYER; //Poner otra vez el player en la posicion que estava
			return false;
		}
		break;
	default:
		return false;
	}
}

//CONTAR SI HAY * para sumar puntuación
bool Map::existCoin(player &player1, Movement move) //FUNCIÓN PARA VERIFICAR SI EL SIGUIENTE MOVIMIENTO ES UNA MONEDA
{
	switch (move)
	{
	case Movement::UP:
	case Movement::DOWN:
	case Movement::LEFT:
	case Movement::RIGHT:
		if (tablero[player1.positionX][player1.positionY] == Cell::COINS)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	default:
		break;
	}
}

void Map::setPlayer(player &player1)
{
	player1.positionX = 4; //DETERMINA POSICION INICIAL PLAYER
	player1.positionY = 5;
	tablero[player1.positionX][player1.positionY] = Cell::PLAYER;
}


void Map::movePlayer(player &player1, Movement newmovement) //FUNCIÓN PARA MOVER EL PERSONAJE EN EL TABLERO Y ESTE ESTAR REPRESENTADO
{
	if (newmovement==Movement::NOTHING){}
	
	else {
		if (checkMovement(player1, newmovement))
		{
			tablero[player1.positionX][player1.positionY] = Cell::PLAYER;
		}
	}
	
}

void Map::gameState(GameStates _gameState)
{
	if (_gameState == GameStates::INIT)
	{
		std::cout << "*-*- INIT -*-*";
	}
	else if (_gameState == GameStates::PLAY)
	{
		std::cout << "*-*- PLAY -*-*";

	}
	else if (_gameState == GameStates::PAUSE)
	{
		std::cout << "*-*- PAUSE -*-*";
	}
	else if (_gameState == GameStates::GAMEOVER)
	{
		std::cout << "*-*- GAMEOVER -*-*";
	}
}
