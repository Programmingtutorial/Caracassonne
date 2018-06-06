#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Tiles\Project1/tile.h"
#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Board\Board/board.h"
#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Interactive\Interactive\interactive.h"
#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Project\Project/auto.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int counter = 0;

	Tiles program, *t;
	t = &program;

	// AUTO MODE.
	FILE *board_auto;
	FILE *tile_auto;
	Board gameauto, *player;

	// INTERACTIVE MODE.
	FILE *tile;
	FILE *board_player1;
	FILE *board_player2;
	Board gamep1, *player1;
	Board gamep2, *player2;

	if (argc > 2) {
		// AUTO MODE.
		player = &gameauto;

		board_auto = fopen(argv[2], "r");
		tile_auto = fopen(argv[1], "r");

		makeMoveAUTO(player, t, board_auto, tile_auto);
		fclose(tile_auto);
		fclose(board_auto);

		tile_auto = fopen(argv[1], "w");
		fillTileFile(tile_auto, t);
		fclose(tile_auto);

		board_auto = fopen(argv[2], "w");
		fillBoardFile(board_auto, player);
		fclose(board_auto);

	}
	else {
		// INTERACTIVE MODE.
		tile = fopen("tile.txt", "r");
		initializeTileArray(tile, t);
		fclose(tile);

		player1 = &gamep1;
		player2 = &gamep2;

		setBoard(player1);
		setBoard(player2);
		// Seting information about the first move to 0.
		player1->firstPlacing = 0;
		player2->firstPlacing = 0;

		// While there is at least one tile in tiles[] array the program continues.
		while (t->no_tiles != NO_TILES) {
			if (counter % 2 == 0) {
				// PLAYER 1.
				printf("************************************* PLAYER 1 *************************************\n\n");
				makeMove(player1, t);

				board_player1 = fopen("board_player1.txt", "w");
				fillBoardFile(board_player1, player1);
				fclose(board_player1);
			}
			else {
				// PLAYER 2.
				printf("************************************* PLAYER 2 *************************************\n\n");
				makeMove(player2, t);

				board_player2 = fopen("board_player2.txt", "w");
				fillBoardFile(board_player2, player2);
				fclose(board_player2);
			}
			counter++;
			tile = fopen("tile.txt", "w");
			fillTileFile(tile, t);
			fclose(tile);
		}
	}

	return 0;
}