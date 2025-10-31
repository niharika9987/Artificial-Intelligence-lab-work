## AO* Algorithm

### Aim
The aim of this program is to implement the AO* (And-Or Star) algorithm on a 2D grid for pathfinding.  
The algorithm finds an optimal path from a start cell to a goal cell, considering obstacles and diagonal movements.  
AO* is particularly suitable for problems represented as AND–OR graphs, where some moves may require solving multiple sub-tasks (AND) or selecting among alternatives (OR).

---

### Algorithm

#### Representation
- Each cell in the grid is considered a **state/node**.
- Neighbors of a node can be **OR successors** (choose one path) or **AND successors** (all must be traversed).
- Obstacles are **blocked nodes** and cannot be traversed.

#### Heuristic Function
- The algorithm uses **Manhattan Distance** or **Octile Distance** as the heuristic `h(n)`.
- `h(n)` estimates the cost from a node to the goal.

#### Steps

1. Start from the **initial node**.  
2. Expand successors (children) of the current node.  
3. For **OR nodes**, propagate the **minimum estimated cost** `f = g + h` from children to the parent.  
4. For **AND nodes**, propagate the **sum of child costs**.  
5. Repeat recursively until the goal node is solved.  
6. The minimal cost path is computed from start to goal.  

---

### Time Complexity
**Worst Case:** `O(b^n)`  
where:  
- `b` = branching factor (number of children per node)  
- `n` = maximum depth of the search tree  

AO* may explore fewer nodes than a naive exhaustive search because it **prunes nodes using heuristics**.

---

### Space Complexity
**Worst Case:** `O(b^n)`  
Memory is required to store:
- All generated nodes/states  
- Heuristic values  
- Child pointers and visited tracking  

Optimizations such as storing only **active paths** can reduce memory usage.

---

### Use Cases

#### 1. Grid-Based Pathfinding / Robotics
- Navigation of robots or agents in 2D maps with obstacles.  
- Optimal path selection when multiple sub-tasks must be solved.
#### 2. Problem Reduction in AI
- Decomposing complex problems into **AND–OR** graphs for structured problem solving.
#### 3. Game Trees / Strategy Games
- Decision-making where moves require handling multiple opponent responses.
#### 4. Planning and Diagnosis Systems
- Task planning in robotics and workflow optimization.  
- Fault diagnosis where certain conditions must all be verified (**AND nodes**) or alternatives can be chosen (**OR nodes**).
