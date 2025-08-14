#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    vector<vector<int>> state;
    int h; // heuristic value (misplaced tiles)
};

// Goal state
vector<vector<int>> goal = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
};

// Calculate heuristic: number of misplaced tiles
int heuristic(const vector<vector<int>> &s) {
    int count = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (s[i][j] != 0 && s[i][j] != goal[i][j])
                count++;
    return count;
}

// Print the board
void printBoard(const vector<vector<int>> &s) {
    for (auto &row : s) {
        for (auto &val : row)
            cout << val << " ";
        cout << "\n";
    }
}

// Get neighbors
vector<vector<vector<int>>> getNeighbors(vector<vector<int>> state) {
    vector<vector<vector<int>>> neighbors;
    int x, y;
    // Find blank position
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (state[i][j] == 0) { x = i; y = j; }

    // Possible moves
    vector<pair<int,int>> moves = {{-1,0},{1,0},{0,-1},{0,1}};
    for (auto move : moves) {
        int nx = x + move.first, ny = y + move.second;
        if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
            vector<vector<int>> newState = state;
            swap(newState[x][y], newState[nx][ny]);
            neighbors.push_back(newState);
        }
    }
    return neighbors;
}

// Hill Climbing Algorithm
void hillClimb(vector<vector<int>> start) {
    Node current;
    current.state = start;
    current.h = heuristic(start);

    while (true) {
        if (current.h == 0) { // Goal found
            cout << "Goal state reached:\n";
            printBoard(current.state);
            return;
        }

        vector<vector<vector<int>>> neighbors = getNeighbors(current.state);
        Node bestNeighbor = current;

        for (auto &n : neighbors) {
            int hVal = heuristic(n);
            if (hVal < bestNeighbor.h) {
                bestNeighbor.state = n;
                bestNeighbor.h = hVal;
            }
        }

        if (bestNeighbor.h >= current.h) {
            // No better neighbor found
            cout << "Stuck at local minima:\n";
            printBoard(current.state);
            return;
        }
        current = bestNeighbor; // Move to better neighbor
    }
}

int main() {
    vector<vector<int>> start(3, vector<int>(3));
    cout << "Enter initial state (use 0 for blank):\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> start[i][j];

    hillClimb(start);
    return 0;
}
