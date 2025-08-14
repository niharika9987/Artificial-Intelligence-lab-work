Lab 1 work date 5/08/2025

8-Puzzle Problem Solver (DFS and BFS)

These files provide C++ implementations of Depth-First Search and Breadth-First Search algorithms to solve the 8-puzzle problem.


1) Aim

The aim of this project is to:
- Solve the 8-puzzle problem using two search strategies: DFS and BFS.
- Find the sequence of moves that transforms a given initial state puzzle by user  into the goal state.
- Analyze and compare the behavior of DFS and BFS in terms of time complexity and efficiency.

2)Algorithm used
  DFS
   a. Use stack to implement depth-first traversal.
   b. Push the initial state into the stack.
   c. Pop the top state.
   d. If the current state is the goal state, print and exit.
   e. Else, generate all possible moves (up, down, left, right), and push resulting states to stack.
   f. Repeat until stack is empty.
  BFS
   a. Use queue to implement breadth-first traversal.
   b. Push the initial state into the queue.
   c. Pop the front state.
   d. If the current state is the goal state, print and exit.
   e. Else, generate all possible moves and enqueue resulting states.
   f. Repeat until queue is empty.
  
3) Time Complexity
   DFS
   uses a stack and visit the depth first so will take 4^ no of possible moves
   BFS
   uses a queue and visit breadth first so 4^ no of possible moves

   
Lab 2 work date 12/08/2025
1) Aim:

To Solve the 8-puzzle problem using the Hill Climbing algorithm and use a heuristic function (misplaced tiles) to guide the search towards the goal state. It also demonstrate the possibility of local minima in heuristic search.

2) Algorithm Used

Hill Climbing (Steepest Ascent)
a. Read the initial state of the puzzle from the user.
b. Calculate the heuristic value (number of misplaced tiles) of the current state.
c. Generate all possible moves (up, down, left, right) by moving the blank tile (0).
d. Calculate the heuristic for each neighbor.
e. Select the neighbor with the lowest heuristic value.
f. If no better neighbor exists, stop (local minima).
g. If the heuristic value is 0, goal is reached and print the final state.

3) Time Complexity

Worst Case: O(b^d) where b is the branching factor (~4 for 8-puzzle) and d is the depth of the solution.

In practice, hill climbing does not explore all states, so complexity depends on the heuristic’s accuracy.

Space Complexity: O(b) since only the current state and its neighbors are stored at each step.

Magic Square Generator

1) Aim
To generate a magic square of size n × n (where n is odd). and ensure that the sum of numbers in each row, column, and both main diagonals is the same. Also to calculate and display the magic constant.

2) Algorithm Used

Siamese Method (for odd n)
a. Start from the middle of the first row and place the number 1.
b. Move up one row and right one column to place the next number.
c. Wrap around if you move outside the square’s boundary.
d. If the target cell is already occupied, move down one cell instead and continue.
e. Repeat until all numbers from 1 to n² are placed.

3) Time Complexity

Time Complexity: O(n²) since each number from 1 to n² is placed exactly once.

Space Complexity: O(n²) for storing the matrix.

Water Jug Problem
1) Aim: The aim of this project is to:
    *Solve the classic water jug problem where two jugs of given capacities must be used to measure an exact target amount of water.
    *Implement a BFS approach to explore all possible states until the target is reached.

2) Algorithm Used
BFS for Water Jug Problem
a. Start with both jugs empty.
b. From the current state (x, y), generate all possible next states by:
     *Filling either jug fully.
     *Emptying either jug.

Pouring water from one jug to the other until one is full or the other is empty.
c. Use a queue to explore states level-by-level.
d. Stop when either jug contains the target amount.

3) Time Complexity

Time Complexity: O(C1 × C2) where C1 and C2 are the capacities of the two jugs.

Space Complexity: O(C1 × C2) for storing visited states.


Tic Tac Toe Game

The aim of this project is to implement a simple Tic Tac Toe game in C++. and to allow a human to play against a simple computer AI.

2) Algorithm Used
Game Flow
a. Initialize a 3×3 board with empty cells.
b. Alternate turns between player 1 and player 2 (or computer).
c. For each move:

Check if the move is valid.
Place the symbol (X or O) in the chosen position.
Check for a win or draw condition.
d. If the computer is playing, choose a move based on a simple pre-defined rule (e.g., blocking, random choice).
e. End the game when a win or draw is detected.

3) Time Complexity

Worst Case: O(9) moves per game 
Space Complexity: O(1) for board storage.

8-Puzzle Problem using Best First Search

1) Aim
To solve the 8-puzzle problem using the Best First Search strategy and use a heuristic function to always expand the node that appears to be closest to the goal state. It also demonstrate how heuristic-based search improves efficiency over blind search strategies.

2) Algorithm Used

Best First Search (Greedy Approach)
a. Read the initial state from the user.
b. Calculate the heuristic value h(n) for the state — here we use number of misplaced tiles.
c. Store states in a priority queue sorted by h(n) (smallest first).
d. Remove the state with the smallest h(n) from the queue.
e. If it is the goal state, stop.
f. Otherwise, generate all possible moves (up, down, left, right), calculate their h(n), and insert them into the priority queue.
g. Mark visited states to avoid revisiting.
h. Repeat until the goal is found or the queue becomes empty.

3) Time Complexity

Worst Case: O(b^d) where b is the branching factor (≈4 for 8-puzzle) and d is the solution depth.
Space Complexity: O(b^d) for storing nodes in the priority queue.
