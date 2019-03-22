//Control i lògica del mapa

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Map.h"

Map::Map() 
{
	
	char character;
	

	std::ifstream myFile("config.txt");
	if (myFile.is_open())
	{
		myFile >> rows;
		myFile >> columns;

		tablero = new char*[rows]; //Reservando memoria para cada Fila y cada una de las filas apuntara (variable puntero) a su vez a un sitio

		for (int i = 0; i <= rows; i++)
		{
			tablero[i] = new char[columns]; //Rservando memoria para cada Columna
			//la Fila tiene puntero porque apunta hacia las columnas (no tienen puntero)
			myFile.getline(tablero[i], columns + 1);
		}

		for (int i = 0; i <= rows; i++) //NO PONEMOS WHILE, porque ya sabemos el número de fílas y columnas que tenemos que leer
		{
			for (int j = 0; j < columns; j++)
			{

				std::cout << tablero[i][j];
				if (j == columns-1)
				{
					std::cout << '\n';
				}
			}
		}

	
		myFile.close();
	}
	
} // código que lee el archivo CONFIG.TXT (SE ENCUENTRA DENTRO DE LA CARPETA PACMAN)




void Map::mostrarTablero() //funcion para mostrar la matriz, a la que le pasamos los parametros de la matriz
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << tablero [i][j];

			if (j == columns - 1)
			{
				std::cout << '\n';
			}//Esto es lo mismo que decir con punteros
			////el *(tablero+i) señala a la fila y le añadimos *(....+j) para que señale la columna
		}
	}
}

