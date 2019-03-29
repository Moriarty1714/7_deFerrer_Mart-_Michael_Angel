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
	

	Movement move = Movement::NOTHING;;
	
	//INPUT OPCI�N GETASYNCKEYSTATE (COMO LA PRACTICA AA2)
	do {
		Sleep(400); //Espera cada 0.4 seg a tornar a fer el següent codi
		system("cls");//Ens permet imprimir en el mateix lloc  que l'anterior (netejar la pantalla)
		
		if (GetAsyncKeyState('D')) {
			move = Movement::UP;
		}
		else if (GetAsyncKeyState('W')) {
			move = Movement::LEFT;
		}
		else if (GetAsyncKeyState('S')) {
			move = Movement::RIGHT;
		}
		else if (GetAsyncKeyState('A')) {
			move = Movement::DOWN;
		}
		
		tablero.movePlayer(player, move);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);//Color estándar
		player.printScore();
		tablero.mostrarTablero();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);//Color estándar

	} while (true);

	return 0;
}