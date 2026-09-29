# Week 2 Assignments: Linked Lists in C

This folder contains my solutions for the Week 2 Data Structures assignments. The focus of this week is understanding and implementing singly linked lists in C, transitioning from basic static node creation to dynamic memory allocation and modular list operations.

## Folder Structure

```text
📁 Assignment_Folder
├── 📄 q1.c          # Solution for Question 1
├── 📄 q2.c          # Solution for Question 2
...
├── 📄 q10.c         # Solution for Question 10
├── 📄 q11.c         # Solution for Question 11
├── 📄 README.md     # Directory documentation
└── 📄 week2.pdf     # The assignment paper along with my answers
```

## Folder Structure & File Index

* **`q1.c`** - **Single Node Creation**: Demonstrates how to define a `struct Node`, assign a data value, and set the `next` pointer to `NULL`.
* **`q2.c`** - **Linking Two Nodes**: Shows how to connect two statically allocated nodes by pointing the first node's `next` to the address of the second.
* **`q3.c`** - **List Traversal**: Implements a `while` loop to traverse and print a three-node list sequentially.
* **`q4.c`** - **Dynamic Allocation (`malloc`)**: Creates a linked list dynamically using `malloc()` and safely releases the memory using `free()` to prevent leaks.
* **`q5.c`** - **Counting Nodes**: Traverses the list to calculate and print the total number of connected nodes.
* **`q6.c`** - **Summing Nodes**: Iterates through the list, accumulating the sum of all node data values.
* **`q7.c`** - **Searching an Element**: Searches for a user-input value within the linked list and breaks the loop upon a successful match.
* **`q8.c`** - **Inserting at the Beginning**: Adds a new node to the head of an existing linked list and updates the head pointer.
* **`q9.c`** - **Inserting at the End**: Traverses to the last node (where `next == NULL`) and appends a newly created node to the tail.
* **`q10.c`** - **Deleting a Node**: Finds a node containing a specific user-input value, securely removes it by rewiring the `previous` and `next` pointers, and frees the allocated memory.
* **`q11.c`** - **Modularized Linked List**: Refactors core operations into reusable functions, specifically implementing `insertBeginning()`, `display()`, and `search()`.

## Core Concepts Covered
* Structs and Pointers in C
* Static vs. Dynamic Memory Allocation (`malloc`, `sizeof`, `free`)
* Linked List Traversal (`current = current->next`)
* Safe Pointer Manipulation and Memory Management