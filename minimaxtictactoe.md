Tic-Tac-Toe (Player vs Computer)
AIM- To implement a Tic-Tac-Toe game in C++ where it implements this game by minimax algorithm ensuring it never loses.User can choose which symbol he wants to use.The computer makes its moves using the Minimax algorithm, ensuring it never loses.

Algorithm (Minimax)
1)Initialize board → 3x3 grid with positions 1–9.
2)Player move → User chooses a cell number (1–9).
3)Computer move → Use Minimax to choose the best move:
4)If the computer can win → choose that move.
5)If the player is about to win → block them.
   Otherwise → pick the move that maximizes computer’s chance of winning.
6)Check winner or draw → After each move.
Repeat until game ends → Either someone wins or the board is full.

Time Complexity
Minimax explores all possible game states. Max possible states in Tic-Tac-Toe = 9! = 362,880.
For each move, Minimax recursively explores remaining states.
Worst-case time complexity: 𝑂(𝑏𝑑)=𝑂(9!)≈362,880 O(bd)=O(9!)≈362,880
where b = branching factor, d = depth of tree.
Since Tic-Tac-Toe is small, the algorithm runs instantly.
