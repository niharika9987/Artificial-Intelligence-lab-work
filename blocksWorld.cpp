#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
using namespace std;

struct State {
    map<char,char> on;  // block -> what it is on (block or 'T')
    string moves;       // steps taken so far
};

// Encode state into string for hashing
string encodeState(State &s, vector<char> &blocks) {
    string enc;
    for(char b : blocks) {
        enc += b;
        enc += s.on[b];
    }
    return enc;
}

// Check if states match
bool isGoal(State &s, State &goal, vector<char> &blocks) {
    for(char b : blocks)
        if(s.on[b] != goal.on[b]) return false;
    return true;
}

// Find clear blocks (nothing stacked on them)
set<char> findClear(State &s, vector<char> &blocks) {
    set<char> occupied;
    for(char b : blocks) {
        if(s.on[b] != 'T') occupied.insert(s.on[b]);
    }
    set<char> clear;
    for(char b : blocks) {
        if(occupied.find(b) == occupied.end())
            clear.insert(b);
    }
    return clear;
}

// BFS solver
void solve(State start, State goal, vector<char> &blocks) {
    queue<State> q;
    unordered_set<string> visited;

    q.push(start);
    visited.insert(encodeState(start, blocks));

    while(!q.empty()) {
        State cur = q.front(); q.pop();

        if(isGoal(cur, goal, blocks)) {
            cout << "Steps:\n" << cur.moves;
            cout << "Goal Reached!\n";
            return;
        }

        set<char> clear = findClear(cur, blocks);

        for(char b : clear) {
            char from = cur.on[b];

            // --- Move b to table ---
            if(from != 'T') {
                State nxt = cur;
                nxt.on[b] = 'T';
                nxt.moves = cur.moves + "Move " + string(1,b) + " to table\n";

                string code = encodeState(nxt, blocks);
                if(!visited.count(code)) {
                    visited.insert(code);
                    q.push(nxt);
                }
            }

            // --- Move b onto another clear block ---
            for(char dest : clear) {
                if(dest == b) continue; // can't put onto itself
                if(cur.on[b] == dest) continue; // already there

                State nxt = cur;
                nxt.on[b] = dest;
                nxt.moves = cur.moves + "Move " + string(1,b) + " on " + string(1,dest) + "\n";

                string code = encodeState(nxt, blocks);
                if(!visited.count(code)) {
                    visited.insert(code);
                    q.push(nxt);
                }
            }
        }
    }

    cout << "No solution found!\n";
}

int main() {
    int n;
    cout << "Enter number of blocks: ";
    cin >> n;

    vector<char> blocks(n);
    for(int i=0;i<n;i++) blocks[i] = 'A' + i;

    State start, goal;

    cout << "\nEnter start state (on which block or T for table):\n";
    for(char b : blocks) {
        cout << "Block " << b << " is on: ";
        cin >> start.on[b];
    }

    cout << "\nEnter goal state (on which block or T for table):\n";
    for(char b : blocks) {
        cout << "Block " << b << " should be on: ";
        cin >> goal.on[b];
    }

    cout << "\nSearching...\n";
    solve(start, goal, blocks);

    return 0;
}
