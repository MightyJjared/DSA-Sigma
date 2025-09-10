#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

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