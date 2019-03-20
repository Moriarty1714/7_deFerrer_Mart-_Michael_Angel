//Control i lògica del mapa

#include <iostream>
#include <fstream>


int main() 
{
	int number1;
	int number2;

	std::ifstream myFile("config.txt");
	if (myFile.is_open())
	{
		myFile >> number1;
		myFile >> number2;
		myFile.close();
	}
	std::cout << number1 << " " << number2;
}