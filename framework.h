#pragma once
#include "SDL.h"
#include <time.h>
#include <stdlib.h>
#include <vector>

#define BOARD_LINE_WIDTH 6
#define BLOCK_SIZE 16
#define BOARD_POSITION 320
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define MIN_VERTICAL_MARGIN 20
#define MIN_HORIZONTAL_MARGIN 20
#define PIECE_BLOCKS 5
#define TILESIZE 30

extern const unsigned short mPieces[7 /*kind */][4 /* rotation */][5 /* horizontal blocks */][5 /* vertical blocks */];

struct piece
{
	short rotation;
	short piece_type;
};

class framework {
public:
	framework();
	~framework();
	void input();
	void clearlines();
	void sequence();
	void draw();
	SDL_Window* window;
	SDL_Renderer* render;
	short board_matrix[BOARD_HEIGHT][BOARD_WIDTH];
	SDL_Rect squares[BOARD_HEIGHT][BOARD_WIDTH];
	piece currentpiece;
	bool KEYS[322];
	void shiftdown();
	void shiftcurrentpiecedown();
	void rotatecurrentpiece();
	void newpiece();
	void settle();
	void slampiece();
	void handleInput();
	void shiftcurrentpieceright();
	void shiftcurrentpieceleft();
};