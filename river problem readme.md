## A* Pathfinding with River Obstacles

### Aim
To implement the A* (A-star) pathfinding algorithm in C++ to find the shortest path between two coordinates in a grid while avoiding river (blocked) cells.

---

### Steps of A* Algorithm

1. Initialize
2. Put the start node in the open list (priority queue).
3. The open list stores nodes to be explored, sorted by their f = g + h value.
4. Repeat until destination is found or open list is empty:
   - Pick the node with the lowest f value from the open list.
   - Move it to the closed list (visited).
   - If this node is the destination, reconstruct the path and stop.
5. Expand neighbors:
   - For each valid neighbor (not blocked, inside grid):
     ```
     g = cost from start to this neighbor
     h = heuristic estimate (Octile distance in this project)
     f = g + h
     ```
   - If the neighbor is not in open/closed list OR has a better f, update it and push it into the open list.

---

### Termination
- If destination is reached → return path and cost.
- If open list becomes empty → no path exists.

---

### Heuristic Used: Octile Distance

Used for grids that allow diagonal movement.

h = max(Δx, Δy) + (√2 − 1) × min(Δx, Δy)

Where:  
Δx = |x_current − x_goal|  
Δy = |y_current − y_goal|

---

### Time Complexity Analysis

Let  
V = number of vertices (grid cells)  
E = number of edges (connections between cells)

For an R × C grid:  
V = R × C  
Each cell can connect to at most 8 neighbors → E ≈ 8 × V

A* uses a priority queue (min-heap) to select the next best node:

- Insertion/Deletion in PQ → O(log V)  
- Each edge is relaxed once → O(E log V)

Final Time Complexity:  
O(E log V) ≈ O(R × C × log(R × C))

---

### Space Complexity
Stores open/closed sets → O(R × C)
