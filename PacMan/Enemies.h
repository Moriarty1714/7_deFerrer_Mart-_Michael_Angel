#pragma once
#include <iostream>
#include "Player.h"
#include "Types.h"
#include <ctime>

class Enemies {
private:
	struct blinky {
		int posX;
		int posY;
	};
	struct inky {
		int posX;
		int posY;
	};
	struct clyde {
		int posX;
		int posY;
	};

	Enemies();
public:
	void movement();
};