#include "player.h"

Player::Player(int number) : number{number} {}

std::shared_ptr<Card> Player::drawCard() {
	std::shared_ptr<Card> draw = draw_pile.cards.back();
	draw_pile.cards.pop_back();
	return draw;
}

/*
size_t Player::pileSize(Pile & pile) {
	return pile.cards.size();
}
*/

