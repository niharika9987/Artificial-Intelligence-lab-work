A* Pathfinding with River Obstacles

Aim:
To implement the A (A-star) pathfinding algorithm* in C++ to find the shortest path between two coordinates in a grid while avoiding river (blocked) cells.
  
Steps of A* Algorithm:

1)Initialize

2)Put the start node in the open list (priority queue).

3)The open list stores nodes to be explored, sorted by their f = g + h value.

4)Repeat until destination is found or open list is empty

5)Pick the node with the lowest f value from the open list.

6)Move it to the closed list (visited).

7)If this node is the destination, reconstruct the path and stop.

8)Expand neighbors

9)For each valid neighbor (not blocked, inside grid):

Calculate:
g = cost from start to this neighbor
h = heuristic estimate (Octile distance in this project)
f = g + h
If neighbor is not in open/closed list OR has a better f, update it and push into open list.

Termination
If destination is reached → return path and cost.
If open list becomes empty → no path exists.

Heuristic Used
Octile Distance (suitable for grids allowing diagonal movement):
ℎ = max(Δ𝑥,Δ𝑦)+(2−1)×min⁡(Δ𝑥,Δ𝑦) Where:Δ𝑥=∣𝑥𝑐𝑢𝑟𝑟𝑒𝑛𝑡−𝑥𝑔𝑜𝑎𝑙∣Δx=∣xcurrent−xgoal∣   Δ𝑦=∣𝑦𝑐𝑢𝑟𝑟𝑒𝑛𝑡−𝑦𝑔𝑜a𝑙∣

Time Complexity Analysis
Let V = number of vertices (grid cells)
Let E = number of edges (connections between cells)
For an R × C grid:
         V = R × C
Each cell can connect to at most 8 neighbors → E ≈ 8 × V
A* uses a priority queue (min-heap) to select the next best node:

Insertion/Deletion in PQ → O(log V)
Each edge is relaxed once → O(E log V)

Final Time Complexity:
𝑂(𝐸log⁡𝑉)≈𝑂(𝑅×𝐶×log(𝑅×𝐶))

Space Complexity:
Stores open/closed sets → O(R × C)
