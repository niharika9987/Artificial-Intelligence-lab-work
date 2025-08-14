#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

char board[3][3] = { {'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'} };

void displayBoard() {
    cout << "\n";
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout << " " << board[i][j] << " ";
            if(j<2) cout << "|";
        }
        cout << "\n";
        if(i<2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool isWinner(char mark) {
    for(int i=0; i<3; i++) {
        if(board[i][0]==mark && board[i][1]==mark && board[i][2]==mark) return true;
        if(board[0][i]==mark && board[1][i]==mark && board[2][i]==mark) return true;
    }
    if(board[0][0]==mark && board[1][1]==mark && board[2][2]==mark) return true;
    if(board[0][2]==mark && board[1][1]==mark && board[2][0]==mark) return true;
    return false;
}

bool isFull() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void playerMove() {
    int move;
    cout << "Enter your move (1-9): ";
    cin >> move;
    int row = (move-1)/3;
    int col = (move-1)%3;
    if(board[row][col] != 'X' && board[row][col] != 'O')
        board[row][col] = 'X';
    else {
        cout << "Invalid move! Try again.\n";
        playerMove();
    }
}

void computerMove() {
    // Beginner girl logic: pick a different end in same row/col/diagonal if possible
    for(int i=0; i<3; i++) {
        // Same row
        if(board[i][0]=='X' && board[i][2] != 'X' && board[i][2] != 'O') { board[i][2]='O'; return; }
        if(board[i][2]=='X' && board[i][0] != 'X' && board[i][0] != 'O') { board[i][0]='O'; return; }
        // Same column
        if(board[0][i]=='X' && board[2][i] != 'X' && board[2][i] != 'O') { board[2][i]='O'; return; }
        if(board[2][i]=='X' && board[0][i] != 'X' && board[0][i] != 'O') { board[0][i]='O'; return; }
    }
    // Diagonals
    if(board[0][0]=='X' && board[2][2] != 'X' && board[2][2] != 'O') { board[2][2]='O'; return; }
    if(board[2][2]=='X' && board[0][0] != 'X' && board[0][0] != 'O') { board[0][0]='O'; return; }
    if(board[0][2]=='X' && board[2][0] != 'X' && board[2][0] != 'O') { board[2][0]='O'; return; }
    if(board[2][0]=='X' && board[0][2] != 'X' && board[0][2] != 'O') { board[0][2]='O'; return; }

    // If above logic fails, pick random free spot
    srand(time(0));
    while(true) {
        int move = rand()%9 + 1;
        int row = (move-1)/3;
        int col = (move-1)%3;
        if(board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = 'O';
            return;
        }
    }
}

int main() {
    cout << "Tic Tac Toe - Player (X) vs Computer (O)\n";
    displayBoard();

    while(true) {
        playerMove();
        displayBoard();
        if(isWinner('X')) { cout << "You win!\n"; break; }
        if(isFull()) { cout << "It's a draw!\n"; break; }

        computerMove();
        cout << "Computer's move:\n";
        displayBoard();
        if(isWinner('O')) { cout << "Computer wins!\n"; break; }
        if(isFull()) { cout << "It's a draw!\n"; break; }
    }
    return 0;
}
