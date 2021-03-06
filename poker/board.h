#ifndef _board_
#define _board_

#include "cardSet.h"

using namespace std;

class board {
private:
	int pot;
	int maxBet;
	cardSet river;
	bool devMode;
public:
	board();
	void addToPot(int x);
	void removeFromPot(int x);
	void setMaxBet(int x);
	void addToRiver(card x);
	void setDevMode(bool x);
	bool getDevMode();
	int getPot();
	int getMaxBet();
	cardSet getRiver();
	void clearPot();
	void clearMaxBet();
	void clearRiver();
};

#endif