Recursive Function (recur)

Base Case: If idx exceeds or equals the size of questions, return 0 (no more questions to solve).

Memoization Check: If the result for idx is already computed (dp[idx] != -1), return dp[idx].

Two Choices at Each Step:

Skip the current question and move to idx + 1.

Solve the current question: Take the points from questions[idx][0] and move to idx + questions[idx][1] + 1 (skipping the required number of questions).

Store the maximum of the two choices in dp[idx] to avoid recomputation.

Memoization (dp array)

A dp array of size questions.size() is used to store previously computed results, avoiding redundant calculations.

Driver Function (mostPoints)

Initializes dp with -1 to indicate uncomputed states.

Calls recur(questions, 0, dp) to start from the first question.

Time Complexity Analysis
Recursion without Memoization: 
𝑂(2^𝑁)
(Exponential due to overlapping subproblems)

With Memoization: 
O(N)
Each idx is computed only once and stored in dp, leading to O(N) recursive calls.
Each call does O(1) work.
