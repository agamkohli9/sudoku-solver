#include <iostream>

class Board {
private:
    int board[9][9];
public:
    Board(int[9][9]); //fill board data
    bool isSln(int, int); //checks if spot is a solution
    int section(int, int); //gives section of spot going from left to right then top to bottom
    bool solve(); //uses backtracking algorithm to solve sudoku board
    void printBoard(); //prints board
};