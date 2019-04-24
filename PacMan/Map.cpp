//Control i lògica del mapa

#include <iostream>
#include <fstream>
#include "Map.h"
#include "Player.h"
#include "Enemies.h"
#include <Windows.h>

Map::Map()
{

	char character;

	char **cBoard; //Creo una array dinàmica para guardar el char

	char separador;

	std::ifstream myFile("config.txt");
	if (myFile.is_open())
	{
		myFile >> rows;
		myFile >> separador; //para coger el char de ';' (separa ambos números)
		myFile >> columns;
		myFile >> separador;

		cBoard = new char*[rows]; //Reservando memoria para cada Fila y cada una de las filas apuntara (variable puntero) a su vez a un sitio

		board = new Cell * [rows]; //Reservando memoria para cada Fila y cada una de las filas apuntara (variable puntero) a su vez a un sitio en el "board" principal

		for (int i = 0; i <= rows; i++)
		{
			cBoard[i] = new char[columns]; //Rservando memoria para cada Columna
			//la Fila tiene puntero porque apunta hacia las columnas (no tienen puntero)
			myFile.getline(cBoard[i], columns + 1);

			board[i] = new Cell[columns];  //Rservando memoria para cada Columna
		}
		myFile.close();

		//Convertir los chars en tipo Cell
		for (int i = 0; i <= rows; i++)
		{
			for (int j = 0; j <= columns; j++)
			{
				switch (cBoard[i][j]) {
				case 'X': {
					board[i][j] = Cell::STONE;
					break;
				}
				case '*': {
					board[i][j] = Cell::COINS;
					break;
				}
				case '<': {
					board[i][j] = Cell::PLAYER;
					break;
				}
				case '#': {
					board[i][j] = Cell::BLINKY;
					break;
				}
				case '&': {
					board[i][j] = Cell::INKY;
					break;
				}
				case '$': {
					board[i][j] = Cell::CLYDE;
					break;
				}
				case '0': {
					board[i][j] = Cell::POWERUP;
					break;
				}
				default:{
					board[i][j] = Cell::NOTHING;
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
			if (board[i][j]==Cell::STONE) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 17); //Da color azul a las piedras
				std::cout << (char)board[i][j];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Volver al color estándar
			}
			else if (board[i][j] == Cell::PLAYER) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); //Da color amarillo al jugador
				std::cout << (char)board[i][j];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Volver al color estándar
			}
			else {
				std::cout << (char)board[i][j];
			}

			if (j == columns - 1)
			{
				std::cout << '\n';
			}//Esto es lo mismo que decir con punteros
			////el *(board+i) señala a la fila y le añadimos *(....+j) para que señale la columna
		}
	}
}


bool Map::checkMovement(player &player1, Movement move) //FUNCIÓN PARA VERIFICAR QUE SEA POSIBLE EL MOVIMIENTO DEL JUGADOR Y LO REALICE
{
	board[player1.positionX][player1.positionY] = Cell::NOTHING;	//Convierte la casilla donde estava en nada
	switch (move)
	{
	case Movement::RIGHT:
		player1.positionY++;
		if (board[player1.positionX][player1.positionY] != Cell::STONE)
		{
			if (player1.positionY > columns-1)
			{
				player1.positionY = 0;
				if (board[player1.positionX][player1.positionY] == Cell::STONE)
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
			board[player1.positionX][player1.positionY] = Cell::PLAYER; //Poner otra vez el player en la posicion que estava
			return false;
		}
		break;
	case Movement::LEFT:
		player1.positionY--;
		if (board[player1.positionX][player1.positionY] != Cell::STONE)
		{
			if (player1.positionY < 0)
			{
				player1.positionY = columns-1;
				if (board[player1.positionX][player1.positionY] == Cell::STONE)
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
			board[player1.positionX][player1.positionY] = Cell::PLAYER; //Poner otra vez el player en la posicion que estava
			return false;
		}
		break;
	case Movement::UP:
		player1.positionX--;
		if (board[player1.positionX][player1.positionY] != Cell::STONE)//NOS DA UN ERROR ......
		{
			if (player1.positionX < 0)
			{
				player1.positionX = rows - 1;
				if (board[player1.positionX][player1.positionY] == Cell::STONE)
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
			board[player1.positionX][player1.positionY] = Cell::PLAYER; //Poner otra vez el player en la posicion que estava
			return false;
		}
		break;
	case Movement::DOWN:
		player1.positionX++;
		if (board[player1.positionX][player1.positionY] != Cell::STONE)
		{
			if (player1.positionX > rows-1)
			{
				player1.positionX = 0;
				if (board[player1.positionX][player1.positionY] == Cell::STONE)
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
			board[player1.positionX][player1.positionY] = Cell::PLAYER; //Poner otra vez el player en la posicion que estava
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
		if (board[player1.positionX][player1.positionY] == Cell::COINS)
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
	board[player1.positionX][player1.positionY] = Cell::PLAYER;
}


void Map::movePlayer(player &player1, Movement newmovement) //FUNCIÓN PARA MOVER EL PERSONAJE EN EL TABLERO Y ESTE ESTAR REPRESENTADO
{
	if (newmovement==Movement::NOTHING){}
	
	else {
		if (checkMovement(player1, newmovement))
		{
			board[player1.positionX][player1.positionY] = Cell::PLAYER;
		}
	}
	
}

void Map::gameState(GameStates _gameState)
{
	if (_gameState == GameStates::INIT)
	{
		std::cout << "*-*- INIT -*-*" << '\n';
		std::cout << "Press SPACE to start";
	}
	else if (_gameState == GameStates::PLAY)
	{
		std::cout << "*-*- PLAY -*-*" << '\n';
		std::cout << "Press P to pause";
	}
	else if (_gameState == GameStates::PAUSE)
	{
		std::cout << "*-*- PAUSE -*-*" << '\n';
		std::cout << "Press P to restore";
	}
	else if (_gameState == GameStates::GAMEOVER)
	{
		std::cout << "*-*- GAMEOVER -*-*" << '\n';
		std::cout << "YOU LOSE";
	}
}

void Map::setEnemiesInky(Enemies &Inky, int _posXInky, int _posYInky) //Funcion para poner posicion inicial X e Y de INKY en enemies
{
	for (int i = 0; i <= rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (board[i][j] == Cell::INKY) {
				Inky.setEnemies(i, j);
				
			}
		}
	}
}
