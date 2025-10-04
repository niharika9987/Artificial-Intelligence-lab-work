Blocks World Problem

Objective:

The Blocks World Problem is a classic problem in Artificial Intelligence (AI) and Cognitive Science.
We are given a set of blocks placed on a table, stacked in various configurations.
The goal is to transform the initial state of the blocks into a desired goal state using valid moves (such as picking up, putting down, stacking, and unstacking).
This problem is used to demonstrate planning, search strategies, and the power of logic programming with Prolog.

Algorithm (General Approach in Prolog)

Define States:
Each state represents a configuration of blocks (e.g., on(A,B) means block A is on block B).

Define Goal:

The target configuration of blocks (e.g., on(A,C), on(C,Table) ).

Define Operators (Moves):

pickup(X) → pick up block X from table.

putdown(X) → put block X on table.

stack(X,Y) → place block X on block Y.

unstack(X,Y) → remove block X from block Y.

Search/Planning:
Use depth-first search or breadth-first search to explore possible sequences of moves until the goal state is achieved.

Time Complexity

Number of Possible States:
Each block can either be: On the table, or On top of another block. 

So, the total number of distinct configurations is approximately:𝑂(𝑛^n).

This is because each of the n blocks has n possible placements (table or on another block).This grows faster than factorial (n!) as n increases.

Search Algorithms:

Depth-First Search (DFS):
Worst-case complexity is 𝑂(𝑏^𝑚)  where b is the branching factor (possible moves from a state) and m is the maximum depth of the search tree.

Breadth-First Search (BFS):
Worst-case complexity is 𝑂(𝑏^𝑑) where d is the depth of the shallowest solution.
(Guarantees the shortest solution but uses much more memory).

Space Complexity:

DFS: O(b * m), where b = branching factor, m = maximum depth.

BFS: O(b^d), where d = depth of the shallowest goal.

Space grows very fast due to the number of possible block configurations.

Use Cases of Prolog:

1)Artificial Intelligence (AI): Expert systems, planning, natural language processing.

2)Knowledge Representation & Reasoning: Modeling rules, facts, and logical inference.

3)Constraint Solving: Scheduling, optimization, puzzles.

4)Symbolic Computation: Semantic web, ontology reasoning.

Pros of Prolog:

1)Excellent for declarative problem-solving (you focus on what instead of how).

2)Built-in backtracking and pattern matching make it powerful for logic-heavy tasks.

3)Very expressive for AI planning, search problems, and rule-based systems.

Cons of Prolog:

1)Not widely adopted in modern mainstream development.

2)Performance is slower than imperative languages like C++ or Python.

3)Limited ecosystem compared to Java, Python, or C#.

Current Relevance:
Prolog is still taught in AI/CS courses because of its unique declarative approach.
Actively used in research, academic projects, and niche applications (e.g., theorem proving, natural language understanding).
However, in industry, it’s largely replaced by Python, Java, and ML/AI frameworks like TensorFlow, PyTorch.
