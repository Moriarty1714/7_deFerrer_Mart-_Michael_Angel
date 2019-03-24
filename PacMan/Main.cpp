//Lògica general del joc, detecció de inputs, control de frames (GameLoop)
#include "Map.h"
#include "Player.h"
#include <Windows.h>


int main()
{

	Map tablero;
	player player;

	tablero.mostrarTablero();


	Movement move;


	//INPUT OPCIÓN GETASYNCKEYSTATE (COMO LA PRACTICA AA2)
	do {

		Sleep(400);
		if (GetAsyncKeyState('W')) {
			move = Movement::UP;
		}
		else if (GetAsyncKeyState('A')) {
			move = Movement::LEFT;
		}
		else if (GetAsyncKeyState('D')) {
			move = Movement::RIGHT;
		}
		else if (GetAsyncKeyState('S')) {
			move = Movement::DOWN;
		}

		//if (tablero.checkMovement(move, player)) {
		//	//player.printScore(); //CREAR ESTA FUNCIÓN!!!!
		//	if (tablero.existsCoin(movement, player))
		//	{
		//		tablero.movePlayerOnBoard(movement, player);
		//		player.updateScore();
		//	}
		//	else
		//	{
		//		tablero.movePlayerOnBoard(movement, player);
		//	}
		//}

	} while (true);

	return 0;
}