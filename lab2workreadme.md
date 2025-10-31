# #**Date:** 12/08/2025  

---

## 1. 8-Puzzle Problem using Hill Climbing Algorithm

### Aim
To solve the **8-puzzle problem** using the **Hill Climbing algorithm** with a heuristic function (number of misplaced tiles) to guide the search towards the goal state.  
This also demonstrates the possibility of **local minima** in heuristic search.

### Algorithm Used — Hill Climbing (Steepest Ascent)
a. Read the initial state of the puzzle from the user.  
b. Calculate the heuristic value (number of misplaced tiles) of the current state.  
c. Generate all possible moves (up, down, left, right) by moving the blank tile (0).  
d. Calculate the heuristic for each neighbor.  
e. Select the neighbor with the lowest heuristic value.  
f. If no better neighbor exists, stop (local minima).  
g. If the heuristic value is 0, the goal is reached and print the final state.

### Time and Space Complexity
- **Time Complexity:** O(b^d), where b is the branching factor (~4 for the 8-puzzle) and d is the depth of the solution.  
  In practice, Hill Climbing does not explore all states, so complexity depends on the heuristic’s accuracy.  
- **Space Complexity:** O(b), since only the current state and its neighbors are stored at each step.

---

## 2. Magic Square Generator

### Aim
To generate a **magic square** of size n × n (where n is odd), ensuring that the sum of numbers in each row, column, and both diagonals is the same.  
Also, to calculate and display the **magic constant**.

### Algorithm Used — Siamese Method (for odd n)
a. Start from the middle of the first row and place the number 1.  
b. Move up one row and right one column to place the next number.  
c. Wrap around if you move outside the square’s boundary.  
d. If the target cell is already occupied, move down one cell instead and continue.  
e. Repeat until all numbers from 1 to n² are placed.

### Time and Space Complexity
- **Time Complexity:** O(n²), since each number from 1 to n² is placed exactly once.  
- **Space Complexity:** O(n²), for storing the matrix.

---

## 3. Water Jug Problem

### Aim
To solve the **Water Jug Problem**, where two jugs of given capacities must be used to measure an exact target amount of water.  
The problem is solved using the **Breadth-First Search (BFS)** algorithm.

### Algorithm Used — BFS for Water Jug Problem
a. Start with both jugs empty.  
b. From the current state (x, y), generate all possible next states by:  
   - Filling either jug fully.  
   - Emptying either jug.  
   - Pouring water from one jug to the other until one is full or the other is empty.  
c. Use a queue to explore states level-by-level.  
d. Stop when either jug contains the target amount.

### Time and Space Complexity
- **Time Complexity:** O(C₁ × C₂), where C₁ and C₂ are the capacities of the two jugs.  
- **Space Complexity:** O(C₁ × C₂), for storing visited states.

---

## 4. Tic Tac Toe Game

### Aim
To implement a simple **Tic Tac Toe** game in **C++** that allows a human to play against a basic computer AI.

### Algorithm Used — Game Flow
a. Initialize a 3×3 board with empty cells.  
b. Alternate turns between Player 1 and Player 2 (or computer).  
c. For each move:  
   - Check if the move is valid.  
   - Place the symbol (X or O) in the chosen position.  
   - Check for a win or draw condition.  
d. If the computer is playing, choose a move based on a simple pre-defined rule (e.g., blocking or random choice).  
e. End the game when a win or draw is detected.

### Time and Space Complexity
- **Time Complexity:** O(9), since there can be at most 9 moves per game.  
- **Space Complexity:** O(1), for storing the board.

---

## 5. 8-Puzzle Problem using Best First Search

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
