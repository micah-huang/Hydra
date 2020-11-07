
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
#include "card.h"
using namespace std;

Card::Card(string value, string suit): value{value}, suit{suit} {} 


size_t Card::numerical_value () {
	if (value == "A") {
		return 1;
	} else if (value == "J") {
		return 11;
	} else if (value == "Q") {
		return 12;
	} else if (value == "K") {
		return 13;
	} else {
		return std::stoi(value);
	}
}


void Card::setValue (std::string updated_value) {
	if (updated_value == "Joker") {
		value = 2;
		suit = "J";
	}
	value = updated_value;
}

void Card::setSuit (std::string updated_suit) {
	suit = updated_suit;
}

std::ostream &operator<<(std::ostream &out, const Card & card) {
	out << card.value << card.suit;
	return out;
}



