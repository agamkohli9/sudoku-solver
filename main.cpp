#include <iostream>
#include "board.h"
using namespace std;

//example of solvable board
int example[9][9] = {
        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,1,0,0,8,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
};

int main() {
    //get user value for board
    cout << "Enter values for Sudoku Board left to right then top to bottom, clicking enter after every value (Enter 0 for blank spaces)" << endl;
    int board[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }
    cout << "solving..." << endl;
    Board sudoku(board);
    if (!sudoku.solve()) cout << "No Possible Solution";

    return 0;
}
