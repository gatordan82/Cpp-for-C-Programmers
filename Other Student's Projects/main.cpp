/*
Game of Hex
first player:  player=0, color='X', north=>south
second player: player=1, color='O', west=>east
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>
#include <random>
#include <math.h>

int size = 11; // size of the board, meaning 2D board by size x size


			   /* Coordinate (m, n) corresponding to row and column respectively like matrix */
class Board {
private:

public:
	int sz;						// the number of nodes in the graph
	bool** graph;				// 2D array. graph[i][j] = true if graph b/w node i and node j
	char* color;

	/* default constructor */
	Board() : sz{ 0 }, graph{ nullptr }, color{ nullptr } {};

	/* constructor with size (blank board) */
	Board(int s) {
		sz = s;
		graph = new bool*[s];
		color = new char[s];	// empty:'.',  first_player:'X', second_player:'O'
		int row_i, col_i, row_j, col_j;

		for (int i = 0; i < s; ++i) {
			graph[i] = new bool[s];
			color[i] = '.';		// initialize all cells with empty
			row_i = i / size;	// correspond to row number of node i
			col_i = i % size;	// correspond to column number of node i

			for (int j = 0; j < s; ++j) {
				row_j = j / size;	// correspond to row number of node j
				col_j = j % size;	// correspond to column number of node j
									/* make a hex board */
				if (i == j) graph[i][j] = false;
				else if (row_i == row_j && abs(col_i - col_j) == 1) graph[i][j] = true;
				else if (abs(row_i - row_j) == 1 && (col_i == col_j || (row_i + col_i) == (row_j + col_j))) graph[i][j] = true;
				else graph[i][j] = false;
				//if (graph[i][j]) std::cout << "(" << row_i << ", " << col_i << ") - (" << row_j << ", " << col_j << ")" << std::endl;
			}
		}
	};

	/* destructor */
	~Board() {
		delete[] graph;
		delete[] color;
	};

	/* draw the board using ASCII symbols */
	void draw_board() {
		int temp;
		for (int i = 0; i < sz; ++i) {
			if (i % size == 0) {
				std::cout << std::endl;
				temp = i / size;
				for (int j = 0; j < temp; ++j) {
					std::cout << "  ";
				}
				std::cout << color[i];
			}
			else if (i%size == (size - 1)) {
				std::cout << " - " << color[i] << std::endl;
				if (i == sz - 1) continue;
				temp = (i + 1) / size;
				for (int j = 0; j < size; ++j) {
					if (j == 0) {
						std::cout << " ";
						for (int k = 0; k < temp - 1; ++k) std::cout << "  ";
						std::cout << '\\' << " ";
					}
					else if (j == sz - 1) std::cout << " " << '\\' << std::endl;
					else std::cout << "/ " << '\\' << " ";
				}
			}
			else std::cout << " - " << color[i];
		}
	};

	bool move(int player, int cell) {	// if the move is legal return true; otherwise return false
		if (color[cell] != '.') return false;
		else {
			if (player == 0) color[cell] = 'X'; // first player
			else color[cell] = 'O';				// second player
			return true;
		}

	};

	int judge() {		// judge the game situation (0: won by the first player, 1: won by the second player, 2: not determined)
		bool temp;
		bool* close = new bool[sz];

		/* judge whether the first player wins or not*/
		for (int i = 0; i < sz; ++i) close[i] = false;
		temp = false;
		for (int i = 0; i < size; ++i) {		// check the first row
			if (color[i] == 'X') { close[i] = true; temp = true; }
		}
		while (temp) {
			temp = false;
			for (int i = size; i < sz; ++i) {		// check the other row
				if (close[i]) continue;
				for (int j = 0; j < sz; ++j) {
					if (color[i] == 'X') {
						if (close[j] && graph[i][j]) {
							close[i] = true;
							temp = true;
							if ((i / size) == (size - 1)) return 0; // satisfy the condition the first player is winner
						}
					}
				}
			}
		}

		/* judge whether the second player wins or not*/
		for (int i = 0; i < sz; ++i) close[i] = false;
		temp = false;
		for (int i = 0; i < size; ++i) {		// check the first column
			if (color[i*size] == 'O') { close[i*size] = true; temp = true; }
		}
		while (temp) {
			temp = false;
			for (int i = 0; i < sz; ++i) {		// check the other column
				if (i % size == 0 || close[i]) continue;
				for (int j = 0; j < sz; ++j) {
					if (color[i] == 'O') {
						if (close[j] && graph[i][j]) {
							close[i] = true;
							temp = true;
							if ((i%size) == (size - 1)) return 1; // satisfy the condition the second player is winner
						}
					}
				}
			}
		}

		/* if neither the first player nor the second player wins, not determined*/
		return 2;
	};

};



int main() {

	int cell_size = size * size;
	int player;		// first_player:0, second_player:1
	int winner;

	Board b(cell_size);					// create a board with size
										//b.draw_board();						// draw the board with the initial situation
	std::cout << std::endl;

	srand(time(0));						// seed of rand()
	player = 0;
	while (true) {
		if (b.move(player, rand() % cell_size)) player = (player + 1) % 2;	// if the move is legal take a turn
		else continue;													// otherwise try again
		winner = b.judge();
		if (winner != 2) {			// if the game is over break
			break;
		}
	}

	b.draw_board();						// draw the board with the final situation
	if (winner == 0) std::cout << std::endl << "The winner is the first player ('X', from north to south)" << std::endl;
	else if (winner == 1) std::cout << std::endl << "The winner is the second player ('O', from west to east)" << std::endl;
	//else std::cout << std::endl << "The winner is not determined" << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}