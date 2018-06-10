#ifndef __SCREEN_H__
#define __SCREEN_H__
#include <stdlib.h>
#include <Windows.h>
#include "player.h"

//klasa odpowiada za wypisywanie do konsoli
//poprzez rozne ekrany uzytkownik oddzialywuje z gra
class Screen {
	HANDLE color; //interface dla kolorow
public:
	Screen() { color = GetStdHandle(STD_OUTPUT_HANDLE); }
	void printPlayground(Player* players, string word, string used); //wypisuje plansze (slowo, uzyte litery, graczy i ich stan)
	int chousePlayerType(bool f); //ekran podania ilosci i typu graczy
	string playerName(); //gracz ludzki podaje imie
	void end(); //ekran koncowy
	bool restart(); //pyta graczy, czy chca powtorzyc gre
};

#endif //__SCREEN_H__