#include "screen.h"

void Screen::printPlayground(Player* players, string word, string used) {
	if (system("CLS")) system("clear");
	Player* tmp = players;
	cout << endl << "\t\t";
	for (int i = 0; i < word.length(); i++) cout << word.at(i) << " ";
	cout << endl;
	for (int i = 0; i < used.length(); i++) cout << used.at(i) << ", ";
	cout << endl;
	cout << endl;
	cout << " ";
	for (; tmp != NULL; tmp = tmp->next) {
		cout << tmp->getName();
		for (int i = 0; i < 10 - tmp->getName().length(); i++) cout << " ";
	}
	tmp = players;
	cout<< endl << " ";
	for (; tmp != NULL; tmp = tmp->next) {
		cout << "  ";
		if (tmp->getStage()>2) {
			cout << "__      ";
		}
		else {
			cout << "        ";
		}
	}
	tmp = players;
	cout << endl << " ";
	for (; tmp != NULL; tmp = tmp->next) {
		cout << " ";
		if (tmp->getStage()>3) {
			cout << "|  |     ";
		}
		else if (tmp->getStage() == 3) {
			cout << "|        ";
		}
		else {
			cout << "         ";
		}
	}
	tmp = players;
	cout << endl << " ";
	for (; tmp != NULL; tmp = tmp->next) {
		cout << " ";
		if (tmp->getStage()<2) {
			cout << "         ";
		}
		else if (tmp->getStage()<4) {
			cout << "|        ";
		}
		else {
			cout << "|  0     ";
		}
	}
	tmp = players;
	cout << endl << " ";
	for (; tmp != NULL; tmp = tmp->next) {
		cout << " ";
		if (tmp->getStage()<2) {
			cout << "         ";
		}
		else if (tmp->getStage()<5) {
			cout << "|        ";
		}
		else if (tmp->getStage() == 5) {
			cout << "|  |     ";
		}
		else {
			cout << "| -|-    ";
		}
	}
	tmp = players;
	cout << endl << " ";
	for (; tmp != NULL; tmp = tmp->next) {
		if (tmp->getStage() == 0) {
			cout << "          ";
		}
		else if (tmp->getStage() == 1) {
			cout << "____      ";
		}
		else if (tmp->getStage() == 7) {
			cout << "_|__^     ";
		}
		else {
			cout << "_|__      ";
		}
	}
	tmp = players;
	cout << endl << " ";
	for (; tmp != NULL; tmp = tmp->next) {
		cout << " " << tmp->getStage() << "/" << "7      ";
	}
	cout << endl;

}

int Screen::chousePlayerType(bool f) {
	if (system("CLS")) system("clear");
	cout << "\tChouse, will you play with friend or with computer? " << endl;
	cout << "\t\tb - bot" << endl;
	cout << "\t\th - human" << endl;
	if (f)
		cout << "\t\tend - finish creating players" << endl;
	string type;
	cin >> type;
	if (f) {
		while (type != "b" && type != "h" && type != "end") {
			cout << "Invalid value" << endl;
			cin >> type;
		}
	}
	else {
		while (type != "b" && type != "h") {
			cout << "Invalid value" << endl;
			cin >> type;
		}
	}
	if (type == "b")
		return 2;
	else if (type == "h")
		return 1;
	else
		return 0;
}

string Screen::playerName() {
	cout << "Enter player name: ";
	string name;
	cin >> name;
	while (name.length() > 9) {
		cout << "Name is to long" << endl;
		cout << "Enter player name: ";
		cin >> name;
	}
	return name;
}