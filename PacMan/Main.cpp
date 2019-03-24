//Lògica general del joc, detecció de inputs, control de frames (GameLoop)
#include "Map.h"
#include "Player.h"
#include <Windows.h>


int main()
{

	Map tablero;

	tablero.mostrarTablero();


	//INPUT OPCIÓN GETASYNCKEYSTATE (COMO LA PRACTICA AA2)
	    
	 //   Movement move;

		//Sleep(400);
		//if (GetAsyncKeyState('W')) {
		//	move = Movement::UP;
		//}
		//else if (GetAsyncKeyState('A')) {
		//	move = Movement::LEFT;
		//}
		//else if (GetAsyncKeyState('D')) {
		//	move = Movement::RIGHT;
		//}
		//else if (GetAsyncKeyState('S')) {
		//	move = Movement::DOWN;
		//}

	return 0;
}