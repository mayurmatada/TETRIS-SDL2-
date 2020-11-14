#include "SDL.h"
#include <iostream>
#include "framework.h"
#include <ctime>
#include <stdlib.h>
#include <windows.h>
#include <cmath>

bool isrunning = true;

int main(int argc, char* args[])
{
	srand(time(NULL));
	framework game;

	while (isrunning == true)
	{
		std::clock_t start = std::clock();
		game.sequence();
		Sleep(500);
		game.sequence();
		std::clock_t end = std::clock();
		Sleep(1000 - (end - start) / CLOCKS_PER_SEC * 1000);
	}
	return 0;
}