#ifndef __READER_H__
#define __READER_H__
#define _CRT_SECURE_NO_DEPRECATE
#include <string>
#include <ctime>
#include <algorithm>
using namespace std;

//klasa odpowiada za wylosowanie i wczytanie nowego slowa z pliku
//nadaje ograniczony dostep do slowa, pozostalej czesci gry 
//zarzadza slowem
class Reader {
private:
	string guesed; //literki ktore juz udalo sie zgadnac
	string word; //wlasciwe slowo
	string used; //uzyte litery ktore nie pasuja
public:
	bool isUnstartable() { return word.empty(); } //sprawdza czy jest slowo zostalo wczytane prawidlowo
	Reader();
	bool isFinished(); //sprawdza czy wszystkie litery slowa udalo sie zgadnac
	string getWord(); //zwraca slowo z podlogami zamiast nieznanych liter
	string getUsed() { return used; } 
	string getGuesed() { return guesed; }
	bool tryChar(string c); //sprawdza czy slowo ma podana litere
	int tryWord(string s); //sprawdza czy udalo sie zgadnac slowo
	void forceFinish() { guesed = word; } //konczy gre poprzez odkrycie ujawnienie liter
};

#endif //__READER_H__