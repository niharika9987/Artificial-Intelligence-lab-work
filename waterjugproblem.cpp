#include <bits/stdc++.h>
using namespace std;

struct State {
    int x, y;
    vector<pair<int,int>> path;
};

int main() {
    int jug1, jug2, target;
    cin >> jug1 >> jug2 >> target;

    queue<State> q;
    set<pair<int,int>> visited;

    q.push({0, 0, {{0,0}}});
    visited.insert({0,0});

    while(!q.empty()) {
        State s = q.front(); q.pop();

        if(s.x == target || s.y == target) {
            for(auto p : s.path)
                cout << "(" << p.first << "," << p.second << ") ";
            cout << endl;
            return 0;
        }

        vector<State> next;

        next.push_back({jug1, s.y, s.path}); next.back().path.push_back({jug1, s.y});
        next.push_back({s.x, jug2, s.path}); next.back().path.push_back({s.x, jug2});
        next.push_back({0, s.y, s.path}); next.back().path.push_back({0, s.y});
        next.push_back({s.x, 0, s.path}); next.back().path.push_back({s.x, 0});
        int pour = min(s.x, jug2 - s.y);
        next.push_back({s.x - pour, s.y + pour, s.path}); next.back().path.push_back({s.x - pour, s.y + pour});
        pour = min(s.y, jug1 - s.x);
        next.push_back({s.x + pour, s.y - pour, s.path}); next.back().path.push_back({s.x + pour, s.y - pour});

        for(auto ns : next)
            if(!visited.count({ns.x, ns.y})) {
                visited.insert({ns.x, ns.y});
                q.push(ns);
            }
    }

    cout << "No solution\n";
}
