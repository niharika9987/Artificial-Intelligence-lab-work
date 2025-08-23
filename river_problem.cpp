#include <bits/stdc++.h>
using namespace std;

struct Node {
    int r, c;
    double f;
    Node(int _r, int _c, double _f) : r(_r), c(_c), f(_f) {}
    bool operator>(const Node &other) const {
        return f > other.f; // for min-heap
    }
};

using Coord = pair<int,int>;

long long makeKey(int r, int c) {
    return ((long long)r << 32) ^ (long long)c;
}

double octile(const Coord &a, const Coord &b, double D = 1.0, double D2 = 1.41421356237) {
    int dx = abs(a.first - b.first);
    int dy = abs(a.second - b.second);
    return D * (dx + dy) + (D2 - 2 * D) * min(dx, dy);
}

vector<Coord> traceback(unordered_map<long long, Coord> &cameFrom, Coord end) {
    vector<Coord> path;
    Coord cur = end;
    long long k = makeKey(cur.first, cur.second);

    while (cameFrom.find(k) != cameFrom.end()) {
        path.push_back(cur);
        cur = cameFrom[k];
        k = makeKey(cur.first, cur.second);
    }
    path.push_back(cur);
    reverse(path.begin(), path.end());
    return path;
}

pair<vector<Coord>, double> astarRoute(
    const vector<vector<int>> &grid,
    Coord start,
    Coord goal,
    int blocked_value = -1,
    bool allow_diagonal = true,
    bool use_cell_weight = true,
    double ortho_cost = 1.0,
    double diag_cost  = 1.41421356237
) {
    int rows = grid.size();
    int cols = rows ? grid[0].size() : 0;

    auto inBounds = [&](int r, int c) {
        return r >= 0 && r < rows && c >= 0 && c < cols;
    };

    vector<pair<int,int>> steps;
    if (allow_diagonal) {
        steps = {{-1,0},{1,0},{0,-1},{0,1},
                 {-1,-1},{-1,1},{1,-1},{1,1}};
    } else {
        steps = {{-1,0},{1,0},{0,-1},{0,1}};
    }

    if (!inBounds(start.first,start.second) || !inBounds(goal.first,goal.second))
        return {{}, numeric_limits<double>::infinity()};
    if (grid[start.first][start.second] == blocked_value || grid[goal.first][goal.second] == blocked_value)
        return {{}, numeric_limits<double>::infinity()};

    unordered_map<long long, double> gScore;
    unordered_map<long long, Coord> cameFrom;

    gScore[makeKey(start.first,start.second)] = 0.0;

    priority_queue<Node, vector<Node>, greater<Node>> openHeap;
    openHeap.push(Node(start.first, start.second, octile(start, goal, ortho_cost, diag_cost)));

    unordered_set<long long> closed;

    while (!openHeap.empty()) {
        Node cur = openHeap.top(); openHeap.pop();
        int r = cur.r, c = cur.c;
        Coord current = {r,c};
        long long ck = makeKey(r,c);

        if (closed.count(ck)) continue;
        closed.insert(ck);

        if (current == goal) {
            auto path = traceback(cameFrom, current);
            return {path, gScore[ck]};
        }

        for (size_t i = 0; i < steps.size(); i++) {
            int dr = steps[i].first;
            int dc = steps[i].second;
            int nr = r + dr, nc = c + dc;
            if (!inBounds(nr,nc)) continue;
            if (grid[nr][nc] == blocked_value) continue;

            double base = (dr != 0 && dc != 0) ? diag_cost : ortho_cost;
            double stepCost = use_cell_weight ? base * grid[nr][nc] : base;

            long long nk = makeKey(nr,nc);
            double tentative_g = gScore[ck] + stepCost;

            if (!gScore.count(nk) || tentative_g < gScore[nk]) {
                gScore[nk] = tentative_g;
                cameFrom[nk] = current;
                double h = octile({nr,nc}, goal, ortho_cost, diag_cost);
                openHeap.push(Node(nr,nc, tentative_g + h));
            }
        }
    }

    return {{}, numeric_limits<double>::infinity()};
}

int main() {
    int rows, cols;
    cout << "Enter grid size (rows cols): ";
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols, 1));

    int sr, sc, dr, dc;
    cout << "Enter source coordinate (row col): ";
    cin >> sr >> sc;
    cout << "Enter destination coordinate (row col): ";
    cin >> dr >> dc;

    int rivers;
    cout << "Enter number of river (blocked) cells: ";
    cin >> rivers;
    cout << "Enter river coordinates (row col): \n";
    for (int i = 0; i < rivers; i++) {
        int rr, rc;
        cin >> rr >> rc;
        if (rr >= 0 && rr < rows && rc >= 0 && rc < cols)
            grid[rr][rc] = -1;
    }

    auto result = astarRoute(grid, {sr, sc}, {dr, dc}, -1, true, true, 1.0, 1.41421356);

    vector<Coord> path = result.first;
    double cost = result.second;

    if (path.empty()) {
        cout << "No path found!\n";
    } else {
        cout << "\nPath:\n";
        for (size_t i = 0; i < path.size(); i++) {
            cout << "(" << path[i].first << "," << path[i].second << ") ";
        }
        cout << "\nTotal Cost: " << cost << "\n";

        // Display grid with path
        cout << "\nGrid with path (* = path, # = river):\n";
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == -1)
                    cout << "# ";
                else if (find(path.begin(), path.end(), make_pair(r,c)) != path.end())
                    cout << "* ";
                else
                    cout << ". ";
            }
            cout << "\n";
        }
    }
    return 0;
}
