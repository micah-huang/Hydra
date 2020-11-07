#ifndef CARD_H
#define CARD_H

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
#include <memory>
using namespace std;


class Card {
	public:
		std::string value;
		std::string suit;
		Card(std::string value, std::string suit);
		size_t numerical_value();
		void setValue(std::string updated_value);
		void setSuit(std::string updated_suit);
};	

std::ostream &operator<<(std::ostream &out, const Card & card);


#endif 
