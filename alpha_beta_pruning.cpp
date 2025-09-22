#include <iostream>
#include <vector>
#include <limits>
using namespace std;

struct Move { int row, col; };

char board[3][3] = { 
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'} 
};

// Print board
void Print_board() {
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

// Generate all empty moves
vector<Move> Generate_moves() {
    vector<Move> moves;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] != 'X' && board[i][j] != 'O') {
                moves.push_back({i, j});
            }
        }
    }
    return moves;
}

// Check winner
bool Winner(char mark) {
    for(int i=0; i<3; i++) {
        if(board[i][0]==mark && board[i][1]==mark && board[i][2]==mark) return true;
        if(board[0][i]==mark && board[1][i]==mark && board[2][i]==mark) return true;
    }
    if(board[0][0]==mark && board[1][1]==mark && board[2][2]==mark) return true;
    if(board[0][2]==mark && board[1][1]==mark && board[2][0]==mark) return true;
    return false;
}

// Check if board is full
bool Boardfull() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

// Scoring function
int score_generator(int depth) {
   if(Winner('O')) return 10 - depth; // Computer (AI) wins → high score
   if(Winner('X')) return depth - 10; // Player wins → low score
   return 0;
}

// Alpha-Beta Minimax
int alphabeta(int depth, int alpha, int beta, bool isMax) {
    int score = score_generator(depth);
    if(score != 0) return score;       // win/loss detected
    if(Boardfull()) return 0;          // draw

    if(isMax) { // AI's turn (O)
        int best = -1000;
        for(auto move : Generate_moves()) {
            char backup = board[move.row][move.col];
            board[move.row][move.col] = 'O';
            best = max(best, alphabeta(depth+1, alpha, beta, false));
            board[move.row][move.col] = backup;
            alpha = max(alpha, best);
            if(beta <= alpha) break; // prune
        }
        return best;
    } else { // Player's turn (X)
        int best = 1000;
        for(auto move : Generate_moves()) {
            char backup = board[move.row][move.col];
            board[move.row][move.col] = 'X';
            best = min(best, alphabeta(depth+1, alpha, beta, true));
            board[move.row][move.col] = backup;
            beta = min(beta, best);
            if(beta <= alpha) break; // prune
        }
        return best;
    }
}

// Player move
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

// Computer move using Alpha-Beta
void computerMove() {
    int bestScore = -1000;
    Move bestMove = {-1,-1};

    for(auto move : Generate_moves()) {
        char backup = board[move.row][move.col];
        board[move.row][move.col] = 'O';
        int score = alphabeta(0, -1000, 1000, false);
        board[move.row][move.col] = backup;

        if(score > bestScore) {
            bestScore = score;
            bestMove = move;
        }
    }

    board[bestMove.row][bestMove.col] = 'O';
    cout << "Computer chooses position " 
         << (bestMove.row * 3 + bestMove.col + 1) << "\n";
}

int main() {
    cout << "Tic-Tac-Toe: You are X, Computer is O\n";
    Print_board();

    while(true) {
        // Player move
        playerMove();
        Print_board();
        if(Winner('X')) { cout << "🎉 You win!\n"; break; }
        if(Boardfull()) { cout << " Draw!\n"; break; }

        // Computer move
        computerMove();
        Print_board();
        if(Winner('O')) { cout << "💻 Computer wins!\n"; break; }
        if(Boardfull()) { cout << " Draw!\n"; break; }
    }
    return 0;
}
