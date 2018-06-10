#include "screen.h"

void Screen::printPlayground(Player* players, string word, string used) {
	if (system("CLS")) system("clear");
	Player* tmp = players;
	cout << endl << "\t\t";
	if(word.find("_") == string::npos)
		SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	for (int i = 0; i < word.length(); i++) cout << word.at(i) << " ";
	SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
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
		if(tmp->getStage() == 7)
			SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "  ";
		if (tmp->getStage()>2) {
			cout << "__      ";
		}
		else {
			cout << "        ";
		}
		SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
	tmp = players;
	cout << endl << " ";
	for (; tmp != NULL; tmp = tmp->next) {
		if (tmp->getStage() == 7)
			SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_INTENSITY);
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
		SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
	tmp = players;
	cout << endl << " ";
	for (; tmp != NULL; tmp = tmp->next) {
		if (tmp->getStage() == 7)
			SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_INTENSITY);
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
		SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
	tmp = players;
	cout << endl << " ";
	for (; tmp != NULL; tmp = tmp->next) {
		if (tmp->getStage() == 7)
			SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_INTENSITY);
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
		SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
	tmp = players;
	cout << endl << " ";
	for (; tmp != NULL; tmp = tmp->next) {
		if (tmp->getStage() == 7)
			SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_INTENSITY);
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
		SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
	tmp = players;
	cout << endl << " ";
	for (; tmp != NULL; tmp = tmp->next) {
		if (tmp->getStage() == 7)
			SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << " " << tmp->getStage() << "/" << "7      ";
		SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
	cout << endl << endl;
}

int Screen::chousePlayerType(bool f) {
	if (system("CLS")) system("clear");
	cout << "\tChouse, will you play with friend or with computer? " << endl;
	cout << "\t\tb - bot" << endl;
	cout << "\t\th - human" << endl;
	if (f)
		cout << "\t\tend - finish creating players" << endl;
	string type;
	cout << "\t\t";
	cin >> type;
	transform(type.begin(), type.end(), type.begin(), ::tolower);
	if (f) {
		while (type != "b" && type != "h" && type != "end") {
			cout << "Invalid value" << endl << "\t\t";
			cin >> type;
			transform(type.begin(), type.end(), type.begin(), ::tolower);
		}
	}
	else {
		while (type != "b" && type != "h") {
			cout << "Invalid value" << endl << "\t\t";
			cin >> type;
			transform(type.begin(), type.end(), type.begin(), ::tolower);
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

void Screen::end() {
	SetConsoleTextAttribute(color, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << endl << endl;
	cout << "\t\t\tGAME OVER" << endl;
	cout << endl << endl;
	SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
}

bool Screen::restart() {
	cout << endl << "\tDo you want to play one more time? (y/n)\n\t";
	string c;
	cin >> c;
	transform(c.begin(), c.end(), c.begin(), ::tolower);
	if (c == "y")
		return true;
	end();
	return false;
}