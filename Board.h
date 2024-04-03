#ifndef BOARD_H
#define BOARD_H

class Board {
public:
  Board();                              // Constructor
  void insert(int column, char symbol); // Insert a symbol into the board
  bool checkWin(char symbol);           // Check for a win
  void display();                       // Display the game board
  const char *getBoardArray() const;    

public:
  char arr[6][7]; // The game board
};

#endif