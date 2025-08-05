#include<iostream>
#include<stack>
#include<vector>
#include<set>
using namespace std;

struct state {
    int id;
    int parent;
    vector<vector<int>> current_state = vector<vector<int>>(3, vector<int>(3));
};

vector<vector<int>> Board_goal = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
};

void print_board(vector<vector<int>> board)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool GoalTest(state s)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (s.current_state[i][j] != Board_goal[i][j])
                return false;
        }
    }
    return true;
}

void DFS(state start)
{
    stack<state> st;
    set<vector<vector<int>>> visited;
    int id_counter = 0;

    start.id = id_counter++;
    start.parent = -1;
    st.push(start);

    while (!st.empty())
    {
        state current = st.top();
        st.pop();

        if (visited.count(current.current_state) != 0)
            continue;

        visited.insert(current.current_state);

        if (GoalTest(current))
        {
            print_board(current.current_state);
            return;
        }

        int x = -1, y = -1;
        for (int i = 0; i < 3 && x == -1; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (current.current_state[i][j] == 0)
                {
                    x = i;
                    y = j;
                    break;
                }
            }
        }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int d = 0; d < 4; d++)
        {
            int new_x = x + dx[d];
            int new_y = y + dy[d];

            if (new_x >= 0 && new_y >= 0 && new_x < 3 && new_y < 3)
            {
                state new_state;
                new_state.current_state = current.current_state;
                int temp = new_state.current_state[new_x][new_y];
                new_state.current_state[new_x][new_y] = new_state.current_state[x][y];
                new_state.current_state[x][y] = temp;

                if (visited.count(new_state.current_state) == 0)
                {
                    new_state.id = id_counter++;
                    new_state.parent = current.id;
                    st.push(new_state);
                }
            }
        }
    }
}

int main()
{
    state start;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> start.current_state[i][j];
        }
    }

    DFS(start);

    return 0;
}
