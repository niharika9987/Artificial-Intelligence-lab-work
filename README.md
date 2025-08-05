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
