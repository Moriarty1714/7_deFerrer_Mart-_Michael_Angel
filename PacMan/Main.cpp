//Lògica general del joc, detecció de inputs, control de frames (GameLoop)
#include "Map.h"
#include "Player.h"


int main()
{

	Map tablero;

	tablero.mostrarTablero();

	//INPUT OPCIÓN AA1_04
#pragma region INPUT CONTROLS
//	char c;
//	std::cin >> c;
//	Movement move;
//
//	switch (c)
//	{
//	case 'w':
//	case 'W':
//		myBoard.movePlayer(myPlayer, Movement::UP);
//		move = Movement::UP;
//		break;
//	case 'a':
//	case 'A':
//		myBoard.movePlayer(myPlayer, Movement::LEFT);
//		move = Movement::LEFT;
//		break;
//	case 's':
//	case 'S':
//		myBoard.movePlayer(myPlayer, Movement::DOWN);
//		move = Movement::DOWN;
//		break;
//	case 'd':
//	case 'D':
//		myBoard.movePlayer(myPlayer, Movement::RIGHT);
//		move = Movement::RIGHT;
//		break;
//	default:
//		break;
//	}
#pragma endregion


	//INPUT OPCIÓN GETASYNCKEYSTATE (COMO LA PRACTICA AA2)

#pragma region INPUT CONTROLS
	/*do {
		board.printBoard();

		Sleep(400);
		if (GetAsyncKeyState('W')) {
			movement = Movement::UP;
		}
		else if (GetAsyncKeyState('A')) {
			movement = Movement::LEFT;
		}
		else if (GetAsyncKeyState('D')) {
			movement = Movement::RIGHT;
		}
		else if (GetAsyncKeyState('S')) {
			movement = Movement::DOWN;
		}*/
#pragma endregion

	return 0;
}