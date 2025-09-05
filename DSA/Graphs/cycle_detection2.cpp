#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

// Question: Detect if a directed graph contains a cycle.
//
// Example Graph (Directed):
//    1 → 0 → 2 → 3
//          ↑     ↓
//          └─────┘
//
// In this graph, we clearly have a cycle: 0 → 2 → 3 → 0.
//
// Approach (DFS + Recursion Stack):
// - We use two arrays: visited[] and recursive_path[].
//   • visited[] tells us if a node has been fully explored.
//   • recursive_path[] tracks the nodes currently in the recursion call stack.
// - For each node:
//     1. Mark it as visited and add it to recursive_path.
//     2. Explore its neighbors:
//        - If a neighbor is unvisited → DFS deeper.
//        - If a neighbor is already in recursive_path → cycle detected.
//     3. Backtrack: remove the node from recursive_path.
// - If we finish exploring all nodes without finding such a case → no cycle.

// We use DFS for cycle detection because recursion + parent tracking makes it simple:
// if we reach a visited node that is not the parent → cycle exists.
// BFS also works but needs extra bookkeeping (queue + parent map), so DFS is preferred.



class Graph{
    int v;
    list<int>* l;
    bool is_undirected;

    public:
    Graph(int v, bool is_undirected = true){
        this->v = v;
        l = new list<int>[v];
        this->is_undirected = is_undirected;
    }

    void addedge(int u, int v){
        l[u].push_back(v);
        if(is_undirected){
            l[v].push_back(u);
        }
    }

    void print(){
        for(int i =0; i< v; i++){
            list<int> neighbours = l[i];
    
            cout << i << " : ";
            for(int itr : neighbours){
               cout << itr << " ";
            }
            cout << endl;
        }
    }

    bool helper(int source, vector<bool> &recursive_path, vector<bool> &visited){
        visited[source] = true;
        recursive_path[source] = true;

        list<int> neighbour = l[source];
        for(auto itr : neighbour){
            if(visited[itr] == false){
                if(helper(itr, recursive_path, visited) == true){
                    return true;
                }
            }
            else{
                if(recursive_path[itr] == true){
                    return true;
                }
            }
        }
        recursive_path[source] = false;
        return false;
    }

    bool cycle_detection(){
        vector<bool> visited(v, false);
        vector<bool> recursive_path(v, false);

        for(int i =0; i< v ; i++){
            if(visited[i] == false){
            if(helper(i, recursive_path, visited) == true){
                return true;
            }
            }
        }
        return false;
    }

};

int main(){
    Graph graph(4, false);

    graph.addedge(1,0);
    graph.addedge(0,2);
    graph.addedge(2,3);
    graph.addedge(3,0);

    
    cout << graph.cycle_detection();
    cout << endl;
    return 0;
}