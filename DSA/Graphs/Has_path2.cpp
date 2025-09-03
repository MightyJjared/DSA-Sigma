#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

/*
Question:
We want to check if there exists a path between a given source node and a 
destination node in an undirected, unweighted graph. In other words, 
starting from 'source', can we reach 'dest' by following the edges of the graph?

Approach:
We use Breadth-First Search (BFS) starting from the source node.
- A queue is used to explore nodes level by level.
- A visited array keeps track of which nodes are already explored to avoid cycles and repetition.
- We enqueue the source and mark it visited.
- While the queue is not empty:
    • Remove the front node (u).
    • If u == dest, we found a path → return true.
    • Otherwise, enqueue all unvisited neighbours of u and mark them visited.
- If BFS finishes and we never encounter 'dest', then no path exists → return false.

This ensures that if any path exists between source and destination, BFS will find it.
*/


// this is for undirected and unweighted graph
// Graph structure (Undirected & Unweighted)
//
//    0
//   / \
//  1   2
//  |   |
//  3---4
//   \ /
//    5
//    |
//    6
//
// Edges:
// 0 -- 1
// 0 -- 2
// 1 -- 3
// 2 -- 4
// 3 -- 4
// 3 -- 5
// 4 -- 5
// 5 -- 6
//
// BFS starting from 0 →  0 1 2 3 4 5 6
//

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
    

    bool Has_path(int source, int dest){
        queue<int> q;
        vector<bool> visited(v, false);

        q.push(source);
        visited[source] = true;

        while(q.size() > 0){
            int u = q.front();
            if(u == dest){
                return true;
                break;
            }
            q.pop();

            list<int> neighbours = l[u];
            for(auto itr : neighbours){
                if(visited[itr] == false){
                    visited[itr] = true;
                    q.push(itr);
                }
            }
        }
        return false;    
    }
};

int main(){
    Graph graph(7);

    graph.addedge(0,1);
    graph.addedge(0,2);
    graph.addedge(1,3);
    graph.addedge(2,4);
    graph.addedge(3,4);
    graph.addedge(3,5);
    graph.addedge(4,5);
    graph.addedge(5,6);

    cout << graph.Has_path(0,5) << endl;
    return 0;
}