#ifndef GAME_H
#define GAME_H

#include "Board.h"

class Game {
public:
  Game();      // Constructor
  void play(); // Function to start the game
private:
  Board board;   // Instance of the game board
  int turn;      // Indicates player's turn (1 for Player 1, 2 for Player 2)
  bool gameOver; // Flag to indicate if the game is over
};

#endif
