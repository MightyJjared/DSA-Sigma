#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

// here to detect a cycle , for a node w have 3 cases
// 1 - it has unvisited neighbours
// 2- it have visited neighbour but that neighbour is parent node so it cant be a cycle
// 3 - it has a visited neighbour and it isnt its parent so this is the case where we can cay a cycle exists.
// also back edge is the edge which is responsible for thegraph to become a cycle

// this is for undirected and unweighted graph
// Graph structure (Undirected & Unweighted)

// Question: Detect whether an undirected, unweighted graph contains a cycle.
// Approach: We use DFS with parent tracking. For each node, we check its neighbours.
// 1) If neighbour is unvisited → keep DFS.
// 2) If neighbour is visited but is the parent → ignore (not a cycle).
// 3) If neighbour is visited and not the parent → cycle exists.
// If any DFS path finds such a condition, return true.
// 
// Example Graph (Undirected):
//     0
//   / | \
//  1--2  3--4
//
// Edges:
// 0--1, 0--2, 0--3, 1--2, 3--4
//
// Cycle: 0-1-2-0 forms a cycle, so output = 1

// We use DFS for cycle detection because recursion + parent tracking makes it simple:
// if we reach a visited node that is not the parent → cycle exists.
// BFS also works but needs extra bookkeeping (queue + parent map), so DFS is preferred.



class Graph{
    int v;
    list<int>* l;

    public:
    Graph(int v){
        this->v = v;
        l = new list<int>[v];
    }

    void addedge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
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

    bool helper(int source, int parent, vector<bool> &visited){
        visited[source] = true;

        list<int> neighbour = l[source];
        for(auto itr : neighbour){
            if(visited[itr] == false){
                if(helper(itr, source, visited) == true){
                    return true;
                }
            }
            else{
                if(itr != parent){
                    return true;
                }
            }
        }
        return false;
    }

    bool cycle_detection(){
        vector<bool> visited(v, false);
        return helper(0, -1, visited);
    }

};

int main(){
    Graph graph(5);

    graph.addedge(0,1);
    graph.addedge(0,2);
    graph.addedge(0,3);
    graph.addedge(1,2);
    graph.addedge(3,4);
    
    cout << graph.cycle_detection();
    cout << endl;
    return 0;
}