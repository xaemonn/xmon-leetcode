# Partition Equal Subset Sum

## 🧩 Problem Statement

Given an integer array `nums`, return `true` if you can partition the array into two subsets such that the sum of the elements in both subsets is equal. Otherwise, return `false`.

### 🔒 Constraints:
- `1 <= nums.length <= 200`
- `1 <= nums[i] <= 100`

---

## 🧠 Approach (Recursive + Memoization)

This problem is a variation of the classic **Subset Sum Problem** and can be solved using **top-down recursion with memoization**.

### Steps:

1. **Calculate Total Sum**:
   - First, compute the total sum of all elements in the array.
   - If the sum is **odd**, return `false` since it's impossible to split an odd number evenly.

2. **Define Target**:
   - If the total sum is even, the target for each subset becomes `sum / 2`.

3. **Recursive Strategy**:
   - Start from index `0` and a current sum `curr = 0`.
   - At each step, try two options:
     - **Pick** the current element and add it to `curr`.
     - **Skip** the current element and move to the next.

4. **Base Conditions**:
   - If `curr == target`: we found a valid subset — return `true`.
   - If `curr > target` or `idx >= nums.size()`: return `false`.

5. **Memoization**:
   - Use a 2D `dp` table (`dp[idx][curr]`) to store intermediate results and avoid recomputation of overlapping subproblems.

---

## 📈 Time & Space Complexity

- **Time Complexity:** `O(n * target)`  
  Where `n` is the number of elements, and `target = sum / 2`.

- **Space Complexity:** `O(n * target)`  
  Due to the memoization table.
