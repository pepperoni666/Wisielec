#include "gameplay.h"

Gameplay::Gameplay() : screenManager() {
	playerList = NULL;
	wordManager = NULL;
	/*
	Player* y = new Player("Marek");
	Player* t = new Player("Konrad", y);
	Player* te = new Player("Beata", t);
	Player* bot = new Player_bot(te);
	playerList = bot;
	screenManager.printPlayground(playerList, wordManager->getWord(), wordManager->getUsed());*/
}

void Gameplay::initPlayers() {
	bool flag = true, f = false;
	while (flag) {
		if (playerList != NULL)
			f = true;
		switch (screenManager.chousePlayerType(f)) {
		case 1:
			addPlayer(screenManager.playerName());
			break;
		case 2:
			addPlayer();
			break;
		default:
			flag = false;
			break;
		}
	}
}

void Gameplay::addPlayer(string name) {
	if (playerList == NULL) {
		playerList = new Player(name);
	}
	else {
		Player* tmp = new Player(name, playerList);
		playerList = tmp;
	}
}

void Gameplay::addPlayer() {
	if (playerList == NULL) {
		playerList = new Player_bot();
	}
	else {
		Player* tmp = new Player_bot(playerList);
		playerList = tmp;
	}
}

bool Gameplay::game() {
	wordManager = new Reader();
	//TODO: madrze zrobiona petla rozgrywki
	return false;
}