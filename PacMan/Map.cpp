//Control i lògica del mapa

#include <iostream>
#include <fstream>
#include <cstdlib>

int **tablero; //dos punteros señalan a una matriz!
int rows;
int columns;

void readMap() 
{
	
	char character;

	std::ifstream myFile("config.txt");
	if (myFile.is_open())
	{
		myFile >> rows;
		myFile >> columns;

		tablero = new int*[rows]; //Reservando memoria para cada Fila y cada una de las filas apuntara (variable puntero) a su vez a un sitio

		for (int i = 0; i < columns; i++)
		{
			tablero[i] = new int[columns]; //Rservando memoria para cada Columna
		}
		//la Fila tiene puntero porque apunta hacia las columnas (no tienen puntero)

		std::noskipws; //para que lea los espacios ' ' 
		while (myFile >> character)
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{

					*(*(tablero + i) + j) = character; //En este caso guardamos los elementos en la array bidimensional dinámica
					//el *(puntero+i) señala a la fila y le añadimos *(....+j) para que señale la columna
					//es lo mismo que decir punteroMatriz[i][j]
				}
			}
		}
		myFile.close();
	}
	
} // código que lee el archivo CONFIG.TXT (SE ENCUENTRA DENTRO DE LA CARPETA PACMAN)


void mostrarTablero(int **tablero, int rows, int columns) //funcion paa mostrar la matriz, a la que le pasamos los parametros de la matriz
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << *(*(tablero + i) + j); //Esto es lo mismo que decir tablero[i][j], pero con punteros
			////el *(tablero+i) señala a la fila y le añadimos *(....+j) para que señale la columna
		}
	}
}

int main()
{
	readMap();
	mostrarTablero(tablero, rows, columns);

	// la parte de funcion delete[] punteroarraydinamico --> no nos sirve aqui si no hacemos un bucle ya que es una matriz

	//A continuación liberamos el espacio de memoria que hemos utilizado en la Matriz
	for (int i = 0; i < rows; i++)
	{
		delete[] tablero[i]; //Liberamos el espacio de memoria de las columnas que apunta cada fila
	}

	delete[] tablero; //Liberamos el especio de memoria donde apunta tablero, es decir liberamos las filas
	//solo se haría este ultimo si solo fuera una array de una dimensión
}