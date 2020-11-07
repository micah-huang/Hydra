#ifndef HEAD_H
#define HEAD_H

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
#include "pile.h"


class Head {
	public:
		// Head(int number);
		std::vector<shared_ptr<Card>> cards;		
		// static int num_heads;
		size_t number;
		Head(size_t number);
		std::shared_ptr<Card> top_card();
		//static int head_count () {
		//	return num_heads;
		// }
		// placeOnTop(Card & card);

};




#endif
