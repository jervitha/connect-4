#ifndef WINCHECKER_H
#define WINCHECKER_H

class WinChecker {
public:
  static bool checkWin(char arr[6][7],
                       char player); //  to check if a player has won
private:
  static bool checkRow(char arr[6][7],
                       char player); //  function to check for a win in a row
  static bool
  checkColumn(char arr[6][7],
              char player); // function to check for a win in a column
  static bool
  checkDiagonal1(char arr[6][7],
                 char player); //  function to check for a win in diagonal 1
  static bool
  checkDiagonal2(char arr[6][7],
                 char player); //  function to check for a win in diagonal 2
};

#endif
