//L�gica general del joc, detecci� de inputs, control de frames (GameLoop)
#include "Map.h"
#include "Player.h"
#include <Windows.h>


int main()
{

	Map board;
	player player;

	board.setPlayer(player);
	
	Movement move = Movement::NOTHING; //Inicialmente estamos quietos
	GameStates gameState = GameStates::INIT; //Inicialmente se encuentra en estado inicial
	
	//INPUT OPCI�N GETASYNCKEYSTATE (COMO LA PRACTICA AA2)
	do {

		while (gameState == GameStates::PLAY)
		{
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
			else if (GetAsyncKeyState('P') || GetAsyncKeyState('p')) //TECLA P para poder PAUSAR el juego
			{
				move = Movement::NOTHING;
				gameState = GameStates::PAUSE;
			}
			else if (GetAsyncKeyState(VK_ESCAPE)) //TECLA ESCAPE (ESC) para poder salir del juego (CIERRA CONSOLA)
			{
				exit(0);
			}

			//LÓGICA DEL JUEGO
			board.movePlayer(player, move);

			//DRAW
			player.printScore();
			board.gameState(gameState);
			board.mostrarTablero();


			//CONTROLADOR DE FRAMES
			Sleep(400); //Espera cada 0.4 seg a tornar a fer el següent codi
		}

		while (gameState == GameStates::PAUSE)
		{
			system("cls");//Ens permet imprimir en el mateix lloc  que l'anterior (netejar la pantalla)

			if (GetAsyncKeyState('P') || GetAsyncKeyState('p')) //TECLA P para poder RENAUDAR el juego
			{
				move = Movement::NOTHING;
				gameState = GameStates::PLAY;
			}
			else if (GetAsyncKeyState(VK_ESCAPE)) //TECLA ESCAPE (ESC) para poder salir del juego (CIERRA CONSOLA)
			{
				exit(0);
			}

			//LÓGICA DEL JUEGO
			board.movePlayer(player, move);

			//DRAW
			player.printScore();
			board.gameState(gameState);
			board.mostrarTablero();


			//CONTROLADOR DE FRAMES
			Sleep(400); //Espera cada 0.4 seg a tornar a fer el següent codi
		}

		while (gameState == GameStates::INIT)
		{
			system("cls");//Ens permet imprimir en el mateix lloc  que l'anterior (netejar la pantalla)

			if (GetAsyncKeyState(VK_SPACE)) //TECLA P para poder RENAUDAR el juego
			{
				move = Movement::NOTHING;
				gameState = GameStates::PLAY;
			}
			else if (GetAsyncKeyState(VK_ESCAPE)) //TECLA ESCAPE (ESC) para poder salir del juego (CIERRA CONSOLA)
			{
				exit(0);
			}

			//LÓGICA DEL JUEGO
			board.movePlayer(player, move);

			//DRAW
			player.printScore();
			board.gameState(gameState);
			board.mostrarTablero();


			//CONTROLADOR DE FRAMES
			Sleep(400); //Espera cada 0.4 seg a tornar a fer el següent codi
		}

	} while (true);

	return 0;
}