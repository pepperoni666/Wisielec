#ifndef __GAMEPLAY_H__
#define __GAMEPLAY_H__
#include "screen.h"
#include "reader.h"

//klasa reprezentuje rozgrywke
//zawiera w sobie lista wszystkich graczy
//realizuje dostep do slowa, zarzadza ekranami
//prganizuje wszystko w jedna calosc i tym tworzy gre
class Gameplay {
private:
	Reader* wordManager; //zarzadzanie slowem
	Screen screenManager; //odpowiada za wypisywanie do konsoli
	Player* playerList; //wskaznik na glowe listy graczy
	void addPlayer(string name); //dodaje gracza ludzkiego
	void addPlayer(); //dodaje bota
	bool areValidPlayers(); //sprawdza czy sposriod graczy ktokolwiek moze jeszcze zgadywac
public:
	Gameplay();
	void initPlayers(); //podanie ilosci i typow graczy
	bool game(); //jegna rozgrywka
};

#endif //__GAMEPLAY_H__