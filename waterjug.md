###  Water Jug Problem

#### Aim
To solve the **Water Jug Problem** using **Breadth-First Search (BFS)**, finding the sequence of actions to measure an exact target quantity using two jugs of known capacities.

####  Algorithm Used — BFS for Water Jug Problem
a. Start with both jugs empty.
b. From the current state (x, y), generate all possible next states by:

Filling either jug completely.

Emptying either jug.

Pouring water from one jug to another until one is full or the other is empty.
c. Use a queue to explore states level-by-level.
d. Stop when either jug contains the target amount.

markdown
Copy code

#### Complexity
- **Time Complexity:** O(C₁ × C₂)
- **Space Complexity:** O(C₁ × C₂)

####  Use Cases
- Demonstrates **state-space search and reasoning**.
- Used in **robotics planning**, **resource distribution**, and **constraint-based problems**.
- Classic example of **AI problem formulation and search**.

---
