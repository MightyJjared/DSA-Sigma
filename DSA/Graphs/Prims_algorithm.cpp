#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

/*
------------------------------------------
Minimum Spanning Tree (MST)
------------------------------------------
- A spanning tree of a graph is a subgraph that:
   1. Includes ALL vertices
   2. Has exactly (V-1) edges (tree property → no cycles)
   3. Is connected

- MST = Spanning tree with the minimum total edge weight.

Conditions for MST:
1. Graph must be undirected
2. Graph must be connected
3. Edge weights must be non-negative

------------------------------------------
Our Graph (4 vertices, 5 edges):

    (10)
  0 ----- 1
  | \     |
(15) \    | (40)
  |   \   |
  2    \  3
   \    /
   (50)(30)

Edges:
0-1 (10), 0-2 (15), 0-3 (30), 1-3 (40), 2-3 (50)

------------------------------------------
Prim’s Algorithm (Approach):
1. Start from any source vertex (here src = 0).
2. Maintain a priority queue (min-heap) of edges by weight.
3. At each step, pick the minimum weight edge that connects a new vertex to MST.
4. Repeat until all vertices are included.
------------------------------------------
Final MST edges chosen:
- 0--1 (10)
- 0--2 (15)
- 0--3 (30)

Total MST Cost = 10 + 15 + 30 = 55
------------------------------------------
*/

class Graph{
    int v;
    list<pair<int,int>>* l;

    public:
    Graph(int v){
        this->v = v;
        l = new list<pair<int,int>>[v];
    }

    void addedge(int u, int v, int weight){
        // Since MST is only defined for undirected graphs,
        // we add both u->v and v->u
        l[u].push_back(make_pair(v,weight));
        l[v].push_back(make_pair(u, weight));
    }

    void prim(int src){
        vector<bool> mst(v,false); // tracks whether a vertex is already in MST
        // Min-heap priority queue storing (weight, vertex)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

        pq.push(make_pair(0,src)); // Start with source having 0 cost
        int ans =0; // store final MST weight

        while(pq.size() > 0){
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            // Only include this vertex if it's not already in MST
            if(mst[u] == false){
                mst[u] = true;
                ans += wt; // add edge weight to MST total cost

                // Push all edges of this vertex into PQ
                list<pair<int, int>> neighbour = l[u];
                for(auto itr : neighbour){
                    pq.push(make_pair(itr.second, itr.first));
                }
            }
        }
        cout << "Final cost of MST : " << ans << endl;
    }
};

int main(){
    Graph graph(4);

    // Adding all edges (undirected weighted graph)
    graph.addedge(0, 1, 10);
    graph.addedge(0, 2, 15);
    graph.addedge(0, 3, 30);
    graph.addedge(1, 3, 40);
    graph.addedge(2, 3, 50);
    
    // Run Prim's Algorithm from source 0
    graph.prim(0);

    return 0;
}
