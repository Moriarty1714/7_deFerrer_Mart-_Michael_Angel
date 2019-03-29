//L�gica general del joc, detecci� de inputs, control de frames (GameLoop)
#include "Map.h"
#include "Player.h"
#include <Windows.h>


int main()
{

	Map tablero;
	player player;

	tablero.setPlayer(player);
	
	Movement move = Movement::NOTHING;; //Inicialmente estamos quietos
	
	//INPUT OPCI�N GETASYNCKEYSTATE (COMO LA PRACTICA AA2)
	do {
		Sleep(400); //Espera cada 0.4 seg a tornar a fer el següent codi
		system("cls");//Ens permet imprimir en el mateix lloc  que l'anterior (netejar la pantalla)
		
		if (GetAsyncKeyState('D') || GetAsyncKeyState(VK_RIGHT)) //Tecla D y (FLECHA DERECHA TECLADO) mueve el personaje a la derecha
		{
			move = Movement::RIGHT;
		}
		else if (GetAsyncKeyState('W') || GetAsyncKeyState(VK_UP)) //Tecla W y (FLECHA ARRIBA TECLADO) mueve el personaje arriba
		{
			move = Movement::UP;
		}
		else if (GetAsyncKeyState('S') || GetAsyncKeyState(VK_DOWN)) //Tecla S y (FLECHA ABAJO TECLADO) mueve el personaje abajo
		{
			move = Movement::DOWN;
		}
		else if (GetAsyncKeyState('A') || GetAsyncKeyState(VK_LEFT)) //Tecla A y (FLECHA IZQUIERDA TECLADO) mueve el personaje a la izquierda
		{
			move = Movement::LEFT;
		}
		else if (GetAsyncKeyState(VK_ESCAPE)) //TECLA ESCAPE (ESC) para poder salir del juego (CIERRA CONSOLA)
		{
			exit(0);
		}
		
		tablero.movePlayer(player, move);
		player.printScore();
		tablero.mostrarTablero();
		

	} while (true);

	return 0;
}