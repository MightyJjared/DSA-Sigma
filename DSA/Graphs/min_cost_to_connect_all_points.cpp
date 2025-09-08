#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

/*
LeetCode Reference: 1584. Min Cost to Connect All Points
Link: https://leetcode.com/problems/min-cost-to-connect-all-points/

Question:
--------------------------------
You are given an array of points where points[i] = [xi, yi] 
represents a point on the 2D plane. The cost of connecting two points 
[xi, yi] and [xj, yj] is the Manhattan distance between them:
    cost = |xi - xj| + |yi - yj|

We need to connect all points such that the total cost is minimized. 
The result should be the weight (sum of costs) of the Minimum Spanning Tree (MST).

--------------------------------
Approach (Prim's Algorithm for MST):
1. Treat each point as a vertex in a graph. 
2. The weight of an edge between two vertices (points) is their Manhattan distance.
3. Use Prim’s Algorithm:
   - Start from any node (here, 0).
   - Use a Min-Heap (priority_queue with greater comparator) to always pick 
     the smallest edge that connects a new vertex to the MST.
   - Keep adding edges until all points are included in the MST.
4. The sum of these selected edges = minimum cost to connect all points.

--------------------------------
Time Complexity:
- Each insertion into the priority queue is O(log V).
- For each node, we may push up to O(V) edges into the priority queue.
- So, worst case complexity = O(V^2 log V).

--------------------------------
*/

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int v = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq; // (wt,vertex)
        vector<bool> mst(v,false);
        int src = 0;
        int minCost = 0;
        pq.push(make_pair(0,src));

        while(pq.size() > 0){
            int wt = pq.top().first;
            int u = pq.top().second;

            pq.pop();
            if(mst[u] == false){
                mst[u] = true;

                minCost += wt;

                for(int i =0; i < v; i++){
                    if(u != i){
                        wt = abs(points[u][0] - points[i][0]) + abs(points[u][1] - points[i][1]);
                        pq.push(make_pair(wt, i));
                    }
                }
            }
        }
        return minCost;
    }
};

int main() {
    Solution sol;

    // Example Input (can be modified for testing)
    vector<vector<int>> points = {{3,12},{-2,5},{-4,1}};

    int result = sol.minCostConnectPoints(points);

    cout << "Minimum Cost to Connect All Points = " << result << endl;

    return 0;
}
