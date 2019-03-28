//L�gica general del joc, detecci� de inputs, control de frames (GameLoop)
#include "Map.h"
#include "Player.h"
#include <Windows.h>


int main()
{

	Map tablero;
	player player;

	tablero.setPlayer(player);
	tablero.mostrarTablero();
	

	Movement move;


	//INPUT OPCI�N GETASYNCKEYSTATE (COMO LA PRACTICA AA2)
	do {
		Sleep(400); //Espera cada 0.4 seg a tornar a fer el següent codi
		system("cls"); //Ens permet imprimir en el mateix lloc  que l'anterior (netejar la pantalla)
		
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
		else {
			move = Movement::NOTHING;
		}

		tablero.movePlayer(player, move);
		player.printScore();
		tablero.mostrarTablero();
		//if (tablero.checkMovement(move, player)) {
		//	//player.printScore(); //CREAR ESTA FUNCI�N!!!!
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