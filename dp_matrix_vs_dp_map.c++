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



////////////////////////////////////////////////////////////////////////

Why Think Recursively First?
Natural Problem Breakdown

Many DP problems have an optimal substructure, meaning the solution depends on smaller subproblems.

Thinking recursively helps break the problem down into these smaller, intuitive cases.

Identifying States

Recursion helps us define state variables like i (index) and sum (current sum).

This makes it easier to design a DP table for bottom-up.

Understanding Choices (Transition Formula)

A recursive approach forces you to make choices:

Include the current element? → solve(i-1, sum - arr[i])

Exclude the current element? → solve(i-1, sum)

These choices directly translate into DP table transitions.

Memoization to Bottom-Up Conversion

A top-down (memoized) solution is just a recursive solution + caching.

Converting memoized recursion to bottom-up DP is straightforward:

Remove recursion.

Fill DP table iteratively.

Example: Subset Sum Problem
1️⃣ Recursive Approach (Without DP)
cpp
Copy
Edit
bool subsetSumRecursive(vector<int>& arr, int i, int sum) {
    if (sum == 0) return true;    // Base case: Target sum achieved
    if (i == 0) return arr[0] == sum; // Base case: Only one element left

    // Exclude the current element
    bool exclude = subsetSumRecursive(arr, i - 1, sum);

    // Include the current element (if possible)
    bool include = (sum >= arr[i]) ? subsetSumRecursive(arr, i - 1, sum - arr[i]) : false;

    return include || exclude;
}
2️⃣ Memoization (Top-Down DP)
cpp
Copy
Edit
vector<vector<int>> dp;
bool subsetSumMemoized(vector<int>& arr, int i, int sum) {
    if (sum == 0) return true;
    if (i == 0) return arr[0] == sum;
    if (dp[i][sum] != -1) return dp[i][sum];  // Memoization

    bool exclude = subsetSumMemoized(arr, i - 1, sum);
    bool include = (sum >= arr[i]) ? subsetSumMemoized(arr, i - 1, sum - arr[i]) : false;

    return dp[i][sum] = include || exclude;
}
3️⃣ Bottom-Up DP (Iterative)
cpp
Copy
Edit
bool subsetSumBottomUp(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    // Base case: Sum 0 is always achievable with an empty subset
    for (int i = 0; i <= n; i++) dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int sum = 1; sum <= target; sum++) {
            if (sum >= arr[i - 1])
                dp[i][sum] = dp[i - 1][sum] || dp[i - 1][sum - arr[i - 1]];
            else
                dp[i][sum] = dp[i - 1][sum];
        }
    }

    return dp[n][target];
}

graph
Here’s a clear and simple introduction to Graphs in data structures and algorithms:


---

📌 What is a Graph?

A graph is a data structure used to represent a set of objects (called nodes or vertices) and the connections between them (called edges).

Graphs are widely used in real-life scenarios like:

Social networks (users = nodes, friendships = edges)

Maps (cities = nodes, roads = edges)

Internet (web pages = nodes, links = edges)



---

🔗 Basic Terminology

Term	Meaning

Vertex (plural: vertices)	A point or node in the graph
Edge	A line connecting two vertices
Adjacent vertices	Vertices connected directly by an edge
Degree of a vertex	Number of edges connected to it
Path	A sequence of vertices where each pair is connected by an edge
Cycle	A path that starts and ends at the same vertex



---

🧭 Types of Graphs

1. Directed Graph (Digraph): Edges have a direction (A → B)


2. Undirected Graph: Edges have no direction (A — B)


3. Weighted Graph: Each edge has a weight or cost (like distance or time)


4. Unweighted Graph: Edges have no weight


5. Cyclic vs Acyclic: A cyclic graph has at least one cycle; an acyclic graph does not


6. Connected Graph: There is a path between every pair of vertices (only in undirected)


7. Disconnected Graph: Some vertices are not connected




---

📋 Graph Representations

1. Adjacency Matrix:

2D array (V x V) where matrix[i][j] = 1 means there is an edge from vertex i to j

Space: O(V²)



2. Adjacency List:

Array of lists. Each index stores a




