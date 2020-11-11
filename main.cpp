#include "SDL.h"
#include <iostream>
#include "framework.h"
#include <time.h>
#include <stdlib.h>

bool isrunning = true;

int main(int argc, char* args[])
{
	srand(time(NULL));
	framework game;

	while (isrunning == true)
	{
		game.sequence();
	}
	return 0;
}