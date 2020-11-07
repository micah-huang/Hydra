#include "model.h"
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <random>
#include "card.h"
#include "head.h"
#include <memory>



void Model::init(size_t num_players) {
	// initialize players
	for (size_t k = 0; k < num_players; k++) {
		players.emplace_back(std::make_shared<Player>(k+1));
	}



	// initialize players' decks
	std::vector<std::shared_ptr<Card>> starting_deck;

	for (size_t j = 0; j < num_players; j++) {
		for (size_t i = 1; i < 15; i++) {
			if ( i == 14 ) {
				starting_deck.emplace_back(std::make_shared<Card>("2", "J"));
				starting_deck.emplace_back(std::make_shared<Card>("2", "J"));
			} else {
				if ( i == 1 ) {
					starting_deck.emplace_back(std::make_shared<Card>("A", "D"));
					starting_deck.emplace_back(std::make_shared<Card>("A", "C"));
					starting_deck.emplace_back(std::make_shared<Card>("A", "H"));
					starting_deck.emplace_back(std::make_shared<Card>("A", "S"));
				} else if (i == 11) {
					starting_deck.emplace_back(std::make_shared<Card>("J", "D"));
					starting_deck.emplace_back(std::make_shared<Card>("J", "C"));
					starting_deck.emplace_back(std::make_shared<Card>("J", "H"));
					starting_deck.emplace_back(std::make_shared<Card>("J", "S"));
				}else if (i == 12) {
					starting_deck.emplace_back(std::make_shared<Card>("Q", "D"));
					starting_deck.emplace_back(std::make_shared<Card>("Q", "C"));
					starting_deck.emplace_back(std::make_shared<Card>("Q", "H"));
					starting_deck.emplace_back(std::make_shared<Card>("Q", "S"));
				} else if ( i == 13 ) {
					starting_deck.emplace_back(std::make_shared<Card>("K", "D"));
					starting_deck.emplace_back(std::make_shared<Card>("K", "C"));
					starting_deck.emplace_back(std::make_shared<Card>("K", "H"));
					starting_deck.emplace_back(std::make_shared<Card>("K", "S"));
				} else {
					starting_deck.emplace_back(std::make_shared<Card>(to_string(i), "D"));
					starting_deck.emplace_back(std::make_shared<Card>(to_string(i), "C"));
					starting_deck.emplace_back(std::make_shared<Card>(to_string(i), "H"));
					starting_deck.emplace_back(std::make_shared<Card>(to_string(i), "S"));
				}
			}

		}
	}

	random_shuffle (starting_deck.begin(), starting_deck.end());
	size_t current_player_index_init = 0;
	current_player_index = 0;
	for ( size_t h = 0; h < starting_deck.size(); h++ ) {
		if (players.at(current_player_index_init)->draw_pile.cards.size() == 54) {
			current_player_index_init += 1;
		}
		players.at(current_player_index_init)->draw_pile.cards.emplace_back(starting_deck.at(h));
	}

	std::shared_ptr<Head> first_head = std::make_shared<Head>(1);
	if (testing_mode) {
		std::string value;
		while(true)

			// run the infinite while loop that we've seen before
			while(true) {
				if (!(cin >> value)) {
					cin.clear();
					cin.ignore();
					cout << "Please enter a positive integer greater than 1" << endl;
					continue;
				} else if (num_players < 2) {
					cin.clear();
					cin.ignore();
					cout << "Please enter a positive integer greater than 1" << endl;
					continue;
				}
			}
		if (value != "Joker") {
			// update the value
		}
	}
	first_head->cards.emplace_back(players.at(current_player_index)->drawCard());
	heads.emplace_back(first_head);
	total_heads = 1;
	current_player_index += 1;



	cout << "Heads:" << endl;
	for (size_t j = 0; j < heads.size(); j++) {
		cout << heads.at(j)->number << ": ";
		std::shared_ptr<Card> top_card = heads.at(j)->cards.back();
		cout << *top_card << " ";
		cout << "(" << heads.at(j)->cards.size() << ")" << endl;
		cout << endl;
	}
	cout << "Players:" << endl;
	for (size_t i = 0; i < players.size(); i++) {
		cout << "Player " << i+1 << ": ";
		size_t drawpile_cards = players.at(i)->draw_pile.cards.size();
		size_t discardpile_cards = players.at(i)->discard_pile.cards.size();
		size_t total_cards = drawpile_cards + discardpile_cards;
		cout << total_cards << " ";
		cout << "(" << drawpile_cards << " draw, ";
		cout << discardpile_cards << " discard)" << endl;
	}

	cout << endl;
	cout << endl;
	cout << endl;
}



void Model::state(std::shared_ptr<Player> player_turn, size_t moves_remaining) {
	cout << "Heads:" << endl;
	for (size_t j = 0; j < heads.size(); j++) {
		cout << heads.at(j)->number << ": ";
		std::shared_ptr<Card> top_card = heads.at(j)->cards.back();
		cout << *top_card << " ";
		cout << "(" << heads.at(j)->cards.size() << ")" << endl;
		cout << endl;
	}
	cout << "Players:" << endl;
	for (size_t i = 0; i < players.size(); i++) {
		cout << "Player " << i+1 << ": ";
		size_t drawpile_cards = players.at(i)->draw_pile.cards.size();
		size_t discardpile_cards = players.at(i)->discard_pile.cards.size();
		size_t total_cards = drawpile_cards + discardpile_cards;
		cout << total_cards << " ";
		cout << "(" << drawpile_cards << " draw, ";
		cout << discardpile_cards << " discard)";
		if (player_turn == players.at(i)) {
			cout << " + 1 in hand, ";
			cout << moves_remaining << " remaining, " << "0 in reserve" << endl;
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
}

size_t getHeadIndex(std::deque<std::shared_ptr<Head>> heads, size_t head_number) {
	for (size_t i = 0; i < heads.size(); i++) {
		if (head_number == heads.at(i)->number) {
			return i;
		}
	} 
	return heads.size();
}


bool Model::unplayable(std::deque<std::shared_ptr<Head>> heads, std::shared_ptr<Card> card) {
	for (size_t head_index = 0; head_index < heads.size(); head_index++) {
		if (card->numerical_value() <= ((heads[head_index])->top_card())->numerical_value()) {
			return false;
		}
	}
	return true;
}

void Model::turn() {
	size_t move;
	current_player = players.at(current_player_index);

	for (int moves = (heads.size()-1); moves >= 0; moves--) { 
		cout << "Player " << current_player->number << ", it is your turn" << endl;
		cout << endl;



		std::shared_ptr<Card> hand = current_player->drawCard();
		Model::state(current_player, moves);
		cout << "Player " << current_player->number << ", you are holding a ";
		cout << *hand << "."; 

		if (hand->suit == "J") {
			cout << "What value would you like the Joker to have? (A, 2-10, J, Q, K)" << endl;
			std::string updated_value;
			cin >> updated_value;
			hand->setValue(updated_value);
			cout << " Your move?" << endl;
			cout << endl;
		} else {
			cout << " Your move?" << endl;
			cout << endl;
		}

		if (unplayable(heads, hand)) {
			total_heads += 1;
			heads.emplace_back(std::make_shared<Head>(total_heads));
			heads.back()->cards.emplace_back(players.at(current_player_index)->drawCard());
			total_heads += 1;
			heads.emplace_back(std::make_shared<Head>(total_heads));
			heads.back()->cards.emplace_back(players.at(current_player_index)->drawCard());
			heads.pop_front();
			for (size_t i = 0; i < heads.front()->cards.size(); i++) {
				players.at(current_player_index)->discard_pile.cards.emplace_back(heads.front()->cards[i]);
			}
			cout << "You have no possible moves, cut heads" << endl;
			break;
		} else {
			//  read in the move and check for possible errors

			while(true) {
				if (cin.eof()) {
					exit(0);
				}
				if (!(cin >> move)) {
					cin.clear();
					cin.ignore();
					cout << "Please enter a valid positive integer input" << endl;
					cout << endl;
					continue;
				} else if (getHeadIndex(heads, move) == heads.size()) {
					cin.clear();
					cin.ignore();
					cout << "The head you selected is not a valid move, please enter a new valid move:" << endl;
					continue;
				} else if (hand->numerical_value() > (heads.at(getHeadIndex(heads, move))->cards.back()->numerical_value())) {
					cin.clear();
					cin.ignore();
					cout << "The head you selected is not a valid move, please enter a new valid move:" << endl;
					continue;
				}
				break;
			}
			size_t head_index = getHeadIndex(heads, move);
			// put card onto head:
			heads.at(head_index)->cards.emplace_back(hand);

			cout << endl;
			cout << endl;
			cout << endl;
		}


	}

	if (current_player_index == (players.size() - 1)) {
		current_player_index = 0;
	} else {
		current_player_index += 1;
	}
}
