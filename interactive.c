#include "tile.h"
#include "Board.h"

#include <stdio.h>
#include <stdlib.h>

int selectMode();
int selectTile();
int selectPlace();
void hello();

int main() {
	if (selecMode() == 1) {
		hello();
	}

	return 0;
}

void hello() {
	printf("INTERACTIVE MODE\n");
	printf("Hello players");
}

int selectMode() {
	int mode;
	printf("Hello!\n");
	printf("Select mode: ");
	scanf("%d", &mode);
	printf("\n");

	return mode;
}

int selectTile() {
	int tile;
	printf("Select number of tile: ");
	scanf("%d", &tile);
	printf("\n");

	return (tile - 1);
}

int selectPlace() {
	char x;
	int y;
	char place;
	scanf("%c%d", &x, &y);

	return 0;
}



