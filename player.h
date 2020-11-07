#ifndef _PLAYER_H_
#define _PLAYER_H_

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

#include "pile.h"

class Player {
	public:
		bool check_for_win();
		int number;
		Player(int number);
		Pile draw_pile;
		Pile discard_pile;
		std::shared_ptr<Card> drawCard ();
		// size_t pileSize (Pile & pile);
		// Card hand;
		// addHeadToDiscard(Pile & head);

}; 


#endif
