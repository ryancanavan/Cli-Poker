#include "board.h"

using namespace std;

board::board() {
	pot = 0;
	maxBet = 0;
}

void board::addToPot(int x) {
	pot += x;
}

void board::removeFromPot(int x) {
	pot -= x;
}

void board::setMaxBet(int x) {
	maxBet = x;
}

void board::addToRiver(card x) {
	river.add(x);
}

int board::getPot() {
	return pot;
}

int board::getMaxBet() {
	return maxBet;
}

cardSet board::getRiver() {
	return river;
}

void board::clearPot() {
	pot = 0;
}

void board::clearMaxBet() {
	maxBet = 0;
}

void board::clearRiver() {
	river.clear();
}