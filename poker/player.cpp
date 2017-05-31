#include "player.h"
#include <iostream>

using namespace std;

player::player(string a, int b) {
	name = a;
	money = b;
	amountBet = 0;
	state = "active|nb";
}

void player::editMoney(int x) {
	money = money + x;
}

void player::deal(card x) {
	hand.add(x);
}

void player::clearHand() {
	hand.clear();
}

void player::setState(string x) {
	state = x;
}

void player::setHandResults(vector<int> x) {
	handResults = x;
}

void player::setAmountBet(int x) {
	amountBet = x;
}

int player::bet(int amount) {
	money -= amount;
	amountBet += amount;
	return amount;
}

cardSet player::getHand() {
	return hand;
}

vector<int> player::getHandResults() {
	return handResults;
}

string player::printName() {
	return name;
}

string player::printState() {
	return state;
}

void player::clearAmountBet() {
	amountBet = 0;
}

void player::clearHandResults() {
	handResults.clear();
}

int player::getAmountBet() {
	return amountBet;
}

int player::printMoney() {
	return money;
}