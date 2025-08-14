#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
using namespace std;

struct state {
    int id;
    int parent;
    vector<vector<int>> current_state = vector<vector<int>>(3, vector<int>(3));
    int h; // heuristic value
};

// Goal state
vector<vector<int>> Board_goal = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
};

// Function to print the board
void print_board(vector<vector<int>> board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Goal test
bool GoalTest(state s) {
    return s.current_state == Board_goal;
}

// Heuristic: number of misplaced tiles
int heuristic(vector<vector<int>> board) {
    int misplaced = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 0 && board[i][j] != Board_goal[i][j])
                misplaced++;
        }
    }
    return misplaced;
}

// Comparator for priority queue (min-heap by h)
struct compareState {
    bool operator()(state const& s1, state const& s2) {
        return s1.h > s2.h; // smaller h first
    }
};

void BestFirstSearch(state start) {
    priority_queue<state, vector<state>, compareState> pq;
    set<vector<vector<int>>> visited;
    map<int, state> allStates; // store all states by ID for backtracking
    int id_counter = 0;

    start.id = id_counter++;
    start.parent = -1;
    start.h = heuristic(start.current_state);
    pq.push(start);
    allStates[start.id] = start;

    while (!pq.empty()) {
        state current = pq.top();
        pq.pop();

        if (visited.count(current.current_state))
            continue;
        visited.insert(current.current_state);

        if (GoalTest(current)) {
            cout << "Goal reached!\n\n";

            // Backtrack and print solution path
            vector<state> path;
            while (current.id != -1) {
                path.push_back(current);
                current = allStates[current.parent];
            }

            // Print in correct order
            for (int i = path.size() - 1; i >= 0; i--) {
                print_board(path[i].current_state);
            }
            return;
        }

        // Find blank position
        int x = -1, y = -1;
        for (int i = 0; i < 3 && x == -1; i++) {
            for (int j = 0; j < 3; j++) {
                if (current.current_state[i][j] == 0) {
                    x = i;
                    y = j;
                    break;
                }
            }
        }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        // Generate neighbors
        for (int d = 0; d < 4; d++) {
            int new_x = x + dx[d];
            int new_y = y + dy[d];

            if (new_x >= 0 && new_y >= 0 && new_x < 3 && new_y < 3) {
                state new_state;
                new_state.current_state = current.current_state;
                swap(new_state.current_state[x][y], new_state.current_state[new_x][new_y]);

                if (visited.count(new_state.current_state) == 0) {
                    new_state.id = id_counter++;
                    new_state.parent = current.id;
                    new_state.h = heuristic(new_state.current_state);
                    pq.push(new_state);
                    allStates[new_state.id] = new_state;
                }
            }
        }
    }

    cout << "No solution found!" << endl;
}

int main() {
    state start;
    cout << "Enter initial state (3x3 grid, use 0 for blank):" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> start.current_state[i][j];
        }
    }

    BestFirstSearch(start);
    return 0;
}
