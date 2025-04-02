Comparison: DP Using Map vs DP Using Matrix
Approach	Time Complexity	Space Complexity	When to Use?
DP Using Matrix (dp[n][sum])	O(n × sum)	O(n × sum)	When sum is small and fits in memory
DP Using Map (dp[i][sum] in an unordered_map)	O(n × sum) (average case)	O(n × distinct sums)	When sum is large (sparse states)
1️⃣ DP Using a Matrix (dp[n][sum])
How It Works:
We create a 2D matrix dp[i][s], where:

i represents the index (0 to n-1).

s represents the current sum (0 to target sum).

We fill the table iteratively or recursively with memoization.

Pros ✅:
✔ Fast Lookups: O(1) access time for dp[i][s].
✔ Easy to Implement: Classic table-based DP approach.

Cons ❌:
✖ High Space Usage (O(n × sum)): If sum is large (10^5), this may be too much memory.
✖ Wastes Space: Many states dp[i][s] are never used (sparse table).

2️⃣ DP Using a Map (unordered_map<int, unordered_map<int, bool>>)
How It Works:
Instead of using a full 2D matrix, we store only the states that are visited.

We store dp[i][s] only when necessary in an unordered_map (hash table).

Pros ✅:
✔ Efficient Space Usage: Uses memory only for reachable states, much better when sum is large.
✔ Works for Large sum: If sum = 10^9, matrix fails, but a map works.

Cons ❌:
✖ Slower Lookups: unordered_map has O(1) average case but O(n) worst case due to hash collisions.
✖ Overhead from Hashing: Extra time due to hashing keys.

🔍 Which One Should You Use?
If sum is small (≤ 10^4) → Use DP with a matrix (dp[n][sum]).

If sum is large (≥ 10^5) → Use DP with a map (unordered_map<int, unordered_map<int, bool>>).

If sum is very large (≥ 10^9) → Matrix is impossible, map is the only option.

