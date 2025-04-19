## 2563. Count the number of Fair Pairs

### 🔍 Problem Statement

Given a **0-indexed** integer array `nums` of size `n` and two integers `lower` and `upper`, return the number of **fair pairs**.

A pair `(i, j)` is **fair** if:

- `0 <= i < j < n`, and  
- `lower <= nums[i] + nums[j] <= upper`

---

### 🗞 Examples

#### Example 1:
```txt
Input:  nums = [0,1,7,4,4,5], lower = 3, upper = 6  
Output: 6

Explanation: The fair pairs are:
(0,3), (0,4), (0,5), (1,3), (1,4), and (1,5)
```

#### Example 2:
```txt
Input:  nums = [1,7,9,2,5], lower = 11, upper = 11  
Output: 1

Explanation: The fair pair is: (2,3)
```

---

### ✅ Approach

1. Sort the array to enable binary search.
2. Iterate through each `i` from `0` to `n-1`.
3. For each `i`, use binary search to find:
   - The smallest index `low` such that `nums[i] + nums[low] >= lower`
   - The first index `up` where `nums[i] + nums[up] > upper`
4. The number of valid `j` values for each `i` is `up - low`
5. Accumulate the result.

---




---

### ⏱️ Time and Space Complexity
- **Time Complexity:** `O(n log n)` due to sorting and binary search
- **Space Complexity:** `O(1)` (ignoring input size)
