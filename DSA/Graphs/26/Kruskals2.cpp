#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

/*
This program implements Kruskal's Algorithm to find the Minimum Spanning Tree (MST) of a graph.

1. We represent the graph using an edge list (class `edge` stores u, v, and wt).
2. The `Graph` class maintains:
   - A list of edges.
   - DSU (Disjoint Set Union) arrays: `parent` and `rank` to efficiently detect cycles.
3. `addedge(u, v, wt)` adds an edge to the graph.
4. `find(x)` implements DSU "find with path compression" (to get representative parent of a node).
5. `unionByRank(u, v)` unites two sets using union by rank heuristic (keeps tree shallow).
6. `kruskal()`:
   - Sorts all edges in increasing order of weight.
   - Iterates through edges:
       - For each edge (u, v), find the parent of u and v using DSU.
       - If parents are different (`if(parU != parV)`), that means u and v belong to different sets → adding this edge will not form a cycle.
         So, include this edge in MST and union their sets.
       - Otherwise, skip (to avoid cycles).
   - Keep adding edges until MST is formed.
   - Prints the final minimum cost of MST.

Condition explained:
`if(parU != parV)` → ensures we only add edges that connect two different connected components. 
If they were the same (`parU == parV`), then adding that edge would create a cycle, which MST must avoid.
*/
class edge{
    public:
    int u;
    int v; 
    int wt;

    edge(int u, int v, int wt){
        this->u = u;
        this->v = v;
        this -> wt = wt;
    }
};

class Graph{
    public:
    int V;
    vector<edge> edges;

    vector<int> parent;
    vector<int> rank;

    Graph(int V){
        this -> V = V;

        for(int i =0; i< V; i++){
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    void addedge(int u , int v, int wt){
        edges.push_back(edge(u, v, wt));
    }

    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unionByRank(int u, int v){
        int parU = find(u);
        int parV = find(v);

        if(rank[parU] == rank[parV]){
            parent[parV] = parU;
            rank[parU]++;
        }
        else if(rank[parU] > rank[parV]){
            parent[parV] = parU;
        }
        else{
            parent[parU] = parV;
        }
    }

    void kruskal(){
        sort(edges.begin(), edges.end(), [](edge &a,edge &b){ // sorting in ascending order based on wt
            return a.wt < b.wt;
        });

        int minCost = 0;
        for(int i =0;i < edges.size(); i++){
            edge e = edges[i];
            
            int parU = find(e.u);
            int parV = find(e.v);
            if(parU != parV){
                unionByRank(parU, parV);
                minCost += e.wt;
            }
        }
        cout << "MST = " << minCost << endl;
    }
};

int main(){
    Graph graph(4);
    graph.addedge(0,1,10);
    graph.addedge(0,2,15);
    graph.addedge(0,3,30);
    graph.addedge(1,3,40);
    graph.addedge(2,3,50);
    graph.kruskal();
    return 0;
}