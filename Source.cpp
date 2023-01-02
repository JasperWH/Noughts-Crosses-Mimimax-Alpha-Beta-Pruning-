#include <iostream>
#include <algorithm>
#include "Header.h"

int main() {
	// set up
	int state = 2;
	int mode;

	// pick which mode to play
	std::cout << "Available modes: \n'1': Human v Human \n'2': Human v AI \n'3': AI v AI\nPlease pick which mode to play:";
	std::cin >> mode;
	std::cout << std::endl << "positions on board:\n";
	print_board();

	// loop unit a win or draw
	while (true) {

		// first player goes, check for win or draw
		if (mode == 1 || mode == 2) {
			std::cout << "Human:" << std::endl;
			state = input(playr[0]);
		}else if(mode == 3){
			std::cout << "AI:" << std::endl;
			// player and adversary player
			state = inputAI(playr[0], playr[1]);
		}
		if (state == 1) {
			std::cout << playr[0] << " wins!\n";
			break;
		}
		else if (state == 0) {
			std::cout << "Draw!";
			break;
		}

		// second player goes, only check for win as odd number as position
		if (mode == 1) {
			std::cout << "Human:" << std::endl;
			state = input(playr[0]);
		}
		else if (mode == 2 || mode == 3) {
			std::cout << "AI:" << std::endl;
			// player and adversary player
			state = inputAI(playr[1], playr[0]); 
		}
		if (state == 1) {
			std::cout << playr[1] << " wins!\n";
			break;
		}
	}
}