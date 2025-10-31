## 8-Puzzle Problem using Best First Search

### Aim
To solve the **8-puzzle problem** using the **Best First Search** (Greedy) strategy and a heuristic function that always expands the node closest to the goal state.  
This demonstrates how heuristic-based search improves efficiency over uninformed search methods.

### Algorithm Used — Best First Search (Greedy Approach)
a. Read the initial state from the user.  
b. Calculate the heuristic value h(n) for the state — here we use the **number of misplaced tiles**.  
c. Store states in a **priority queue** sorted by h(n) (smallest first).  
d. Remove the state with the smallest h(n) from the queue.  
e. If it is the goal state, stop.  
f. Otherwise, generate all possible moves (up, down, left, right), calculate their h(n), and insert them into the queue.  
g. Mark visited states to avoid revisiting.  
h. Repeat until the goal is found or the queue becomes empty.

### Time and Space Complexity
- **Time Complexity:** O(b^d), where b is the branching factor (≈4 for 8-puzzle) and d is the solution depth.  
- **Space Complexity:** O(b^d), for storing nodes in the priority queue.

### Use Cases

Demonstrates heuristic-based search in AI.

Used in robot motion planning and automated puzzle solving.

Illustrates local minima and plateaus in optimization problems.
