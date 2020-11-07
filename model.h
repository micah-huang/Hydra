#ifndef MODEL_H
#define MODEL_H

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
#include <deque>
#include "card.h"
#include "player.h"
#include "pile.h"
#include "head.h"

class Model {
	public:
		bool testing_mode;
		size_t current_player_index;
		std::shared_ptr<Player> current_player;
		size_t total_heads; 
		std::vector<std::shared_ptr<Player>> players;
		std::deque<std::shared_ptr<Head>> heads;
		void init(size_t num_players); // initializes game
		void turn();
		void state(std::shared_ptr<Player>, size_t remaining);
		bool unplayable(std::deque<std::shared_ptr<Head>> heads, std::shared_ptr<Card> card);
		std::shared_ptr<Head> getHead(std::deque<std::shared_ptr<Head>> heads, size_t head_number);
		bool invalid_value(std::string value);
		bool invalid_suit(std::string suit);
};





#endif
