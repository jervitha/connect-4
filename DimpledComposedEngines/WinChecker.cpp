#include "WinChecker.h"

bool WinChecker::checkWin(char arr[6][7], char player) {
  return checkRow(arr, player) || checkColumn(arr, player) ||
         checkDiagonal1(arr, player) || checkDiagonal2(arr, player);
}

bool WinChecker::checkRow(char arr[6][7], char player) {
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (arr[i][j] == player && arr[i][j + 1] == player &&
          arr[i][j + 2] == player && arr[i][j + 3] == player) {
        return true;
      }
    }
  }
  return false;
}

bool WinChecker::checkColumn(char arr[6][7], char player) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 7; ++j) {
      if (arr[i][j] == player && arr[i + 1][j] == player &&
          arr[i + 2][j] == player && arr[i + 3][j] == player) {
        return true;
      }
    }
  }
  return false;
}

bool WinChecker::checkDiagonal1(char arr[6][7], char player) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (arr[i][j] == player && arr[i + 1][j + 1] == player &&
          arr[i + 2][j + 2] == player && arr[i + 3][j + 3] == player) {
        return true;
      }
    }
  }
  return false;
}

bool WinChecker::checkDiagonal2(char arr[6][7], char player) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 3; j < 7; ++j) {
      if (arr[i][j] == player && arr[i + 1][j - 1] == player &&
          arr[i + 2][j - 2] == player && arr[i + 3][j - 3] == player) {
        return true;
      }
    }
  }
  return false;
}
