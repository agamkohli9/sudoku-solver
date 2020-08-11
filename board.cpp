#include "board.h"

Board::Board(int boardInput[9][9]) {
    //fill in board
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board[i][j] = boardInput[i][j];
        }
    }
}


int Board::section(int i, int j) {
    if (i < 3 && j < 3) return 1;
    if (i < 3 && j < 6) return 2;
    if (i < 3 && j < 9) return 3;
    if (i < 6 && j < 3) return 4;
    if (i < 6 && j < 6) return 5;
    if (i < 6 && j < 9) return 6;
    if (i < 9 && j < 3) return 7;
    if (i < 9 && j < 6) return 8;
    if (i < 9 && j < 9) return 9;
}

bool Board::isSln(int row, int col) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (section(row, col) == section(i, j) && board[row][col] == board[i][j] && row != i && col != j) return false;
            if (board[row][col] == board[row][j] && col != j) return false;
            if (board[row][col] == board[i][col] && row != i) return false;
        }
    }
    return true;
}

bool Board::solve() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                for (int num = 1; num < 10; num++) {
                    //try numbers 1 through 10 for spot with 0
                    board[i][j] = num;
                    //if a number works then go onto the next empty value
                    if (isSln(i, j) && solve()) return true;
                    //backtrack if none of the numbers worked
                    board[i][j] = 0;
                }
                return false;
            }
        }
    }
    printBoard();
}

void Board::printBoard() {
    std::cout << "SOLUTION" << std::endl;
    for (int i = 0; i < 9; i++) {
        std::cout << "|";
        for (int j = 0; j < 9; j++) {
            std::cout << board[i][j] << "|";
        }
        std::cout << std::endl;
    }
}
