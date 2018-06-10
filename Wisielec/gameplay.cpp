#include "gameplay.h"

Gameplay::Gameplay() : screenManager() {
	playerList = NULL;
	wordManager = NULL;
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

template<typename T>
void resetAll(T* ptr) {
	for (; ptr != NULL; ptr = ptr->next)
		ptr->reset();
}

bool Gameplay::game() {
	resetAll<Player>(playerList);
	wordManager = new Reader();
	if (wordManager->isUnstartable()) {
		screenManager.end();
		return false;
	}
	Player* ptr = playerList;
	while (!wordManager->isFinished() && areValidPlayers()) {
		screenManager.printPlayground(playerList, wordManager->getWord(), wordManager->getUsed());
		if (ptr->getStage() < 7) {
			string tmp = ptr->gues(wordManager->getGuesed(), wordManager->getUsed());
			if (tmp.length() > 3) {
				switch (wordManager->tryWord(tmp)) {
				case 2:
					ptr->incrStage();
					break;
				case 0:
					ptr->lose();
					break;
				default:
					break;
				}
			}
			else if (!wordManager->tryChar(tmp))
				ptr->incrStage();
		}
		if (ptr->next != NULL)
			ptr = ptr->next;
		else
			ptr = playerList;
	}
	screenManager.printPlayground(playerList, wordManager->getWord(), wordManager->getUsed());
	return screenManager.restart();
}

bool Gameplay::areValidPlayers() {
	Player* tmp = playerList;
	for (; tmp != NULL; tmp = tmp->next) {
		if (tmp->getStage() < 7)
			return true;
	}
	wordManager->forceFinish();
	return false;
}