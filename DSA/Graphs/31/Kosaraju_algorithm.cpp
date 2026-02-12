#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <queue>
using namespace std;

/*
    Kosaraju's Algorithm:
    ---------------------
    - Purpose: To find Strongly Connected Components (SCCs) in a directed graph.
    - SCC definition: A maximal subgraph where every vertex is reachable from every other vertex.
      (i.e., you can go from any node A to B and also from B to A).

    Steps:
    1. Do a DFS on the original graph, pushing vertices into a stack in order of finishing time.(exactly topological)
    2. Build the transpose graph (reverse direction of all edges).
    3. Pop vertices from the stack; for each unvisited node, run DFS on the transpose graph.
       Each DFS call gives one SCC.
*/

class Graph{
    int v;
    list<int>* l;

    public:
    Graph(int v){
        this->v = v;
        l = new list<int>[v];
    }

    void addedge(int u, int v){
        l[u].push_back(v); // directed edge u -> v
    }

    // DFS on transpose graph (used in 2nd phase of Kosaraju)
    void dfs(int src, vector<bool> &visited, list<int>* transpose){
        visited[src] = true;
         
        cout << src << " "; // print node as part of current SCC

        list<int> neighbour = transpose[src];
        for(auto itr : neighbour){
            if(visited[itr] == false){
                dfs(itr, visited, transpose);
            }
        }
    }

    // First DFS (for ordering nodes by finish time)
    void topological(int src, vector<bool> &visited, stack<int> &s){
        visited[src] = true;

        list<int> neighbour = l[src];
        for(auto itr : neighbour){
            if(visited[itr] == false){
                topological(itr, visited, s);
            }
        }
        s.push(src); // push after visiting all neighbours
    }

    void Kosaraju(){
        vector<bool> visited(v, false);
        stack<int> s;

        // Step 1: Fill stack with nodes in finishing order
        for(int i =0; i<v; i++){
            if(visited[i] == false){
                topological(i, visited, s);
            }
        }

        // Step 2: Build transpose graph
        list<int>* transpose;
        transpose = new list<int>[v];
        for(int i =0; i < v; i++){
            list<int> neighbour = l[i];
            for(auto itr : neighbour){
                transpose[itr].push_back(i); // reverse edge
            }
        }

        // Step 3: Process nodes in order of stack
        vector<bool> visited1(v, false);
        while(s.size() > 0){
            int u = s.top();
            s.pop();
            if(visited1[u] == false){
                dfs(u, visited1, transpose); // one SCC
                cout << endl;
            }
        }
    }
    
};

int main(){
    Graph graph(5);

    /*
        Graph:
        0 -> 2, 3
        1 -> 0
        2 -> 1
        3 -> 4

        Strongly Connected Components (SCCs) are:
        {0,1,2}  (they form a cycle)
        {3}
        {4}    (mutually reachable)
    */

    graph.addedge(0,2);
    graph.addedge(0,3);
    graph.addedge(1,0);
    graph.addedge(2,1);
    graph.addedge(3,4);
    
    cout << "Strongly connected components are : " << endl;
    graph.Kosaraju();

    return 0;
}
