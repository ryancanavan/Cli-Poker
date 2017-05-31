#include "card.h"
#include "cardSet.h"
#include "player.h"
#include "board.h"
#include "compare.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

cardSet populate(cardSet deck) { //creates full deck of cards in order
	cardSet fullDeck;
	string suits[] = { "C", "D", "H", "S" };
	string values[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
	for (int j = 0; j < 13;  j++) {
		for (int i = 0; i < 4; i++) {
			fullDeck.add(card(values[j], suits[i]));
		}
	}
	return fullDeck;
}

void takeTurn(player &currentPlayer, vector<player> &players, board &currentGame) {
	system("cls"); //clear console
	string userDecision; //string for user input (ex: fold, bet, etc.)
	cout << "It is now your turn " << currentPlayer.printName() << endl; //print the name of player whos turn it is
	for (int i = 0; i < players.size(); i++) { //print out all users name and money
		if (players[i].printState() == "active|nb" || players[i].printState() == "active|b")
			cout << players[i].printName() << " - $" << players[i].printMoney() << "   ";
		if (players[i].printState() == "folded")
			cout << players[i].printName() << " (folded)- $" << players[i].printMoney() << "   ";
	}
	cout << "Pot - $" << currentGame.getPot(); //print out amount in pot
	cout << endl;
	cout << "River: " << currentGame.getRiver().print() << endl; //print out cards in river
	while (true) {
		if ((currentGame.getMaxBet() - currentPlayer.getAmountBet()) == 0 || currentPlayer.printMoney() == 0) {
			cout << "The following commands are available: Hand, Fold, Check, Bet" << endl << "> ";
			cin >> userDecision;
		}
		else if (currentPlayer.printMoney() < (currentGame.getMaxBet() - currentPlayer.getAmountBet())) { //if they do not have enough to fully call, let them go all in
			cout << "The following commands are available: Hand, Fold, Call($" << currentPlayer.printMoney() << "), Bet" << endl << "> ";
			cin >> userDecision;
		}
		else {
			cout << "The following commands are available: Hand, Fold, Call($" << currentGame.getMaxBet() - currentPlayer.getAmountBet() << "), Bet" << endl << "> ";
			cin >> userDecision;
		}
		if (userDecision == "Hand") { //show user their hand
			cout << currentPlayer.getHand().print() << endl;
		}
		else if (userDecision == "Fold") { //set the users state to fold and end turn
			currentPlayer.setState("folded");
			break;
		}
		else if ((currentGame.getMaxBet() - currentPlayer.getAmountBet()) != 0 && userDecision == "Call") { //bet the amount required and end turn
			if (currentPlayer.printMoney() < (currentGame.getMaxBet() - currentPlayer.getAmountBet())) {
				currentGame.addToPot(currentPlayer.bet(currentPlayer.printMoney()));
			}
			else //if they have enough money to call then bet that amount
				currentGame.addToPot(currentPlayer.bet(currentGame.getMaxBet() - currentPlayer.getAmountBet()));
			currentPlayer.setState("active|b");
			break;
		}
		else if ((currentGame.getMaxBet() - currentPlayer.getAmountBet()) == 0 || currentPlayer.printMoney() == 0 && userDecision == "Check") { //set state to have bet and move to next player
			currentPlayer.setState("active|b");
			break;
		}
		else if (userDecision == "Bet") { //request the amount the user wants to bet and then end turn
			int betAmount;
			while (true) {
				cout << "Insert the amount you want to bet: ";
				cin >> betAmount;
				if (betAmount <= (currentGame.getMaxBet() - currentPlayer.getAmountBet()) || betAmount > currentPlayer.printMoney())
					cout << "Invalid bet amount." << endl;
				else
					break;
			}
			currentGame.addToPot(currentPlayer.bet(betAmount));
			currentGame.setMaxBet(currentPlayer.getAmountBet());
			currentPlayer.setState("active|b");
			break;
		}
		else {
			cout << "Invalid input." << endl;
		}
	}
	
}

cardSet combine(cardSet a, cardSet b) {
	cardSet out;
	int aSize = a.size();
	int bSize = b.size();
	for (int i = 0; i < aSize; i++) {
		out.add(a.getFirst());
		a.remove(a.getFirst());
	}
	for (int i = 0; i < bSize; i++) {
		out.add(b.getFirst());
		b.remove(b.getFirst());
	}
	return out;
}

bool playerCompare(player a, player b) {
	return (a.getAmountBet() < b.getAmountBet());
}

int main(void) {
	cardSet deck; //total deck
	int playerAmount; //number of players
	int blind = 0; //start the blind with the 1st player
	vector<player> players; //filled with the players who are still in
	bool gameOver = false; //keeps entire game looping until finished
	board currentGame;
	while (true) { //user enters amount of players
		cout << "Type the amount of players: ";
		cin >> playerAmount;
		if (playerAmount < 2)
			cout << "Invalid amount of players. Value must be at least 2." << endl;
		else
			break;
	}

	for (int i = 1; i < playerAmount + 1; i++) { //Set up vector of players
		string name;
		while (true) { //make sure names are unique
			bool repeat = false;
			cout << "Type the name of player " << i << ": ";
			cin >> name;
			for (int i = 0; i < players.size(); i++) {
				if (name == players[i].printName()) {
					cout << "Name cannot be the same as another player." << endl;
					repeat = true;
				}
			}
			if (repeat == false)
				break;
		}
		players.push_back(player(name, 20000));
	}
	int smallBlind = 400;
	int gameRound = 1;
	while (gameOver == false) { //run until winner is found
		system("cls");
		for (int i = 0; i < players.size(); i++) { //print out all users name and money
			cout << players[i].printName() << " - $" << players[i].printMoney() << "   ";
		}
		cout << endl << endl;
		cout << "It is round " << gameRound << endl << endl;
		cout << "Blinds - " << players[blind].printName() << "($" << smallBlind << ")   " << players[(blind + 1) % players.size()].printName() << "($" << smallBlind*2 << ")" << endl << endl;
		system("pause");

		deck = populate(deck); //fill deck w/ all 52 cards
		deck.shuffle(); //randomize deck
		int round = 1; //round of betting
		for (int i = 0; i < players.size(); i++) { //deal everyone two cards
			players[i].deal(deck.getFirst());
			deck.remove(deck.getFirst());
			players[i].deal(deck.getFirst());
			deck.remove(deck.getFirst());
		}
		if (players[blind].printMoney() >= smallBlind) //if they have enough to pay small blind
			currentGame.addToPot(players[blind].bet(smallBlind)); //pay small blind
		else
			currentGame.addToPot(players[blind].bet(players[blind].printMoney())); //pay as much as they can
		if (players[(blind + 1) % players.size()].printMoney() >= (smallBlind * 2)) //if they have enough to pay big blind
			currentGame.addToPot(players[(blind + 1) % players.size()].bet(smallBlind * 2)); //pay big blind
		else
			currentGame.addToPot(players[(blind + 1) % players.size()].bet(players[(blind + 1) % players.size()].printMoney())); //pay as much as they can
		currentGame.setMaxBet(smallBlind*2);
		int loop = (blind + 2) % players.size(); //used to loop through players in each round
		int currentPlayers; //amount of players who are still in round (not folded)
		bool roundOver = false; //keeps round looping until finished
		while (roundOver == false) {
			currentPlayers = 0;
			for (int i = 0; i < players.size(); i++) { //find amount of players still in round
				if (players[i].printState() == "active|nb" || players[i].printState() == "active|b")
					currentPlayers++;
			}
			if (currentPlayers == 1) { //if only one player left then declare them the winner
				for (int i = 0; i < players.size(); i++) {
					if (players[i].printState() == "active|nb" || players[i].printState() == "active|b") {
						players[i].editMoney(currentGame.getPot());
						cout << players[i].printName() << " has won the hand!" << endl;
					}
				}
				system("pause");
				break;
			}
			int playersDoneBetting = 0;
			for (int i = 0; i < players.size(); i++) { //check if everyone is done betting
				if (players[i].printState() == "active|b") {
					playersDoneBetting++;
				}
			}
			if (playersDoneBetting == currentPlayers) { //move to second round
				if (round == 1) {
					for (int i = 0; i < 3; i++) { //3 cards into the river on 1st round
						currentGame.addToRiver(deck.getFirst());
						deck.remove(deck.getFirst());
						for (int i = 0; i < players.size(); i++) { //reset players bet status for next round of betting
							if (players[i].printState() != "folded")
								players[i].setState("active|nb");
						}
					}
					round++;
				}
				else if (round == 2 || round == 3) { //1 card into the river on 2nd and 3rd rounds
					currentGame.addToRiver(deck.getFirst());
					deck.remove(deck.getFirst());
					for (int i = 0; i < players.size(); i++) { //reset players bet status for next round of betting
						if (players[i].printState() != "folded")
							players[i].setState("active|nb");
					}
					round++;
				}
				else if (round == 4) { //find winner at end of round
					system("cls");
					vector<player> finalists, winners;
					for (int i = 0; i < players.size(); i++) {
						if (players[i].printState() != "folded") {
							cardSet total = combine(players[i].getHand(), currentGame.getRiver());
							players[i].setHandResults(findBestHand(total));
							finalists.push_back(players[i]);
						}
					}
					while (currentGame.getPot() > 0) {
						int numFinalists = finalists.size();
						winners = findWinner(finalists);
						if (winners.size() == 1) {
							for (int i = 0; i < players.size(); i++) {
								if (players[i].printName() == winners[0].printName()) {
									if (players[i].getAmountBet() == currentGame.getMaxBet()) {
										players[i].editMoney(currentGame.getPot());
										cout << players[i].printName() << " has won the pot!" << endl;
										currentGame.clearPot();
									}
									else {
										int removeAmount = players[i].getAmountBet();
										string removeName = players[i].printName();
										players[i].editMoney(players[i].getAmountBet() * numFinalists);
										currentGame.removeFromPot(players[i].getAmountBet() * numFinalists);
										cout << players[i].printName() << " has won a side pot for $" << players[i].getAmountBet() * numFinalists << "!" << endl;
										for (int j = 0; j < players.size(); j++) {
											players[j].setAmountBet(players[j].getAmountBet() - removeAmount);
										}
										for (int j = 0; j < finalists.size(); j++) {
											if (finalists[j].printName() == removeName) {
												finalists.erase(finalists.begin() + j);
												j = 0;
											}
										}
									}
								}
							}
						}
						else {
							sort(winners.begin(), winners.end(), playerCompare);
							int winnersSize = winners.size();
							int potSplit = currentGame.getPot() / winnersSize;
							for (int i = 0; i < winnersSize; i++) {
								for (int j = 0; j < players.size(); j++) {
									if (players[j].printName() == winners[i].printName()) {
										if (winners[0].getAmountBet() >= potSplit) { //if theyve paid the potSplit amount, they get their money back
											players[j].editMoney(potSplit);
											cout << players[j].printName() << " ";
											currentGame.clearPot();
										}
										else {
											int removeAmount = ((players.size() - i) * players[j].getAmountBet()) / winnersSize;
											int removeFromPotAmount = 0;
											string removeName = players[j].printName();
											for (int k = i; k < winnersSize; k++) {
												for (int l = 0; l < players.size(); l++) {
													if (players[l].printName() == winners[k].printName()) {
														players[l].editMoney(removeAmount);
														currentGame.removeFromPot(removeAmount);
													}
												}
											}
											cout << players[j].printName() << " ";
											for (int k = 0; k < players.size(); k++) {
												players[k].setAmountBet(players[k].getAmountBet() - players[j].getAmountBet());
											}
											for (int k = 0; k < finalists.size(); k++) {
												if (finalists[k].printName() == removeName) {
													finalists.erase(finalists.begin() + k);
													k = 0;
												}
											}
										}
									}	
								}
							}
							cout << " have split the pot for $" << potSplit << " each!" << endl;
						}
					}
					for (int i = 0; i < players.size(); i++) { //print out all users name and money
						if (players[i].printState() == "active|nb" || players[i].printState() == "active|b")
							cout << players[i].printName() << " - $" << players[i].printMoney() << "   ";
						if (players[i].printState() == "folded")
							cout << players[i].printName() << " (folded)- $" << players[i].printMoney() << "   ";
					}
					cout << endl;
					cout << "River: " << currentGame.getRiver().print() << endl; //print out cards in river

					for (int i = 0; i < players.size(); i++) {
						if (players[i].printState() != "folded") {
							cout << players[i].printName() << " - ";
							if (players[i].getHandResults()[0] == 9)
								cout << "Straight flush";
							else if (players[i].getHandResults()[0] == 8)
								cout << "Four of a kind";
							else if (players[i].getHandResults()[0] == 7)
								cout << "Full house";
							else if (players[i].getHandResults()[0] == 6)
								cout << "Flush";
							else if (players[i].getHandResults()[0] == 5)
								cout << "Straight";
							else if (players[i].getHandResults()[0] == 4)
								cout << "Three of a kind";
							else if (players[i].getHandResults()[0] == 3)
								cout << "Two pair";
							else if (players[i].getHandResults()[0] == 2)
								cout << "One pair";
							else if (players[i].getHandResults()[0] == 1)
								cout << "High card";
							cout << " ( " << players[i].getHand().print() << ")" << endl;
						}
					}

					system("pause");
					break;
				}
			}
			if(players[loop].printState() != "folded")
				takeTurn(players[loop], players, currentGame); //take turn betting if they have not folded
			loop = (loop + 1) % players.size(); //move to next player
		}
		for (int i = 0; i < players.size();) {
			if (players[i].printMoney() == 0) {
				players.erase(players.begin() + i);
				i = 0;
			}
			else
				i++;
		}
		if (players.size() == 1)
			gameOver = true;

		round = 1;
		currentGame.clearMaxBet(); //reset board for next round
		currentGame.clearRiver();
		if (gameRound % 5 == 0) {
			smallBlind += 200;
		}
		gameRound++;
		for (int i = 0; i < players.size(); i++) { //reset players for next round
			players[i].clearHand();
			players[i].clearAmountBet();
			players[i].setState("active|nb");
			players[i].clearHandResults();
		}
		blind = (blind + 1) % players.size(); //move blind to next player
	}
	system("cls");
	cout << players[0].printName() << " has won the game! Congratulations!" << endl << endl;
	cout << "Thanks for playing!" << endl << endl;
	cout << "Made by Ryan Canavan" << endl << endl;
	system("pause");

	return 0;
}