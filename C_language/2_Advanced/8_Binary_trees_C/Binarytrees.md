# Binary trees
## Introduction
A Binary Tree is a type of data structure in which each node has at most two children (left child and right child). Binary trees are used to implement binary search trees and binary heaps, and are used for efficient searching and sorting. A binary tree is a special case of a K-ary tree, where k is 2. Common operations for binary trees include insertion, deletion, and traversal. The difficulty of performing these operations varies if the tree is balanced and also whether the nodes are leaf nodes or branch nodes. For balanced trees the depth of the left and right subtrees of every node differ by 1 or less. This allows for a predictable depth also known as height. This is the measure of a node from root to leaf, where root is 0 and sebsequent nodes are (1,2..n). This can be expressed by the integer part of log2(n) where n is the number of nodes in the tree.

        g                  s                  9
       / \                / \                / \
      b   m              f   u              5   13
     / \                    / \                /  \
    c   d                  t   y              11  15
The operations performed on trees requires searching in one of two main ways: Depth First Search and Breadth-first search. Depth-first search (DFS) is an algorithm for traversing or searching tree or graph data structures. One starts at the root and explores as far as possible along each branch before backtracking. There are three types of depth first search traversal: pre-order visit, left, right, in-order left, visit, right, post-order left, right, visit. Breadth-first search (BFS) is an algorithm for traversing or searching tree or graph structures. In level-order, where we visit every node on a level before going to a lower level.

## Complete Binary Tree
A type of binary tree, where all levels are filled with nodes, and all levels except the last are fully filled, the last level is a tree that is filled from left to right.
All nodes have two child nodes except the last level. Fully binary trees are used in algorithms such as hip alignment.

## Binary Search Tree (BST)
A binary search tree is a binary tree that meets certain conditions. Based on a node N, the node's left subtree has nodes with all key values smaller than the key value of N, and the right subtree has nodes with all key values larger than the key value of N. Binary search trees allow you to visit nodes in ascending order of key values by performing a mid-order traversal.

## Breadth-First Search (BFS)
Indicates how to use Queue for the discovery of binary trees. By visiting nodes at each level, we start with the root node of the tree and navigate sequentially by level from left to right and from top to bottom. The reason for using queues in this process is to manage the navigation order.


The basic algorithm for width-first navigation is as follows.
1. Inserts the root node into the queue to start the discovery.
2. Repeat the following steps unless the queue is empty.
* Pull a node out of the queue.
* Processes the node. (Performance of Function)
* If there are child nodes on the left and child nodes on that node, insert them into the queue.

This approach visits all nodes, and since each node is processed once, it is very useful for exploring by area (level) not only in full binary trees but also in typical binary trees.