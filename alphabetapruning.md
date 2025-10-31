#  Alpha-Beta Pruning

## Introduction

**Alpha-Beta Pruning** is a fundamental optimization technique for the **Minimax Algorithm**, widely used in **Artificial Intelligence** for two-player games such as Chess, Tic-Tac-Toe, and Checkers.  
The goal of the algorithm is to reduce the number of nodes evaluated in the search tree without affecting the final decision outcome.

By intelligently eliminating branches that cannot influence the final choice, alpha-beta pruning helps improve the efficiency of the Minimax search process.

---

## Problem Description

In a two-player game:
- One player is called **MAX**, whose goal is to maximize the score.
- The other player is **MIN**, whose goal is to minimize the score.
- The game can be represented as a **tree structure**, where:
  - Each node represents a game state.
  - Edges represent possible moves.
  - Leaf nodes represent terminal states with assigned utility values.

The **Minimax Algorithm** explores all possible moves to determine the best strategy.  
However, this exhaustive search becomes computationally expensive as the game tree grows larger.  
**Alpha-Beta Pruning** enhances Minimax by pruning branches that cannot possibly influence the final decision, thereby saving time and computation.

---

## Core Concept

During the traversal of the game tree:
- **Alpha (α)** represents the **best value that the maximizer can guarantee** at that point or above.
- **Beta (β)** represents the **best value that the minimizer can guarantee** at that point or above.
- The algorithm prunes (cuts off) a branch when:
  - **β ≤ α**
  - This condition means the current branch will not affect the final result.

---

## Example

Consider a small game tree:

       [A]
      /   \
    [B]   [C]
   / \    / \
  3   5  6   9

Using Minimax:
- MAX chooses between B and C.
- MIN within B chooses min(3, 5) = 3  
- MIN within C chooses min(6, 9) = 6  
- MAX chooses max(3, 6) = **6**

With Alpha-Beta Pruning:
- Certain branches are skipped once it’s clear they won’t change the outcome.  
- The same result (6) is obtained with fewer node evaluations.

---

## Algorithm Steps

1. Initialize α = -∞ and β = +∞.  
2. Traverse the game tree recursively using Minimax logic.  
3. At each **MAX** node:
   - Update α = max(α, current_value).
   - Prune if β ≤ α.  
4. At each **MIN** node:
   - Update β = min(β, current_value).
   - Prune if β ≤ α.  
5. Continue until the best value is determined for the root node.

---

