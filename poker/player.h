#ifndef _player_
#define _player_

#include "card.h"
#include "cardSet.h"
#include <string>
#include <vector>

using namespace std;

class player {
private:
	string name;
	int money;
	cardSet hand;
	int amountBet;
	string state;
	vector<int> handResults;
public:
	player(string a, int b); //constructor requires name and starting money
	void editMoney(int x); //edit player's money (positive number to add and negative to remove)
	void deal(card x); //adds a card to players hand
	void clearHand(); //empties hand
	void setState(string x); //set player's state
	void setHandResults(vector<int> x); //set hand results
	void setAmountBet(int x);
	int bet(int amount); //allows player to bet
	cardSet getHand(); //return player's cards in hand
	vector<int> getHandResults(); //return players hand results vector
	string printName(); //return player's name
	string printState(); //return current player state (ex: active, folded)
	void clearAmountBet();
	void clearHandResults(); //clear hand results
	int getAmountBet(); //return amount theyve bet in the round
	void setAmountBet();
	int printMoney(); //return player's money
};

#endif