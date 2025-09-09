AO* ALGORITHM

Aim
The aim of this program is to implement the AO* (And-Or Star) algorithm on a 2D grid for pathfinding. The algorithm finds an optimal path from a start cell to a goal cell, considering obstacles and possible diagonal movements. AO* is particularly suitable for problems represented as AND–OR graphs, where some moves may require solving multiple sub-tasks (AND) or selecting among alternatives (OR).

Algorithm
The AO* algorithm works as follows:
Representation:
Each cell in the grid is considered a state/node.Neighbors of a node can be OR successors (choose one path) or AND successors (all must be traversed).Obstacles are blocked nodes and cannot be traversed.
Heuristic Function:
We use Manhattan distance or Octile distance as the heuristic ℎ(𝑛) 
h(n) is to estimate the cost from a node to the goal.
Steps
Start from the initial node.
Expand successors (children) of the current node.
For OR nodes, propagate the minimum estimated cost 
𝑓=𝑔+ℎ from children to the parent.
For AND nodes, propagate the sum of child costs.
Repeat recursively until the goal node is solved.
The minimal cost path is computed from start to goal.

Time Complexity
Worst Case: 𝑂(𝑏𝑛)O(bn), where:
𝑏 = branching factor (number of children per node)
𝑛 = maximum depth of the search tree
AO* may explore fewer nodes than naive exhaustive search because it prunes nodes using heuristics.

Space Complexity
Worst Case:𝑂(𝑏𝑛) , due to storage of:
All generated nodes/states
Heuristic values
Child pointers and visited tracking
Optimizations like storing only active paths can reduce memory usage.

Use Cases

Grid-Based Pathfinding / Robotics

Navigating robots or characters in a 2D map with obstacles.

Optimal path selection considering multiple sub-tasks.

Problem Reduction in AI

Decomposing complex problems into AND–OR graphs.

Game Trees / Strategy Games

Decision making where a move may require handling multiple opponent responses.

Planning and Diagnosis Systems

Task planning in robotics or workflow optimization.

Fault diagnosis where certain conditions must all be verified (AND nodes) or alternative paths can be chosen (OR nodes).
