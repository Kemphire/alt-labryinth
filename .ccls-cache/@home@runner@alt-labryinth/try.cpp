#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <cstdio>
#include <ctype.h>
using namespace std;
class TicTacToe {
private:
  char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
  char playerSymbols[2] {'X','Y'};

public:
  void displayBoard() 
  {
    for (int i = 0; i < 3; i++) {
      for(int j{0};j < 3;j++)
      {
        cout << " "<<board[i][j] << " ";
        if(j < 2)cout << "|";
      }
      cout << endl;
      if(i != 2)cout << "+++++++++++\n";
    }
  }
  void player_move()
  {
    srand(time(NULL));
    string name1;
    cout << "Hey player 1 enter your name: ";
    while(!(cin >> name1))
    {
      cin.clear();
      cin.ignore(125489,'\n');
    }
    // later i realised that upper two lines are redundant as there is no need to check wheather the input provided is string or not because eventually everything can be converted to string
    int indi1 = rand() % 2;
    cout << "Hey " << name1 << " you got " << playerSymbols[indi1] << " ,best of luck\n";
    string name2;
    cout << "Hey player 2 enter your name: ";
    while(!(cin >> name2))
    {
      cin.clear();
      cin.ignore(125489,'\n');
    }
    int indi2;
    do
    {
      indi2 = rand() % 2;
    }
    while(indi2 == indi1);
    cout << "Hey " << name2 << " you got " << playerSymbols[indi2] << " ,best of luck\n";
  }
};

int main()
{
  TicTacToe boarde;
  boarde.displayBoard();
  boarde.player_move();
}