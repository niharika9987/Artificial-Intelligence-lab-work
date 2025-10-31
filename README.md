# Artificial Intelligence Lab Work

---

## Lab 1 — Date: 05/08/2025

### Experiment: 8-Puzzle Problem Solver (DFS and BFS)

---

###  Aim
The aim of this project is to:
- Solve the 8-puzzle problem using two search strategies: **Depth-First Search (DFS)** and **Breadth-First Search (BFS)**.
- Find the sequence of moves that transforms a given **initial state** (entered by the user) into the **goal state**.
- Analyze and compare the behavior of DFS and BFS in terms of **time complexity** and **efficiency**.

---

###  Algorithms Used

#### ** Depth-First Search (DFS)**
a. Use a stack to implement depth-first traversal.
b. Push the initial state into the stack.
c. Pop the top state.
d. If the current state is the goal state, print and exit.
e. Else, generate all possible moves (up, down, left, right) and push resulting states onto the stack.
f. Repeat until the stack is empty.


#### 2️ Breadth-First Search (BFS)
a. Use a queue to implement breadth-first traversal.
b. Push the initial state into the queue.
c. Pop the front state.
d. If the current state is the goal state, print and exit.
e. Else, generate all possible moves and enqueue resulting states.
f. Repeat until the queue is empty.

---

### Complexity Analysis

| Algorithm | Time Complexity | Space Complexity |
|------------|-----------------|------------------|
| **DFS** | O(4ⁿ) — explores depth first | O(4ⁿ) — stack stores depth states |
| **BFS** | O(4ⁿ) — explores breadth first | O(4ⁿ) — queue stores frontier nodes |

---

### Use Cases
- Demonstrates **uninformed search techniques** in AI.
- Used in **pathfinding**, **puzzle solving**, and **state-space search**.
- Highlights differences in **space–time tradeoff** between BFS and DFS.

---

