#include "reader.h"

Reader::Reader() {
	FILE* f;
	srand(time(NULL));
	if ((f = fopen("word_pool.txt", "r")) != NULL) {
		char tmp[100];
		string tmp2;
		int n = 0, v = 0;
		while (fscanf(f, "%s\n", &tmp) == 1) {
				n++;
				fscanf(f, "%s\n", &tmp);
				string k = tmp;
				if (k.length() > 3)
					v++;
		}
		if (v == 0)
			return;
		rewind(f);
		do {
			int x = rand() % n;
			for (int i = 0; i < x; i++)
				fscanf(f, "%s\n", &tmp);
			string k = tmp;
			transform(k.begin(), k.end(), k.begin(), ::tolower);
			tmp2 = k;
		} while (tmp2.length() < 4);
		word = tmp2;
	}
	fclose(f);
}

string Reader::getWord() {
	string toRet;
	for (int i = 0; i < word.length(); i++) {
		if (guesed.find(word.at(i)) != string::npos)
			toRet += (char)toupper(word.at(i));
		else
			toRet += "_";
	}
	return toRet;
}

bool Reader::tryChar(string c) {
	if (word.find(c) != string::npos) {
		guesed += c;
		return true;
	}
	used += c;
	return false;
}

int Reader::tryWord(string s) {
	if (word.length() == s.length()) {
		if (word == s) {
			guesed = s;
			return 1;
		}
		else
			return 0;
	}
	else
		return 2;
}

bool Reader::isFinished() {
	if (getWord().find("_") == string::npos)
		return true;
	return false;
}