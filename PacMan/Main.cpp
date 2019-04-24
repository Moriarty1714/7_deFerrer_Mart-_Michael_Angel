//L�gica general del joc, detecci� de inputs, control de frames (GameLoop)
#include "Map.h"
#include "Player.h"
#include <Windows.h>


int main()
{

	Map board;
	player player;

	Enemies inky;

	board.setPlayer(player);
	board.setEnemiesInky(inky);

	Movement move = Movement::NOTHING; //Inicialmente estamos quietos
	GameStates gameState = GameStates::INIT; //Inicialmente se encuentra en estado inicial


#pragma region MANERA COMO DEBE HACERSE EL MAIN!!! CAMBIARLO A ESTA MANERA
	//mirar pdf especificacions del projecte!!! Estructura del projecte - controls!

	//INIT GAME VARIABLES
	//.....
	//bool keyboard[(int)InputKey::COUNT] - {};

	//while (!keyboard[(int)InputKey::K_ESC])
	//{
	//	//INPUT HANDLE
	//	keyboard[(int)InputKey::K_ESC] = GetAsyncKeyState(VK_ESCAPE);
	//	keyboard[(int)InputKey::K_UP] = GetAsyncKeyState(VK_UP);
	//	keyboard[(int)InputKey::K_DOWN] = GetAsyncKeyState(VK_DOWN);
	//	keyboard[(int)InputKey::K_RIGHT] = GetAsyncKeyState(VK_RIGHT);
	//	keyboard[(int)InputKey::K_LEFT] = GetAsyncKeyState(VK_LEFT);

	//	//UPDATE
	//	//....

	//	//DRAW
	//	//.....

	//	//FRAME CONTROL
	//	//....
	//}
	//return 0;
#pragma endregion

	//INPUT OPCI�N GETASYNCKEYSTATE (COMO LA PRACTICA AA2)
	do {
		system("cls"); //Ens permet imprimir en el mateix lloc  que l'anterior (netejar la pantalla)
		if (gameState == GameStates::PLAY)
		{
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
		}
		else if (gameState == GameStates::PAUSE)
		{
			if (GetAsyncKeyState('P') || GetAsyncKeyState('p')) //TECLA P para poder RENAUDAR el juego
			{
				move = Movement::NOTHING;
				gameState = GameStates::PLAY;
			}
			else if (GetAsyncKeyState(VK_ESCAPE)) //TECLA ESCAPE (ESC) para poder salir del juego (CIERRA CONSOLA)
			{
				exit(0);
			}
		}

		else if (gameState == GameStates::INIT)
		{
			if (GetAsyncKeyState(VK_SPACE)) //TECLA P para poder RENAUDAR el juego
			{
				move = Movement::NOTHING;
				gameState = GameStates::PLAY;
			}
			else if (GetAsyncKeyState(VK_ESCAPE)) //TECLA ESCAPE (ESC) para poder salir del juego (CIERRA CONSOLA)
			{
				exit(0);
			}
		}

			//LÓGICA DEL JUEGO
			board.movePlayer(player, move);
			board.moveEnemy(inky, move);
			//DRAW
			player.printScore();
			board.gameState(gameState);
			board.mostrarTablero();


			//CONTROLADOR DE FRAMES
			Sleep(400); //Espera cada 0.4 seg a tornar a fer el següent codi


	} while (true);

	return 0;
}