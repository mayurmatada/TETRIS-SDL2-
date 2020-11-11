#include "framework.h"
#include "SDL.h"
#include <stdlib.h>
#include <time.h>

const unsigned short mPieces[7 /*kind */][4 /* rotation */][5 /* horizontal blocks */][5 /* vertical blocks */] =
{
	// Square
	  {
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 2, 1, 0},
		{0, 0, 1, 1, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 2, 1, 0},
		{0, 0, 1, 1, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 2, 1, 0},
		{0, 0, 1, 1, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 2, 1, 0},
		{0, 0, 1, 1, 0},
		{0, 0, 0, 0, 0}
		}
	   },

	// I
	  {
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 1, 2, 1, 1},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 2, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{1, 1, 2, 1, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 2, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
		}
	   }
	  ,
	// L
	  {
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 2, 0, 0},
		{0, 0, 1, 1, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 1, 2, 1, 0},
		{0, 1, 0, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 1, 1, 0, 0},
		{0, 0, 2, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0},
		{0, 1, 2, 1, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
		}
	   },
	// L mirrored
	  {
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 2, 0, 0},
		{0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0},
		{0, 1, 2, 1, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 1, 0},
		{0, 0, 2, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 1, 2, 1, 0},
		{0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0}
		}
	   },
	// N
	  {
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0},
		{0, 0, 2, 1, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 1, 2, 0, 0},
		{0, 0, 1, 1, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 1, 2, 0, 0},
		{0, 1, 0, 0, 0},
		{0, 0, 0, 0, 0}
		},

	   {
		{0, 0, 0, 0, 0},
		{0, 1, 1, 0, 0},
		{0, 0, 2, 1, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
		}
	   },
	// N mirrored
	  {
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 2, 1, 0},
		{0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 2, 1, 0},
		{0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0},
		{0, 1, 2, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 1, 0},
		{0, 1, 2, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
		}
	   },
	// T
	  {
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 2, 1, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 1, 2, 1, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 1, 2, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 1, 2, 1, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
		}
	   }
};

framework::framework()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	srand(time(NULL));

	for (int i = 0; i < 322; i++)
	{
		KEYS[i] = false;
	}



	window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, BOARD_WIDTH * TILESIZE, BOARD_HEIGHT * TILESIZE, 0);
	render = SDL_CreateRenderer(window, -1, 0);

	for (unsigned int i = 0; i <= BOARD_HEIGHT - 1; i++)
	{
		for (unsigned int j = 0; j <= BOARD_WIDTH - 1; j++)
		{
			board_matrix[i][j] = 0;
		}
	}

	for (unsigned int i = 0; i <= BOARD_HEIGHT - 1; i++)
	{
		for (unsigned int j = 0; j <= BOARD_WIDTH - 1; j++)
		{
			squares[j][i].x = i * TILESIZE;
			squares[j][i].y = j * TILESIZE;
			squares[j][i].w = TILESIZE;
			squares[j][i].h = TILESIZE;
		}
	}

	newpiece();
}

framework::~framework()
{
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
}

void framework::input()
{
	bool action = false;
	SDL_Event e;
	switch (SDL_PollEvent(&e))
	{
	case SDL_QUIT:
		SDL_DestroyRenderer(render);
		SDL_DestroyWindow(window);
	case SDL_KEYDOWN:
		KEYS[e.key.keysym.sym] = true;
		action = true;
		break;
	case SDL_KEYUP:
		KEYS[e.key.keysym.sym] = false;
		action = true;
		break;
	}
	if (action == true)
	{
		handleInput();
	}
}

void framework::clearlines()
{
	bool clear = true;
	for (unsigned int i = 0; i <= BOARD_WIDTH - 1; i++)
	{
		if (board_matrix[i][BOARD_HEIGHT - 1] != 3)
		{
			bool clear = false;
			break;
		}
	}
	if (clear == true) {
		for (unsigned int j = 0; j <= BOARD_WIDTH - 1; j++)
		{
			board_matrix[j][BOARD_HEIGHT - 1] = 0;
		}
		shiftdown();
	}
}

void framework::sequence()
{
	shiftcurrentpiecedown();
	input();
	settle();
	clearlines();
	draw();
}

void framework::draw()
{
	SDL_RenderClear(render);
	for (short i = BOARD_HEIGHT - 1; i >= 0; i--)
	{
		for (short j = BOARD_WIDTH - 1; j >= 0; j--)
		{
			if (board_matrix[i][j] == 1 || board_matrix[i][j] == 2)
			{
				SDL_SetRenderDrawColor(render, 255, 124, 0, 255);
				SDL_RenderFillRect(render, &squares[j][i]);
				SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
			}
		}
	}
	SDL_RenderPresent(render);
}

void framework::shiftdown()
{
	for (short i = BOARD_HEIGHT - 1; i >= 0; i--)
	{
		for (short j = BOARD_WIDTH - 1; j >= 0; j--)
		{
			board_matrix[i][j] = board_matrix[i][j - 1];
		}
	}
}

void framework::shiftcurrentpiecedown()
{
	bool possible = true;
	for (short i = BOARD_HEIGHT - 1; i >= 0; i--)
	{
		for (short j = BOARD_WIDTH - 1; j >= 0; j--)
		{
			if (board_matrix[i][j] == 1 || board_matrix[i][j] == 2)
			{
				if (board_matrix[i][j + 1] == 3 || j + 1 == BOARD_WIDTH - 1)
				{
					possible = false;
					settle();
					break;
				}
			}
		}
	}
	if (possible == true) {
		for (short i = BOARD_HEIGHT - 1; i >= 0; i--)
		{
			for (short j = BOARD_WIDTH - 1; j >= 0; j--)
			{
				if (board_matrix[i][j] == 1 || board_matrix[i][j] == 2 || board_matrix[i-1][j] == 1 || board_matrix[i-1][j] == 2)
				{
					board_matrix[i][j] = board_matrix[i-1][j];
				}
			}
		}
	}
}

void framework::rotatecurrentpiece()
{
	currentpiece.rotation += 1;
	if (currentpiece.rotation == 5)
	{
		currentpiece.rotation = 1;
	}
	for (unsigned short i = BOARD_HEIGHT - 1; i >= 0; i--)
	{
		for (unsigned short j = BOARD_WIDTH - 1; j >= 0; j--)
		{
			if (board_matrix[i][j] == 2)
			{
				for (unsigned short k = i - 2; k >= 0; k--)
				{
					for (unsigned short n = j - 2; n >= 0; n--)
					{
						board_matrix[n][k] = mPieces[currentpiece.piece_type][currentpiece.rotation][n][k];
					}
				}
			}
		}
	}
}

void framework::newpiece()
{
	currentpiece.piece_type = rand() % 7 + 1;
	currentpiece.rotation = rand() % 4 + 1;
	int x, y;
	x = BOARD_WIDTH / 2;
	y = BOARD_HEIGHT / 2;
	for (short k = x - 3; k >= 0; k--)
	{
		for (short n = y - 6; n >= 0; n--)
		{
			board_matrix[k][n] = mPieces[currentpiece.piece_type][currentpiece.rotation][k][n];
		}
	}
}

void framework::settle()
{
	bool settled = false;
	for (short i = BOARD_HEIGHT - 1; i >= 0; i--)
	{
		for (short j = BOARD_WIDTH - 1; j >= 0; j--)
		{
			if (board_matrix[i][j] == 1 || board_matrix[i][j] == 2)
			{
				if (board_matrix[i][j + 1] == 3 || i == BOARD_HEIGHT - 1)
				{
					board_matrix[i][j] = 3;
					settled = true;
				}
			}
		}
	}
	if (settled == true) {
		currentpiece.piece_type = NULL;
		currentpiece.rotation = NULL;
		newpiece();
	}
}

void framework::slampiece()
{
	for (short i = 0; i <= BOARD_HEIGHT - 1; i++)
	{
		shiftcurrentpiecedown();
	}
}

void framework::handleInput()
{
	if (KEYS[SDLK_RIGHT])
	{
		shiftcurrentpiecedown();
	}
	if (KEYS[SDLK_LEFT])
	{
		shiftcurrentpieceleft();
	}
	if (KEYS[SDLK_z])
	{
		slampiece();
	}
	if (KEYS[SDLK_x])
	{
		rotatecurrentpiece();
	}
}

void framework::shiftcurrentpieceright()
{
	bool possible = true;
	for (short i = BOARD_HEIGHT - 1; i >= 0; i--)
	{
		for (short j = BOARD_WIDTH - 1; j >= 0; j--)
		{
			if (board_matrix[i][j] == 1 || board_matrix[i][j] == 2)
			{
				if (board_matrix[i + 1][j] == 3 || j + 1 == BOARD_WIDTH - 1)
				{
					possible = false;
					settle();
					break;
				}
			}
		}
	}
	if (possible == true) {
		for (short i = BOARD_HEIGHT - 1; i >= 0; i--)
		{
			for (short j = BOARD_WIDTH - 1; j >= 0; j--)
			{
				if (board_matrix[i][j] == 1 || board_matrix[i][j] == 2 || board_matrix[i - 1][j] == 1 || board_matrix[i - 1][j] == 2)
				{
					board_matrix[i][j] = board_matrix[i - 1][j];
				}
			}
		}
	}
}

void framework::shiftcurrentpieceleft()
{
	bool possible = true;
	for (short i = BOARD_HEIGHT - 1; i >= 0; i--)
	{
		for (short j = BOARD_WIDTH - 1; j >= 0; j--)
		{
			if (board_matrix[i][j] == 1 || board_matrix[i][j] == 2)
			{
				if (board_matrix[i - 1][j] == 3 || j - 1 == BOARD_WIDTH - 1)
				{
					possible = false;
					settle();
					break;
				}
			}
		}
	}
	if (possible == true)
	{
		for (short i = BOARD_HEIGHT - 1; i >= 0; i--)
		{
			for (short j = 0; j <= BOARD_WIDTH - 1; j++)
			{
				if (board_matrix[i][j] == 1 || board_matrix[i][j] == 2 || board_matrix[i + 1][j] == 1 || board_matrix[i + 1][j] == 2)
				{
					board_matrix[i][j] = board_matrix[i + 1][j];
				}
			}
		}
	}
}