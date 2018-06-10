#include "player.h"

Player::Player(string _name) {
	next = NULL;
	stage = 0;
	name = _name;
}

Player::Player(string _name, Player* pr) {
	next = pr;
	stage = 0;
	name = _name;
}

string Player::gues(string guesed, string used) {
	string c;
	do {
		cout << name << ", wpisz litere: ";
		cin >> c;
		transform(c.begin(), c.end(), c.begin(), ::tolower);
		if (c.length() > 3) {
			cout << "Do you wanna guess the word? (y/n): ";
			string yn;
			cin >> yn;
			transform(yn.begin(), yn.end(), yn.begin(), ::tolower);
			if (yn == "y")
				return c;
		}
		cout << "Invalid value" << endl;
	} while (c.length() != 1 || guesed.find(c) != string::npos || used.find(c) != string::npos);
	return c;
}

string Player_bot::gues(string guesed, string used) {
	srand(time(NULL));
	int x;
	do {
		x = 97 + rand() % 26;
	} while (guesed.find((char)x) != string::npos || used.find((char)x) != string::npos);
	string s;
	s = (char)x;
	return s;
}