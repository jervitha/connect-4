#include "Board.h"
#include "WinChecker.h"
#include <iostream>

using namespace std;

Board::Board() {
  // Initialize the board
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 7; ++j) {
      arr[i][j] = ',';
    }
  }
}

void Board::insert(int column, char symbol) {
  int row = 5;
  while (row >= 0) {
    if (arr[row][column - 1] == ',') {
      arr[row][column - 1] = symbol;
      break;
    }
    --row;
  }
}

bool Board::checkWin(char symbol) { return WinChecker::checkWin(arr, symbol); }

void Board::display() {
  cout << endl;
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 7; ++j) {
      cout << arr[i][j] << '|';
    }
    cout << endl;
  }
  cout << "---------------" << endl;
}
