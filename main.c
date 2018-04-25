#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Tiles\Project1/tile.h"
#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Board\Board/board.h"
#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Interactive\Interactive\interactive.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
	// Defines when to stop a program.
	int stop1 = 1, stop2 = 1, stop = 1;

	Tiles program, *t;
	t = &program;

	Board game, *p;
	p = &game;

	FILE *tile = fopen("tile.txt", "r");
	initializeTileArray(tile, t);
	fclose(tile);
	hello();
	setBoard(p);

	// Seting information about the first move to 0.
	p->firstPlacing1 = 0;
	p->firstPlacing2 = 0;

	// While there is at least one tile in tiles[] array the program continues.
	while (stop != NO_TILES) {
		if (stop1 != NO_TILES)
			stop1 = player1(p, t);
		if (stop2 != NO_TILES)
			stop2 = player2(p, t);
		if (stop1 == NO_TILES && stop2 == NO_TILES)
			stop = NO_TILES;
	}
	
	return 0;
}