#include <iostream>
#include "model.h"
#include <stdexcept>
using namespace std;

int main ( int argc, char * argv[] ) {
	Model game;
	// check for testing mode:
	string cmd_line_arg;
	if ( argc == 2 ) {
		cmd_line_arg = argv[1];
		if ( cmd_line_arg == "-testing" ) {
			game.testing_mode = true;
		}
	} else {
		game.testing_mode = false;
	}


	int num_players;
	
	while (true) {
		if (cin.eof()) {
			exit(0);
		}

		cout << "How many players?" << endl;
		if (!(cin >> num_players)) {
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
		// cin >> num_players;
		break;
		   
	} 
	// spacing:
	cout << endl;

	game.init(num_players);
	game.turn();
	
	while(true) {
	// check if current player has won:
	//if (game.current_player->won == true) {
	//cout << "Player " << game.current_player->number << "wins!" << endl;
	//} 
	// play the current player, the game function will update the current player index, etc.
	game.turn();
	
	// check for win

	// check
	// game.state();
	// game.turn();
	}
	
}
