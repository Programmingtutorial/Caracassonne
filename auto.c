#include "auto.h"
#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Tiles\Project1/tile.h"
#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Board\Board/board.h"
#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Interactive\Interactive\interactive.h"

#include <stdio.h>
#include <stdlib.h>

/*
Zak³adam, ze program w pierwszym ruchu postawi klocek na œrodku planszy. 
Program bêdzie próbowa³ uk³adaæ klocki od prawej strony.
Wybiera kolejne klocki z tablicy i sprawdza czy zgadzaj¹ siê z s¹siadami.
Jeœli nie, bierze kolejny klocek (albo przechodzi dalej (?)).
*/

Board* initializeBoard(FILE *board_player, Board *p) {
	int i, j, k = 0, stop = 0;
	char s = '0';

	if (board_player == NULL) {
		printf("Fail to open the file.\n");
		exit(-1);
	}

	for (i = 0; i < length; i++) {
		for (j = 0; j < length; j++) {
			char *temp = (char*)malloc(tile_length * sizeof(char));
			while ((s = getc(board_player)) != ' ') {
				if (s == EOF)
					break;
				if (s != '\n') {
					temp[k] = s;
					k++;
				}
			}
			if (s == EOF)
				break;
			temp[k] = '\0';
			p->board[i][j] = temp;
			k = 0;
		}
		if (s == EOF)
			break;
	} 

	return p;
}

void fillBoardFile(FILE *board, Board *p) {
	int i, j;
	for (i = 0; i < length; i++) {
		for (j = 0; j < length; j++) {
			fprintf(board, "%.*s ", tile_length - 1, p->board[i][j]);
		}
		fprintf(board, "\n");
	}
}

void fillTileFile(FILE *tile, Tiles *t) {
	for (int i = 0; i < tiles_number; i++) {
		fprintf(tile, "%.*s\n", tile_length - 1, t->tiles[i]);
	}
}

/* Function places selected tile in the middle of the board as a first move. */
Board* firstMove(int tile, Tiles *t, Board *p) {

	p->board[length / 2][length / 2] = t->tiles[tile];

	return p;
}

/* Function checks if there is any tile on a board already.
If not, places a tile in a middle of a board as a first move- fistMove() function.
Otherwise it takes first free place from a right. */
int checkBoard(Board *p) {
	return 0;
}