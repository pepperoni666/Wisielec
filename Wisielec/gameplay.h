#ifndef __GAMEPLAY_H__
#define __GAMEPLAY_H__
#include "screen.h"
#include "reader.h"

class Gameplay {
private:
	Reader* wordManager;
	Screen screenManager;
	Player* playerList;
	void addPlayer(string name);
	void addPlayer();
public:
	Gameplay();
	void initPlayers();
	bool game();
};

#endif //__GAMEPLAY_H__