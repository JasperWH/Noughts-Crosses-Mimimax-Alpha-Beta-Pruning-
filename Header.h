char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char playr[2] = { 'x','o' };

void print_board();
int input(char);
int inputAI(char, char);
void find(int*, char);
int check(int[2], char);
int minimax(int[2], char, char, int, int, int, int);

void print_board() {
	// loop through board postions and print
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl << std::endl;
	}
}
int inputAI(char plyr, char Aplyr) {
	// Initialse (x,y) - '3' as value > 2 indicates position not found
	int pos[2] = { 3,3 };
	int bestpos[2] = { 3,3 };

	// Initialse worst possible states:
	int bestscore = -100000; // best choice so far for maximising player
	int alpha = -100000;     // best choice so far for maximising player
	int beta = 100000;       // best choice so far for minimising player

	// loop through each number on board, if found the score outcomes
	for (char inpt = '1'; inpt < '1' + 9; ++inpt) {
		find(pos, inpt);
		if (pos[0] < 3) {
			// try new initial state
			board[pos[0]][pos[1]] = plyr;
			int score = minimax(pos, plyr, Aplyr, 0, 0, alpha, beta);

			// based on best score set best next move
			if (score > bestscore) {
				bestscore = score;
				bestpos[0] = pos[0];
				bestpos[1] = pos[1];
			}

			// reset board and position for new number
			board[pos[0]][pos[1]] = inpt;
			pos[0] = 3;
			pos[1] = 3;

			// Prune child nodes if alpha is now greater than beta
			alpha = std::max(alpha, bestscore);
			if (beta <= alpha)
				break;
		}
	}
	// set AI character in best place on board
	board[bestpos[0]][bestpos[1]] = plyr;
	print_board();

	// Check if player wins and return the state
	int state = check(bestpos, plyr);
	return state;
}


int minimax(int pos[2], char plyr, char Aplyr, int depth, int isMax, int alpha, int beta) {
	// recursive function to find terminal state, call utility function for value of win/draw/loose
	int state = check(pos, plyr);
	if (state != 2) {
		return state;
	}

	if (isMax == 1) {
		// Maximise player turn, e.g. if winning move possible return 1
		int bestscore = -100000;
		int pos[2] = { 3,3 };
		// loop through each number on board, if found the score outcomes
		for (char inpt = '1'; inpt < '1' + 9; ++inpt) {
			find(pos, inpt);
			if (pos[0] < 3) {
				board[pos[0]][pos[1]] = plyr;
				int score = minimax(pos, plyr, Aplyr, depth + 1, 0, alpha, beta);
				bestscore = std::max(bestscore, score);

				// reset board and position for new number
				board[pos[0]][pos[1]] = inpt;
				pos[0] = 3;
				pos[1] = 3;

				// Prune child nodes if alpha is now greater than beta
				alpha = std::max(alpha, bestscore);
				if (beta <= alpha)
					break;
			}
		}
		return bestscore;
	}
	else {
		// Minimise other player e.g. if next move they win then -1 returned, 
		// then the maxamising fuction which calls this will not choose this option. 
		int bestscore = 100000;
		int pos[2] = { 4,4 };
		// loop through each number on board, if found the score outcomes
		for (char inpt = '1'; inpt < '1' + 9; ++inpt) {
			find(pos, inpt);
			if (pos[0] < 3) {
				board[pos[0]][pos[1]] = Aplyr;
				int score = minimax(pos, plyr, Aplyr, depth + 1, 1, alpha, beta);
				bestscore = std::min(bestscore, score);

				// reset board and position for new number
				board[pos[0]][pos[1]] = inpt;
				pos[0] = 4;
				pos[1] = 4;

				// Prune child nodes if alpha is now greater than beta
				beta = std::min(beta, bestscore);
				if (beta <= alpha)
					break;
			}
		}
		return bestscore;
	}
}

int input(char plyr) {
	char inpt = ' ';
	int pos[2] = { 4,4 }; // (x,y) - '4' as value > 2 indicates position not found
	while (pos[0] > 2) {  // loop until user inputs a valid number
		std::cout << "Please enter a value not taken between 0-9: ";
		std::cin >> inpt;
		find(pos, inpt);  // check if valid input
	}

	// set players character in new place on board
	board[pos[0]][pos[1]] = plyr;
	print_board();

	// Check if player wins and return the state
	int state = check(pos, plyr);
	return state;
}

int check(int pos[2], char plyr) {
	// loop through players and check horizontal, vertical and diagonal rows and if found assign player to winner
	char winner = ' ';
	for (int n = 0; n < 2; n++) {
		if (board[pos[0]][0] == playr[n] && board[pos[0]][1] == playr[n] && board[pos[0]][2] == playr[n])
			winner = playr[n];
		if (board[0][pos[1]] == playr[n] && board[1][pos[1]] == playr[n] && board[2][pos[1]] == playr[n])
			winner = playr[n];
		if (board[0][0] == playr[n] && board[1][1] == playr[n] && board[2][2] == playr[n])
			winner = playr[n];
		if (board[0][2] == playr[n] && board[1][1] == playr[n] && board[2][0] == playr[n])
			winner = playr[n];
	}

	// loop through numbers, if one is found then board not full
	int full = 1;
	for (char inpt = '1'; inpt < '1' + 9; ++inpt) {
		int pos[2] = { 4,4 };
		find(pos, inpt);
		if (pos[0] < 3) {
			full = 0;
		}
	}

	// no winner and not full the continue game:
	if (winner == ' ' && full == 0) {
		return 2;
	}// no winner and full then draw:
	else if (winner == ' ' && full == 1) {
		return 0;
	}// player the winner:
	else if (plyr == winner) {
		return 1;
	}// else other player must be the winner:
	else {
		return -1;
	}
}

void find(int* pos, char inpt) {
	// loop through board and if input found then asign it to pos array
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			if (board[x][y] == inpt) {
				pos[0] = x;
				pos[1] = y;
			}
		}
	}
}
