#include "Game.h"
#include <iostream>

using namespace std;

Game::Game() : turn(1), gameOver(false) {}

void Game::play() {
  cout << "Welcome to Connect 4!" << endl;
  while (!gameOver) {
    board.display();
    int column;
    char symbol = (turn == 1) ? 'X' : 'O';
    cout << "Player " << turn << ", enter column (1-7): ";
    cin >> column;
    board.insert(column, symbol);
    if (board.checkWin(symbol)) {
      board.display();
      cout << "Player " << turn << " wins!" << endl;
      gameOver = true;
    } else {
      // Check if the board is full
      bool boardFull = true;
      for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
          if (board.arr[i][j] == ',') {
            boardFull = false;
            break;
          }
        }
        if (!boardFull) {
          break;
        }
      }
      if (boardFull) {
        board.display(); // Display the board after draw
        cout << "It's a draw!" << endl;
        gameOver = true;
      } else {
        turn = (turn == 1) ? 2 : 1;
      }
    }
  }
}