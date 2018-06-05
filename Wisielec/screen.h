#ifndef __SCREEN_H__
#define __SCREEN_H__
#include <stdlib.h>
#include "player.h"

class Screen {
public:
	void printPlayground(Player* players, string word, string used);
	int chousePlayerType(bool f);
	string playerName();
};

#endif //__SCREEN_H__