#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <iostream>
#include <string>
using namespace std;

class Player {
private:
	int stage;
	string name;
public:
	Player * next;
	Player(string _name);
	Player(string _name, Player* pr);
	string getName() { return name; }
	int getStage() { return stage; }
	void incrStage() { stage++; }
	virtual string gues();
};


class Player_bot : public Player {
public:
	Player_bot() : Player("bot") {};
	Player_bot(Player* pr) : Player("bot", pr) {};
	string gues();
};

#endif //__PLAYER_H__