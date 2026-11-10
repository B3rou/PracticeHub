# Week 9 Assignment: AVL Trees, Rotations & Multi-way Search Trees

This folder contains my solutions for the Week 9 Data Structures assignment on Self-Balancing Binary Search Trees (AVL Trees) and Multi-way Search Tree concepts (2-3 Trees & Red-Black Trees).

## Folder Structure

```text
📁 Week 9
├── 📄 q1.c           # Single Left Rotation (RR Case) & Balance Factor Analysis
├── 📄 q2.c           # Generic insertAVL implementation for LL, RR, LR, and RL Cases
└── 📄 pekitirme.md   # Conceptual evaluation on Inorder invariant, 2-3 Trees, and Red-Black Trees

```

## File Index

* **`q1.c`**: Demonstrates sequential Balance Factor tracking and Single Left Rotation (`rotateLeft`) for RR imbalance resolution.
* **`q2.c`**: Implements a generic `insertAVL()` function handling all four imbalance configurations (`LL`, `RR`, `LR`, `RL`) dynamically using single and double rotations.
* **`pekitirme.md`**: Summarizes why Inorder traversal guarantees sorted output on BST/AVL structures and compares balancing trade-offs between AVL and Red-Black trees.

