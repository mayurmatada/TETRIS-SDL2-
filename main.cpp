#include "SDL.h"
#include <iostream>
#include "framework.h"
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <cmath>

bool isrunning = true;

unsigned short int fps = 1;
double tickrate = 1000 / fps;

void checkticks()
{
	if (std::fmod(SDL_GetTicks(), tickrate) != 0 && std::fmod(SDL_GetTicks(), tickrate) != 1 && std::fmod(SDL_GetTicks(), tickrate) != 2 && std::fmod(SDL_GetTicks(), tickrate) != 3 && std::fmod(SDL_GetTicks(), tickrate) != 4 && std::fmod(SDL_GetTicks(), tickrate) != 5 | std::fmod(SDL_GetTicks(), tickrate) != 6 && std::fmod(SDL_GetTicks(), tickrate) != 7 && std::fmod(SDL_GetTicks(), tickrate) != 8 && std::fmod(SDL_GetTicks(), tickrate) != 9 && std::fmod(SDL_GetTicks(), tickrate) != 10)
	{
		Sleep(1);
		checkticks();
	}
}

int main(int argc, char* args[])
{
	srand(time(NULL));
	framework game;

	while (isrunning == true)
	{
		game.sequence();
		checkticks();
	}
	return 0;
}