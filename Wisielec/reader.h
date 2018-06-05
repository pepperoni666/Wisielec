#ifndef __READER_H__
#define __READER_H__
#define _CRT_SECURE_NO_DEPRECATE
#include <string>
#include <ctime>
using namespace std;

class Reader {
private:
	string guesed;
	string word;
	string used;
public:
	Reader();
	string getWord();
	string getUsed() { return used; }
};

#endif //__READER_H__