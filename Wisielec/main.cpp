#include "gameplay.h"

int main(){
	Gameplay* game = new Gameplay();
	game->initPlayers(); //podanie ilosci i typow graczy
	while (game->game()); //rozgrywka
	return 0;
}