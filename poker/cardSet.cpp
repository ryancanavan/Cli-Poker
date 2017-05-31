#include "cardSet.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

int seed(int i) {
	return rand() % i;
}

cardSet::cardSet() {};

void cardSet::add(card x) {
	cards.push_back(x);
}

card cardSet::getFirst() {
	return cards.front();
}

void cardSet::remove(card x) {
	for (int i = 0; i < cards.size(); i++) {
		if (cards[i].getSuit() == x.getSuit() && cards[i].getValue() == x.getValue()) {
			cards.erase(cards.begin() + i);
		}
	}
}

int cardSet::size() {
	return cards.size();
}

void cardSet::shuffle() {
	srand(unsigned(time(0)));
	random_shuffle(cards.begin(), cards.end(), seed);
}

void cardSet::clear() {
	cards.clear();
}

string cardSet::print() {
	string output = "";
	for (int i = 0; i < cards.size(); i++) {
		output += cards[i].print();
		output += " ";
	}
	return output;
}