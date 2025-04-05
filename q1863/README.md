# XOR Sum of All Subsets

## Problem Statement
The **XOR total** of an array is defined as the bitwise XOR of all its elements, or `0` if the array is empty.

Given an array `nums`, return the **sum of all XOR totals for every subset** of `nums`.

> **Note:** Subsets with the same elements but different indices are counted multiple times.
> An array `a` is a subset of an array `b` if `a` can be obtained from `b` by deleting some (possibly zero) elements of `b`.

## Examples

### Example 1
**Input:**
```plaintext
nums = [1,3]
```
**Output:**
```plaintext
6
```
**Explanation:**
Subsets: [], [1], [3], [1,3]
XOR Totals: 0, 1, 3, 2
Sum: 0 + 1 + 3 + 2 = **6**

### Example 2
**Input:**
```plaintext
nums = [5,1,6]
```
**Output:**
```plaintext
28
```
**Explanation:**
Subsets: [], [5], [1], [6], [5,1], [5,6], [1,6], [5,1,6]
XOR Totals: 0, 5, 1, 6, 4, 3, 7, 2
Sum: 0 + 5 + 1 + 6 + 4 + 3 + 7 + 2 = **28**

### Example 3
**Input:**
```plaintext
nums = [3,4,5,6,7,8]
```
**Output:**
```plaintext
480
```

## Constraints
- `1 <= nums.length <= 12`
- `1 <= nums[i] <= 20`

## Approach
We use **backtracking** to generate all subsets and calculate their XOR total.
The total number of subsets for an array of length `n` is `2^n`, so we can explore each subset using recursion or iteration efficiently (since `2^12 = 4096`).


## Complexity Analysis
- **Time Complexity:** `O(2^n)`, where `n` is the length of `nums`, for generating all subsets.
- **Space Complexity:** `O(n)` due to recursion depth.

## Conclusion
This problem emphasizes understanding subsets, bitwise XOR operations, and recursive backtracking. With a maximum size of 12 elements, the problem allows us to explore all subset combinations efficiently.

