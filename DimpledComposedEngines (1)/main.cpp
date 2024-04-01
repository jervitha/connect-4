#include <iostream>
#include <vector>
using namespace std;

class Connect4 {
private:
    // Represents a player
    class Player {
    private:
        string name;
        char symbol;

    public:
        Player(const string& playerName, char playerSymbol) : name(playerName), symbol(playerSymbol) {}

        string getName() const {
            return name;
        }

        char getSymbol() const {
            return symbol;
        }
    };

    // Represents the game board
    class Board {
    private:
        vector<vector<char>> arr;

    public:
        Board() {
            // Initialize the board
            arr.resize(6, vector<char>(7, ','));
        }

        void display() const {
            for (int i = 0; i < 6; ++i) {
                for (int j = 0; j < 7; ++j) {
                    cout << arr[i][j] << '|';
                }
                cout << endl;
            }
            cout << "---------------" << endl;
        }

        bool insert(int column, char symbol) {
            if (column < 1 || column > 7) {
                return false;
            }

            int row = 5;
            while (row >= 0) {
                if (arr[row][column - 1] == ',') {
                    arr[row][column - 1] = symbol;
                    return true;
                }
                --row;
            }
            return false; // Column is full
        }

        bool checkWin(char symbol) const {
            // Check rows for win
            for (int i = 0; i < 6; ++i) {
                for (int j = 0; j <= 3; ++j) {
                    if (arr[i][j] == symbol && arr[i][j + 1] == symbol && arr[i][j + 2] == symbol && arr[i][j + 3] == symbol) {
                        return true;
                    }
                }
            }

            // Check columns for win
            for (int i = 0; i <= 2; ++i) {
                for (int j = 0; j < 7; ++j) {
                    if (arr[i][j] == symbol && arr[i + 1][j] == symbol && arr[i + 2][j] == symbol && arr[i + 3][j] == symbol) {
                        return true;
                    }
                }
            }

            // Check diagonals for win
            for (int i = 0; i <= 2; ++i) {
                for (int j = 0; j <= 3; ++j) {
                    if (arr[i][j] == symbol && arr[i + 1][j + 1] == symbol && arr[i + 2][j + 2] == symbol && arr[i + 3][j + 3] == symbol) {
                        return true;
                    }
                }
            }
            for (int i = 0; i <= 2; ++i) {
                for (int j = 3; j < 7; ++j) {
                    if (arr[i][j] == symbol && arr[i + 1][j - 1] == symbol && arr[i + 2][j - 2] == symbol && arr[i + 3][j - 3] == symbol) {
                        return true;
                    }
                }
            }

            return false;
        }
    };

    Player player1;
    Player player2;
    Board board;

public:
    Connect4(const string& name1, const string& name2) : player1(name1, 'X'), player2(name2, 'O') {}

    void startGame() {
        cout << "Welcome to Connect4!" << endl;
        board.display();

        bool player1Turn = true;
        while (true) {
            int column;
            Player currentPlayer = (player1Turn) ? player1 : player2;

            cout << currentPlayer.getName() << ", enter column (1-7): ";
            cin >> column;

            if (board.insert(column, currentPlayer.getSymbol())) {
                board.display();
                if (board.checkWin(currentPlayer.getSymbol())) {
                    cout << currentPlayer.getName() << " wins!" << endl;
                    break;
                }
                player1Turn = !player1Turn;
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        }
    }
};

int main() {
    Connect4 game("Player 1", "Player 2");
    game.startGame();
    return 0;
}
