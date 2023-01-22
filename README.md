## Code Summary:
This code for Noughts and Crosses aka Tic-tac-toe is written in C++. The user is provided with the options to run it in the following game mode:
1) Human v Human
2) Human v AI
3) AI v AI

 The AI has been implimented using the Minimax algorithm Alpha-Beta Pruning to increase efficiency
 
 ## Algortihm Explained:

The minimax algorithm is a decision-making algorithm used in game theory and artificial intelligence. It is used to determine the best move for a player in a two-player, zero-sum game. The algorithm works by evaluating all possible future states of the game and determining the best move based on the minimum amount of damage that the player's opponent can do to them (i.e. the "min" value) and the maximum amount of benefit the player can gain (i.e. the "max" value). Alpha-beta pruning is an optimization of the standard minimax algorithm useing two additional parameters, called alpha and beta, to keep track of the best move that the algorithm has found so far. This reduces the number of states the algorithm needs to explore and therefore the time complexity of the algorithm.

The minimax algorithm uses a tree-like structure to represent the possible moves and outcomes of the game. Each node in the tree represents a possible move, and the edges connecting the nodes represent the outcome of the move. The algorithm starts at the root of the tree, representing the current state of the game, and then recursively evaluates all the child nodes, working its way down the tree. The alpha parameter represents the best move that the maximizing player (i.e. the current player) has found so far, and the beta parameter represents the best move that the minimizing player (i.e. the opponent) has found so far. The algorithm uses these parameters to eliminate branches of the tree that cannot possibly produce a better outcome than the best move that has already been found. At the leaf nodes, which represent the final outcome of the game, the algorithm assigns a value to the node based on whether the outcome is a win, loss, or draw for the current player. The algorithm then works its way back up the tree, using the values of the child nodes to determine the best move for the current player.

For example, if the current value of alpha is greater than the current value of beta, the algorithm knows that the maximizing player can't possibly do better than the best move that has already been found, so it can stop exploring that branch of the tree. This allows the algorithm to significantly reduce the number of nodes that it needs to evaluate, which can greatly speed up the process of determining the best move.
