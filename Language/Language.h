#pragma once

#include <iostream>
#include <string>


using namespace std;

class Language
{
	string name;
	string sayHello;
	int alphabet;
	int year;
	bool canspeak;
public:
	Language(string name, string sayHello, int alphabet, int year, bool canspeak);
	string getName() const;
	string getHello() const;
	int getAlphabet() const;
	int getYear() const;
	bool getCanSpeak() const;

	string toString() const;

};