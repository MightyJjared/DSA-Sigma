#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

/*
    LeetCode Reference: 787. Cheapest Flights Within K Stops
    --------------------------------------------------------
    Question:
    You are given:
      - n cities (labeled from 0 to n-1).
      - an array flights where flights[i] = [u, v, w] 
        means there is a flight from city u to city v with cost w.
      - integers src (source city), dst (destination city), and k (maximum allowed stops).

    You need to find the cheapest price from src to dst with at most k stops.
    If no such route exists, return -1.

    Key Points:
    - "At most k stops" means the path can use up to k+1 edges (flights).
    - Edge weights (flight costs) are positive.
    - The problem is basically "shortest path with a constraint on number of stops".

    Approach in this code (BFS-like traversal):
    --------------------------------------------
    - We define a class 'info' to keep track of:
         u     -> current city
         cost  -> total cost so far
         stops -> how many stops we have taken so far
    - We use a queue (BFS style) to explore neighbors level by level (stops-wise).
    - For each popped node, we check all outgoing flights:
         if going to a neighbor gives a cheaper cost and doesn't exceed k stops,
         we update distance and push that neighbor into the queue.
    - Finally, we check dist[dst]. If it is still INT_MAX, no path exists.

    Why BFS works here:
    - Since we are limiting by number of stops (levels), BFS ensures
      we do not explore paths longer than allowed stops.
    - We still maintain a 'dist' array to ensure we only relax when
      we find a strictly cheaper path.

    Time Complexity:
    - O(V * E) in the worst case, since each edge can be relaxed multiple times.
    - Acceptable for typical constraints in this problem.
*/

class Solution {
public:
    class info {
    public:
        int u;
        int cost;
        int stops;
        info(int u, int cost, int stops) {
            this->u = u;
            this->cost = cost;
            this->stops = stops;
        }
    };

    int findCheapestPrice(int v, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<info> q;
        vector<int> dist(v, INT_MAX);
        dist[src] = 0;

        // start from src, cost = 0, stops = -1 (so first edge gives stops = 0)
        q.push(info(src, 0, -1));

        while (!q.empty()) {
            info current = q.front();
            q.pop();

            for (int i = 0; i < flights.size(); i++) {
                if (flights[i][0] == current.u) {
                    int v = flights[i][1];
                    int wt = flights[i][2];

                    if (dist[v] > current.cost + wt && current.stops + 1 <= k) {
                        dist[v] = current.cost + wt;
                        q.push(info(v, dist[v], current.stops + 1));
                    }
                }
            }
        }

        if (dist[dst] == INT_MAX) {
            return -1;
        }
        return dist[dst];
    }
};

// ---------------- Main function to test ----------------
int main() {
    Solution sol;

    // Example test case:
    // 4 cities (0,1,2,3), flights = [[0,1,100],[1,2,100],[2,3,100],[0,3,500]]
    // src = 0, dst = 3, k = 1
    // Path: 0 -> 1 -> 2 -> 3 has 2 stops (not allowed for k=1).
    // Cheapest with <= 1 stop is direct 0 -> 3 = 500
    // Another path with <=1 stop is 0->1->2->... (not valid since 2 stops).
    // So answer = 500
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 3, 100},
        {0, 3, 500}
    };

    int n = 4;
    int src = 0;
    int dst = 3;
    int k = 1;

    int ans = sol.findCheapestPrice(n, flights, src, dst, k);
    cout << "Cheapest Price from " << src << " to " << dst 
         << " with at most " << k << " stops = " << ans << endl;

    return 0;
}
