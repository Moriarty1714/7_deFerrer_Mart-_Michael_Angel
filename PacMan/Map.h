#pragma once

struct Map
{
	char **tablero; //dos punteros se�alan a una matriz!
	int rows;
	int columns;

	Map(); //CONSTRUCTOR del mapa 

	void mostrarTablero(); //funcion paa mostrar la matriz, a la que le pasamos los parametros de la matriz
};