#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
using namespace std;

//klasa reprazentuje gracza (ludzkiego)
//posiada inforamcje dotyczace kazdego gracza
//oraz realizuje realizuje czynnosci na nich wywolywane
class Player {
private:
	int stage; //stan gracza (ile razy sie pomylil)
	string name; //imie gracza
public:
	Player * next; //wskaznik na nastepnego gracza dla listy dynamicznej
	Player(string _name);
	Player(string _name, Player* pr);
	string getName() { return name; }
	int getStage() { return stage; }
	void incrStage() { stage++; } //wywolywane kiedy gracz sie pomylil
	void lose() { stage = 7; } //przyznaje na rzecz gracza porazke
	virtual string gues(string guesed, string used); //gracz zgaduje
	void reset() { stage = 0; } //restartuje stan gracza, likwidujac dokonane do tej pory bledy
};

//gracz komputerowy
//nasladuje wszystko po graczu ludzkim
//oprucz metody zgadywania (tu ona losuje)
class Player_bot : public Player {
public:
	Player_bot() : Player("bot") {};
	Player_bot(Player* pr) : Player("bot", pr) {};
	string gues(string guesed, string used); //bot losuje litere
};

#endif //__PLAYER_H__