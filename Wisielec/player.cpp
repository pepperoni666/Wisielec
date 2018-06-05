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

string Player::gues() {
	string c;
	cout << name << ", wpisz litere: ";
	cin >> c;
	while (c.length() != 1) {
		cout << "Invalid value" << endl;
		cout << name << ", wpisz litere: ";
		cin >> c;
	}
	return "";
}

string Player_bot::gues() {
	//TODO: losuje i zwraca litere;
	return "";
}