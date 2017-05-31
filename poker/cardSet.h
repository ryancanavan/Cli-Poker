#ifndef _cardSet_
#define _cardSet_

#include "card.h"
#include <string>
#include <vector>

using namespace std;

class cardSet {
private:
	vector<card> cards;
public:
	cardSet(); //construct empty vector
	void add(card x); //add card to end of vector
	card getFirst();
	void remove(card x); //remove specific card from vector
	int size(); //return size of vector
	void shuffle(); //randomize vector
	void clear(); //empty vector
	string print(); //print out vector in order
};

#endif