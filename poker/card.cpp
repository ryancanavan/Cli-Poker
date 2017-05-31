#include "card.h"
#include <iostream>
#include <string>

using namespace std;

card::card(string cardValue, string cardSuit) {
	suit = cardSuit;
	value = cardValue;
}

string card::getSuit() {
	return suit;
}

string card::getValue() {
	return value;
}

string card::print() {
	string output;
	output = value + suit;
	return output;
}