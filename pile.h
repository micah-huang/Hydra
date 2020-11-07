#ifndef PILE_H
#define PILE_H

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
#include "card.h"


class Pile {
	public:
		std::vector<std::shared_ptr<Card>> cards;
};
	






#endif
