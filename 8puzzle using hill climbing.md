## **Lab 2 — Date: 12/08/2025**

---

### 8-Puzzle Problem using Hill Climbing

#### Aim
To solve the 8-puzzle problem using the **Hill Climbing algorithm** with the **misplaced tiles heuristic** to guide the search toward the goal state.  
Also demonstrates the occurrence of **local minima** in heuristic search.

####  Algorithm Used — Hill Climbing (Steepest Ascent)
a. Read the initial state of the puzzle from the user.
b. Calculate the heuristic value (number of misplaced tiles) for the current state.
c. Generate all possible moves (up, down, left, right) by moving the blank tile.
d. Calculate the heuristic for each neighboring state.
e. Move to the neighbor with the lowest heuristic value.
f. If no better neighbor exists, stop (local minima reached).
g. If heuristic value = 0, goal is reached.


#### Complexity
- **Time Complexity:** O(bᵈ), where b ≈ 4 and d is the solution depth.  
- **Space Complexity:** O(b) since only current and neighboring states are stored.

#### Use Cases
- Demonstrates **heuristic-based local search**.
- Used in **optimization**, **pathfinding**, and **robot control**.
- Explains **local minima traps** in AI problem-solving.

---
