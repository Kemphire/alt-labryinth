#include <iostream>

class TicTacToe {
private:
  char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
  char playerSymbols;

public:
  void displayBoard() {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        std::cout << '|' << board[i][j];
      }
      std::cout << '|' << std::endl;
    }
  }

public:
  void playerMoves() {
    int rows, columns;
    char playerChoice;
    std::cout << "Please enter the symbol (X or O)" << std::endl;
    std::cin >> playerChoice;
    playerChoice = toupper(playerChoice);
    while (playerChoice != 'X' ||
           playerChoice != 'Y' && playerChoice == isdigit(playerChoice)) {
      std::cout
          << "You know TIC TAC TOE game right ??? Please enter either X or O."
          << std::endl;
      std::cin >> playerChoice;
      playerChoice = toupper(playerChoice);
    }
    playerSymbols = playerChoice;
    std::cout << "Enter the rows and columns where you want to put "
              << playerSymbols << std::endl;
    std::cin >> rows >> columns;
    while (rows < 0 || rows > 2 || columns < 0 || columns > 2) {
      std::cout
          << "Invalid row or column. Please enter values between 0 and 2: ";
      std::cin >> rows >> columns;
      break;
    }

    if (board[rows][columns] == ' ') {
      board[rows][columns] = playerSymbols;
      std::cout << board[rows][columns] << playerSymbols << std::endl;

      secondPlayer();
    } else {

      std::cout << "It's occupied. Please choose another move: ";
    }
  }

public:
  void secondPlayer() {
    char secondPlayer;
    int row1, column1;
    std::cout << "Player 2 it's your turn " << std::endl;
    std::cin >> secondPlayer;
    secondPlayer = toupper(secondPlayer);

    while (secondPlayer == playerSymbols ||
           (secondPlayer != 'X' && secondPlayer != 'O')) {
      std::cout << "Can't be as first player." << std::endl;
      std::cin >> secondPlayer;
      secondPlayer = toupper(secondPlayer);
    }
    std::cout << "Enter the rows and columns where you want to put "
              << secondPlayer << std::endl;
    std::cin >> row1 >> column1;
    while (row1 < 0 || row1 > 2 || column1 < 0 || column1 > 2) {
      std::cout
          << "Invalid row or column. Please enter values between 0 and 2: ";
      std::cin >> row1 >> column1;
      break;
    }
    if (row1 < 0 || row1 > 2 || column1 < 0 || column1 > 2 ||
        board[row1][column1] != ' ') {
      std::cout
          << "Invalid move. Please enter values between 0 and 2 for rows and "
             "columns, and make sure the spot is not already occupied."
          << std::endl;
    }
    while (row1 < 0 || row1 > 2 || column1 < 0 || column1 > 2 ||
           board[row1][column1] != ' ') {
      board[row1][column1] = secondPlayer;
      std::cout << board[row1][column1] << secondPlayer << std::endl;
      playerMoves();
    }
  }
};
int main() {
  TicTacToe game;
  game.displayBoard();
  game.playerMoves();
  game.secondPlayer();

  return 0;
}