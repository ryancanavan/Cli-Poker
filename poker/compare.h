#include "cardSet.h"
#include <iostream>

using namespace std;

vector<int> whereExists(int start, int end, int findIn[]) {
	vector<int> output;
	for (int i = start; i < end + 1; i++) {
		if (findIn[i] > 0) {
			output.push_back(i);
		}
	}
	return output;
}

vector<int> isStraight(vector<int> positions) {
	vector<int> output;
	if (positions.size() == 5) {
		if (positions[0] + 1 == positions[1] && positions[1] + 1 == positions[2] && positions[2] + 1 == positions[3] && positions[3] + 1 == positions[4]) {
			output.push_back(1);
			output.push_back(positions[4]);
			output.push_back(positions[3]);
			output.push_back(positions[2]);
			output.push_back(positions[1]);
			output.push_back(positions[0]);
			return output;
		}
		else {
			output.push_back(0);
			return output;
		}
	}
	else if (positions.size() == 6) {
		if (positions[0] + 1 == positions[1] && positions[1] + 1 == positions[2] && positions[2] + 1 == positions[3] && positions[3] + 1 == positions[4]){
			output.push_back(1);
			output.push_back(positions[4]);
			output.push_back(positions[3]);
			output.push_back(positions[2]);
			output.push_back(positions[1]);
			output.push_back(positions[0]);
			return output;
	}
		else if (positions[1] + 1 == positions[2] && positions[2] + 1 == positions[3] && positions[3] + 1 == positions[4] && positions[4] + 1 == positions[5]){
			output.push_back(1);
			output.push_back(positions[5]);
			output.push_back(positions[4]);
			output.push_back(positions[3]);
			output.push_back(positions[2]);
			output.push_back(positions[1]);
			return output;
	}
		else {
			output.push_back(0);
			return output;
		}
	}
	else if (positions.size() == 7) {
		if (positions[0] + 1 == positions[1] && positions[1] + 1 == positions[2] && positions[2] + 1 == positions[3] && positions[3] + 1 == positions[4]){
			output.push_back(1);
			output.push_back(positions[4]);
			output.push_back(positions[3]);
			output.push_back(positions[2]);
			output.push_back(positions[1]);
			output.push_back(positions[0]);
			return output;
		}
		else if (positions[1] + 1 == positions[2] && positions[2] + 1 == positions[3] && positions[3] + 1 == positions[4] && positions[4] + 1 == positions[5]){
			output.push_back(1);
			output.push_back(positions[5]);
			output.push_back(positions[4]);
			output.push_back(positions[3]);
			output.push_back(positions[2]);
			output.push_back(positions[1]);
			return output;
		}
		else if (positions[2] + 1 == positions[3] && positions[3] + 1 == positions[4] && positions[4] + 1 == positions[5] && positions[5] + 1 == positions[6]){
			output.push_back(1);
			output.push_back(positions[6]);
			output.push_back(positions[5]);
			output.push_back(positions[4]);
			output.push_back(positions[3]);
			output.push_back(positions[2]);
			return output;
		}
		else {
			output.push_back(0);
			return output;
		}
	}
	else if (positions.size() == 8) {
		if (positions[0] + 1 == positions[1] && positions[1] + 1 == positions[2] && positions[2] + 1 == positions[3] && positions[3] + 1 == positions[4]){
			output.push_back(1);
			output.push_back(positions[4]);
			output.push_back(positions[3]);
			output.push_back(positions[2]);
			output.push_back(positions[1]);
			output.push_back(positions[0]);
			return output;
		}
		else if (positions[3] + 1 == positions[4] && positions[4] + 1 == positions[5] && positions[5] + 1 == positions[6] && positions[6] + 1 == positions[7]){
			output.push_back(1);
			output.push_back(positions[7]);
			output.push_back(positions[6]);
			output.push_back(positions[5]);
			output.push_back(positions[4]);
			output.push_back(positions[3]);
			return output;
		}
		else {
			output.push_back(0);
			return output;
		}
	}
	else{
		output.push_back(0);
		return output;
	}
}

vector<int> flushHighCards(cardSet limitSuit, string s) {
	vector<int> output;
	cardSet cards;
	int limitSuitSize = limitSuit.size();
	for (int i = 0; i < limitSuitSize; i++) {
		if (limitSuit.getFirst().getSuit() == s)
			cards.add(limitSuit.getFirst());
		limitSuit.remove(limitSuit.getFirst());
	}
	int cardSize = cards.size();
	int countByValue[14] = { 0 }; //array of values
	for (int i = 0; i < cardSize; i++) { //count amount of cards with each value
		if (cards.getFirst().getValue() == "2") {
			countByValue[1]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getValue() == "3") {
			countByValue[2]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getValue() == "4") {
			countByValue[3]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getValue() == "5") {
			countByValue[4]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getValue() == "6") {
			countByValue[5]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getValue() == "7") {
			countByValue[6]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getValue() == "8") {
			countByValue[7]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getValue() == "9") {
			countByValue[8]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getValue() == "10") {
			countByValue[9]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getValue() == "J") {
			countByValue[10]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getValue() == "Q") {
			countByValue[11]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getValue() == "K") {
			countByValue[12]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getValue() == "A") {
			countByValue[13]++;
			countByValue[0]++;
			cards.remove(cards.getFirst());
		}
	}
	for (int i = 13; i >= 0; i--) { //add value of highest card in suit
		if (countByValue[i] != 0) {
			output.push_back(i);
			break;
		}
	}
	for (int i = 13; i >= 0; i--) { //add value of next highest card in suit
		if (countByValue[i] != 0 && i != output[0]) {
			output.push_back(i);
			break;
		}
	}
	for (int i = 13; i >= 0; i--) { //add value of next highest card in suit
		if (countByValue[i] != 0 && i != output[0] && i != output[1]) {
			output.push_back(i);
			break;
		}
	}
	for (int i = 13; i >= 0; i--) { //add value of next highest card in suit
		if (countByValue[i] != 0 && i != output[0] && i != output[1] && i != output[2]) {
			output.push_back(i);
			break;
		}
	}
	for (int i = 13; i >= 0; i--) { //add value of next highest card in suit
		if (countByValue[i] != 0 && i != output[0] && i != output[1] && i != output[2] && i != output[3]) {
			output.push_back(i);
			break;
		}
	}
	return output;
}

vector<int> findBestHand(cardSet cards) {
	cardSet temp = cards; //copy so that we can check for suit after value
	vector<int> output; //vector used to put output data in
	int cardSize = cards.size();
	int countByValue[14] = { 0 }; //array of values
	int countBySuit[4] = { 0 }; //array of suits
	for (int i = 0; i < cardSize; i++) { //count amount of cards with each value
		if (cards.getFirst().getValue() == "2") {
			countByValue[1]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getValue() == "3") {
			countByValue[2]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getValue() == "4") {
			countByValue[3]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getValue() == "5") {
			countByValue[4]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getValue() == "6") {
			countByValue[5]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getValue() == "7") {
			countByValue[6]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getValue() == "8") {
			countByValue[7]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getValue() == "9") {
			countByValue[8]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getValue() == "10") {
			countByValue[9]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getValue() == "J") {
			countByValue[10]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getValue() == "Q") {
			countByValue[11]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getValue() == "K") {
			countByValue[12]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getValue() == "A") {
			countByValue[13]++;
			countByValue[0]++;
			cards.remove(cards.getFirst());
		}
	}
	cards = temp; //fill cards back up
	for (int i = 0; i < cardSize; i++) { //count amount of cards with each suit
		if (cards.getFirst().getSuit() == "C") {
			countBySuit[0]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getSuit() == "D") {
			countBySuit[1]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getSuit() == "H") {
			countBySuit[2]++;
			cards.remove(cards.getFirst());
		}
		else if (cards.getFirst().getSuit() == "S") {
			countBySuit[3]++;
			cards.remove(cards.getFirst());
		}
	
	}
	cards = temp;
	int *flush, *fourOfAKind, *threeOfAKind, *twoOfAKind, *twoPair, twoPosition; //pointers used for find function
	flush = find(countBySuit, countBySuit + 4, 5); //check if there are five of a suit
	fourOfAKind = find(countByValue, countByValue + 14, 4); //check if there are four of a card value
	threeOfAKind = find(countByValue, countByValue + 14, 3); //check if there are three of a card value
	twoOfAKind = find(countByValue, countByValue + 14, 2); //check if there are two of a card value
	if (twoOfAKind != countByValue + 14) {
		for (int i = 0; i < 14; i++) {
			if (countByValue[i] == 2) {
				twoPosition = i;
				break;
			}
		}
		twoPair = find(countByValue + twoPosition + 1, countByValue + 14, 2); //check for a second instance of two cards of a value
	}
	else {
		twoPair = find(countByValue, countByValue + 14, 2);
	}
	vector<int> positions = whereExists(0, 13, countByValue); //vector of where the values are (to check for straights)
	vector<int> isStraightResults;
	isStraightResults = isStraight(positions);
	if (flush != countBySuit + 4 && isStraightResults[0] == 1) { //check for straight flush
		output.push_back(9);
		output.push_back(isStraightResults[1]); //add value of straight high card
		return output;
	}
	else if (fourOfAKind != countByValue + 14) { //check for four of a kind
		output.push_back(8);
		for (int i = 0; i < 14; i++) { //add value of four of a kind
			if (countByValue[i] == 4) {
				output.push_back(i);
				break;
			}
		}
		for (int i = 13; i >= 0; i--) { //add value of 5th card
			if (countByValue[i] != 0 && countByValue[i] != 4) {
				output.push_back(i);
				break;
			}
		}
		return output;
	}
	else if (threeOfAKind != countByValue + 14 && twoOfAKind != countByValue + 14) { //check for a full house
		output.push_back(7);
		for (int i = 13; i >= 0; i--) { //add value of the three of a kind
			if (countByValue[i] == 3) {
				output.push_back(i);
				break;
			}
		}
		for (int i = 13; i >= 0; i--) { //add value of the two of a kind
			if (countByValue[i] == 2) {
				output.push_back(i);
				break;
			}
		}
		return output;
	}
	else if (flush != countBySuit + 4) { //check for flush
		output.push_back(6);
		vector<int> result;
		string input;
		for (int i = 13; i >= 0; i--) {
			if (countBySuit[i] == 5) {
				if (i == 0)
					input = "C";
				else if (i == 1)
					input = "D";
				else if (i == 2)
					input = "H";
				else
					input = "S";
				break;
			}
		}
		result = flushHighCards(cards, input);
		for (int i = 0; i < result.size(); i++) {
			output.push_back(result[i]);
		}
		return output;
	}
	else if (isStraightResults[0] == 1) { //check for straight
		output.push_back(5);
		output.push_back(isStraightResults[1]);
		output.push_back(isStraightResults[2]);
		output.push_back(isStraightResults[3]);
		output.push_back(isStraightResults[4]);
		output.push_back(isStraightResults[5]);
		return output;
	}
	else if (threeOfAKind != countByValue + 14) { //check for three of a kind
		output.push_back(4);
		for (int i = 13; i >= 0; i--) { //add value of the three of a kind
			if (countByValue[i] == 3) {
				output.push_back(i);
				break;
			}
		}
		for (int i = 13; i >= 0; i--) { //add value of highest card not in 3 of a kind
			if (countByValue[i] != 0 && countByValue[i] != 3) {
				output.push_back(i);
				break;
			}
		}
		for (int i = 13; i >= 0; i--) { //add value of the next highest card not in 3 of a kind
			if (countByValue[i] != 0 && countByValue[i] != 3 && i != output[2]) {
				output.push_back(i);
				break;
			}
		}
		return output;
	}
	else if (twoOfAKind != countByValue + 14 && twoPair != countByValue + 14) { //check for two pair
		output.push_back(3);
		for (int i = 13; i >= 0; i--) { //add value of the highest two of a kind
			if (countByValue[i] == 2) {
				output.push_back(i);
				break;
			}
		}
		for (int i = 13; i >= 0; i--) { //add value of the next highest two of a kind
			if (countByValue[i] == 2 && i != output[1]) {
				output.push_back(i);
				break;
			}
		}
		for (int i = 13; i >= 0; i--) { //add value of the next highest two of a kind
			if (countByValue[i] != 0 && countByValue[i] != 2) {
				output.push_back(i);
				break;
			}
		}
		return output;
	}
	else if (twoOfAKind != countByValue + 14) { //check for pair
		output.push_back(2);
		for (int i = 13; i >= 0; i--) { //add value of the two of a kind
			if (countByValue[i] == 2) {
				output.push_back(i);
				break;
			}
		}
		for (int i = 13; i >= 0; i--) { //add value of highest card not in 2 of a kind
			if (countByValue[i] != 0 && countByValue[i] != 2) {
				output.push_back(i);
				break;
			}
		}
		for (int i = 13; i >= 0; i--) { //add value of the next highest card not in 2 of a kind
			if (countByValue[i] != 0 && countByValue[i] != 2 && i != output[2]) {
				output.push_back(i);
				break;
			}
		}
		for (int i = 13; i >= 0; i--) { //add value of the next highest card not in 2 of a kind
			if (countByValue[i] != 0 && countByValue[i] != 2 && i != output[2] && i != output[3]) {
				output.push_back(i);
				break;
			}
		}
		return output;
	}
	else { //check for high card
		output.push_back(1);
		for (int i = 13; i >= 0; i--) { //add value of highest card
			if (countByValue[i] != 0) {
				output.push_back(i);
				break;
			}
		}
		for (int i = 13; i >= 0; i--) { //add value of next highest card
			if (countByValue[i] != 0 && i != output[1]) {
				output.push_back(i);
				break;
			}
		}
		for (int i = 13; i >= 0; i--) { //add value of next highest card
			if (countByValue[i] != 0 && i != output[1] && i != output[2]) {
				output.push_back(i);
				break;
			}
		}
		for (int i = 13; i >= 0; i--) { //add value of next highest card
			if (countByValue[i] != 0 && i != output[1] && i != output[2] && i != output[3]) {
				output.push_back(i);
				break;
			}
		}
		for (int i = 13; i >= 0; i--) { //add value of next highest card
			if (countByValue[i] != 0 && i != output[1] && i != output[2] && i != output[3] && i != output[4]) {
				output.push_back(i);
				break;
			}
		}
		return output;
	}
}

player compare(player a, player b) {
	player c("Tie", 0);
	if (a.getHandResults()[0] > b.getHandResults()[0])
		return a;
	else if (a.getHandResults()[0] < b.getHandResults()[0])
		return b;
	else {
		if (a.getHandResults()[1] > b.getHandResults()[1]) //Tiebreaker 1
			return a;
		else if (a.getHandResults()[1] < b.getHandResults()[1])
			return b;
		else {
			if (a.getHandResults().size() == 2)
				return c;
			else if (a.getHandResults()[2] > b.getHandResults()[2]) //Tiebreaker 2
				return a;
			else if (a.getHandResults()[2] < b.getHandResults()[2])
				return b;
			else {
				if (a.getHandResults().size() == 3)
					return c;
				else if (a.getHandResults()[3] > b.getHandResults()[3]) //Tiebreaker 3
					return a;
				else if (a.getHandResults()[3] < b.getHandResults()[3])
					return b;
				else {
					if (a.getHandResults().size() == 4)
						return c;
					else if (a.getHandResults()[4] > b.getHandResults()[4]) //Tiebreaker 4
						return a;
					else if (a.getHandResults()[4] < b.getHandResults()[4])
						return b;
					else {
						if (a.getHandResults().size() == 5)
							return c;
						else if (a.getHandResults()[5] > b.getHandResults()[5]) //Tiebreaker 5
							return a;
						else if (a.getHandResults()[5] < b.getHandResults()[5])
							return b;
						else
							return c;
					}
				}
			}
		}
	}
}

vector<player> findWinner(vector<player> players) {
	if (players.size() == 1)
		return players;
	player tie("Tie", 0);
	vector<player> output;
	bool player0tie, player1tie;
	if (players.size() == 2) { //final iteration
		player winner = compare(players[0], players[1]);
			if (winner.printName() == players[0].printName()) { //if winner of last comparison is 1st
				player0tie = false;
				for (int i = 0; i < output.size(); i++) {
					if (output[i].printName() == players[0].printName())
						player0tie = true;
				}
				if (player0tie == true) //if they are in the tied list
					return output;
				else { //if they are not in the tied list
					output.clear();
					output.push_back(players[0]);
					return output;
				}
			}
			else if (winner.printName() == players[1].printName()) { //if winner of last comparison is 2nd
				player1tie = false;
				for (int i = 0; i < output.size(); i++) {
					if (output[i].printName() == players[1].printName())
						player1tie = true;
				}
				if (player1tie == true) //if they are in the tied list
					return output;
				else { //if they are not in the tied list
					output.clear();
					output.push_back(players[1]);
					return output;
				}
			}
			else { //if the last comparison is a tie
				player0tie = false;
				for (int i = 0; i < output.size(); i++) {
					if (output[i].printName() == players[0].printName())
						player0tie = true;
				}
				player1tie = false;
				for (int i = 0; i < output.size(); i++) {
					if (output[i].printName() == players[1].printName())
						player1tie = true;
				}
				if (player0tie == true && player1tie == false) //if the first is in the tied list but the second isnt
					output.push_back(players[1]);
				else if (player0tie == false && player1tie == true) //if the first is not in the tied list but the second is
					output.push_back(players[0]);
				else if (player0tie == false && player1tie == false) { //if neither are in the list
					output.clear();
					output.push_back(players[0]);
					output.push_back(players[1]);
				}
				return output;
			}
	}
	else {
		player winner = compare(players[0], players[1]);
		if (winner.printName() == players[0].printName()) {
			player0tie = false;
			for (int i = 0; i < output.size(); i++) {
				if (output[i].printName() == players[0].printName())
					player0tie = true;
			}
			if (player0tie == true) { //if the winner of comparison is in tied list, erase other and move on
				players.erase(players.begin() + 1);
				return findWinner(players);
			}
			else { //if the winner of comparison is not in tied list, clear tied list and move on
				output.clear();
				players.erase(players.begin() + 1);
				return findWinner(players);
			}
		}
		else if (winner.printName() == players[1].printName()) {
			player1tie = false;
			for (int i = 0; i < output.size(); i++) {
				if (output[i].printName() == players[1].printName())
					player1tie = true;
			}
			if (player1tie == true) { //if the winner of comparison is in tied list, erase other and move on
				players.erase(players.begin());
				return findWinner(players);
			}
			else { //if the winner of comparison is not in tied list, clear tied list and move on
				output.clear();
				players.erase(players.begin());
				return findWinner(players);
			}
		}
		else { //if comparison is a tie
			player0tie = false;
			for (int i = 0; i < output.size(); i++) {
				if (output[i].printName() == players[0].printName())
					player0tie = true;
			}
			player1tie = false;
			for (int i = 0; i < output.size(); i++) {
				if (output[i].printName() == players[1].printName())
					player1tie = true;
			}
			if (player0tie == true && player1tie == false) //if the first is in the tied list but the second isnt
				output.push_back(players[1]);
			else if (player0tie == false && player1tie == true) //if the first is not in the tied list but the second is
				output.push_back(players[0]);
			else if (player0tie == false && player1tie == false) { //if neither are in the list
				output.clear();
				output.push_back(players[0]);
				output.push_back(players[1]);
			}
			players.erase(players.begin());
			return findWinner(players);
		}
	}
}