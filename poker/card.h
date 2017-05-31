#ifndef _card_
#define _card_

#include <string>

using namespace std;

class card {
private:
	string suit;
	string value;
public:
	card(string cardValue, string cardSuit); //constructor requires value and suit
	string getSuit(); //return suit (ex: C)
	string getValue(); //return value (ex: 7)
	string print(); //return card (ex: 5H)
};

#endif