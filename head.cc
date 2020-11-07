#include "head.h"

Head::Head (size_t number) : number{number} {}


std::shared_ptr<Card> Head::top_card() {
	return cards.back();
}
