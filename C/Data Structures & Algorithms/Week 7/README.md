# Week 7 Assignment: Treasure Tree Game (Recursive BST Search)

This folder contains the solution for the Week 7 Data Structures assignment. The focus of this week is applying recursive Binary Search Tree (BST) operations to simulate a search game while measuring search steps and tree height metrics.

## Folder Structure

```text
📁 Week 7
└── 📄 q1.c    # Treasure Tree Game (Recursive Search & Height Calculation)

```

## Concept Overview

* **Recursive Search ( $O(h)$ ):** Implements a recursive search function that navigates left or right based on value comparisons.
* **Step-by-Step Traversal Logging:** Prints each visited node dynamically at every recursion level.
* **Worst-Case Step Analysis:** Computes tree height using `getHeight()` to establish the absolute maximum steps required to find any target node ($h = \text{Height of Tree}$).