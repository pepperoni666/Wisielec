#include "reader.h"

Reader::Reader() {
	FILE* f;
	srand(time(NULL));
	if ((f = fopen("word_pool.txt", "r")) != NULL) {
		char tmp[100];
		string tmp2;
		int n = 0;
		while (fscanf(f, "%s\n", &tmp) == 1) {
				n++;
		}
		rewind(f);
		do {
			int x = rand() % n;
			for (int i = 0; i < x; i++)
				fscanf(f, "%s\n", &tmp);
			string k = tmp;
			tmp2 = k;
		} while (tmp2.length() < 4);
		word = tmp2;
		//TODO: opcja na pusty plik lub brak dobrych slow
	}
	fclose(f);
}

string Reader::getWord() {
	string toRet = "";
	for (int i = 0; i < word.length(); i++) {
		if (guesed.find(word.at(i)) != string::npos)
			toRet += (char)toupper(word.at(i));
		else
			toRet += "_";
	}
	return toRet;
}