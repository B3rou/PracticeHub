# Week 10 Assignment: Graph Data Structures (BFS & DFS)

This folder contains my solution for the Week 10 Data Structures assignment covering undirected graph representations and fundamental traversal algorithms.

## Folder Structure

```text
📁 Week 10
└── 📄 q1.c    # City Network Graph with Adjacency List, BFS, and DFS

```

## Concept Overview

* **Adjacency List Representation ($ O(V + E) $ Space):** Dynamically allocates linked lists for each city vertex to store neighboring connections efficiently.
* **Breadth-First Search (BFS):** Explores the graph level-by-level using a dynamically allocated FIFO Queue ($ O(V + E) $ time complexity).
* **Depth-First Search (DFS):** Explores as far as possible along each branch before backtracking via recursion ($ O(V + E) $ time complexity).