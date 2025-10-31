## Tic-Tac-Toe (Player vs Computer)

### Aim
To implement a Tic-Tac-Toe game in C++ that uses the Minimax algorithm, ensuring the computer never loses.  
The user can choose their symbol (X or O), and the computer will always make the optimal move.

---

### Algorithm (Minimax)

1. Initialize the board → 3×3 grid with positions numbered 1–9.
2. Player move → The user selects a cell number (1–9).
3. Computer move → Use the Minimax algorithm to determine the best possible move:
   - If the computer can win → choose that move.
   - If the player is about to win → block that move.
   - Otherwise → choose the move that maximizes the computer’s chance of winning.
4. Check for winner or draw after each move.
5. Repeat until the game ends → either a win or a draw occurs.

---

### Working Principle of Minimax
- Minimax simulates all possible moves from the current state.
- The computer assumes that the player will always play optimally.
- It assigns a score to terminal states:
  - +10 if the computer wins.
  - -10 if the player wins.
  - 0 for a draw.
- The algorithm recursively backtracks and selects the move that maximizes the computer’s score and minimizes the opponent’s.

---

### Time Complexity

- Tic-Tac-Toe has a maximum of 9! = 362,880 possible states.
- For each move, Minimax recursively explores remaining possibilities.

Worst-case time complexity:  
O(b^d) = O(9!) ≈ 362,880  

where  
b = branching factor (number of possible moves),  
d = depth of the game tree.

Since the search space is small, the Minimax algorithm runs efficiently for Tic-Tac-Toe.

---

### Space Complexity
O(b × d) for the recursive call stack and board copies, which is manageable for a 3×3 grid.
