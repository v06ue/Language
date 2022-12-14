#include <iostream>
#include <string.h>
#include <algorithm>
#include "Language.h"

using namespace std;

Language::Language(string name, string sayHello, int alphabet, int year, bool canspeak) {
	this->name = name;
	this->sayHello = sayHello;
	this->alphabet = alphabet;
	this->year = year;
	this->canspeak = canspeak;
}

string Language::getName() const {
	return name;
}

string Language::getHello() const {
	return sayHello;
}

int Language::getAlphabet() const {
	return alphabet;
}

int Language::getYear() const {
	return year;
}

bool Language::getCanSpeak() const {
	return canspeak;;
}


string Language::toString() const {
	string speak;
	if (canspeak == 1)
		speak = "� ���� �� ��� ��������!";
	else speak = "� �� ���� �� ��� ��������...";
	return "����: " + name + ", \"������!\": " + sayHello + ", ���������� ���� � �������� : " + to_string(alphabet) + ", ����� ������ : " + to_string(year) + ", " + speak;
}

