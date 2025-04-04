# Lowest Common Ancestor of Deepest Leaves

## Problem Statement
Given the root of a binary tree, return the lowest common ancestor (LCA) of its deepest leaves.

### Definitions:
- A node in a binary tree is a **leaf** if and only if it has no children.
- The **depth** of the root of the tree is `0`. If the depth of a node is `d`, the depth of each of its children is `d + 1`.
- The **lowest common ancestor (LCA)** of a set `S` of nodes is the node `A` with the largest depth such that every node in `S` is in the subtree with root `A`.

## Examples

### Example 1
**Input:**
```plaintext
root = [3,5,1,6,2,0,8,null,null,7,4]
```
**Output:**
```plaintext
[2,7,4]
```
**Explanation:**
- The node with value `2` is the LCA of the deepest leaf nodes `7` and `4`.
- Nodes `6`, `0`, and `8` are also leaf nodes but have a depth of `2`, while `7` and `4` have a depth of `3`.

### Example 2
**Input:**
```plaintext
root = [1]
```
**Output:**
```plaintext
[1]
```
**Explanation:**
- The root itself is the deepest node and thus its own LCA.

### Example 3
**Input:**
```plaintext
root = [0,1,3,null,2]
```
**Output:**
```plaintext
[2]
```
**Explanation:**
- The deepest leaf node in the tree is `2`, and the LCA of a single node is itself.

## Constraints
- The number of nodes in the tree is in the range `[1, 1000]`.
- `0 <= Node.val <= 1000`
- The values of the nodes in the tree are **unique**.

## Approach
To solve this problem efficiently, we can use a **recursive depth-first search (DFS)** strategy:
1. Compute the depth of each subtree.
2. Identify the deepest leaves.
3. Traverse back up to find the lowest common ancestor of these deepest leaves.


## Complexity Analysis
- **Time Complexity:** `O(N)`, where `N` is the number of nodes in the tree (each node is visited once).
- **Space Complexity:** `O(H)`, where `H` is the height of the tree (recursion stack depth).

## Conclusion
This approach effectively finds the LCA of the deepest leaves in a binary tree using recursion in an optimal `O(N)` time complexity. This method ensures an efficient solution suitable for trees up to 1000 nodes.

