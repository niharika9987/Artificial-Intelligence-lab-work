### Magic Square Generator

####  Aim
To generate a **magic square** of size *n × n* (where *n* is odd), ensuring that the sum of all rows, columns, and diagonals is identical, and to calculate the **magic constant**.

####  Algorithm Used — Siamese Method (for odd n)
a. Start at the middle of the first row and place number 1.
b. Move up one row and right one column to place the next number.
c. Wrap around if you move outside the boundary.
d. If the target cell is occupied, move down one cell instead.
e. Repeat until all numbers from 1 to n² are placed.

###  Complexity
- **Time Complexity:** O(n²)
- **Space Complexity:** O(n²)

#### Use Cases
- Used in **mathematical puzzles**, **pattern generation**, and **cryptography**.
- Demonstrates **matrix manipulation and modular arithmetic**.
- Can be extended for **AI pattern recognition** or **algorithm visualization**.

---
