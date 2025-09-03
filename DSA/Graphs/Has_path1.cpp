#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

/*
 Question:
 ---------
 We are given an undirected, unweighted graph. 
 We need to check if there exists a path between two given vertices (source and destination).

 Approach:
 ---------
 - We represent the graph using an adjacency list (array of lists).
 - To check if a path exists, we use DFS (Depth First Search):
     1. Start from the source node.
     2. Mark it as visited.
     3. Recursively explore all its neighbors that are not visited.
     4. If we reach the destination node during DFS, return true.
     5. If all paths are explored and destination is not reached, return false.

 Example:
 --------
 Graph structure (Undirected & Unweighted)
 
    0
   / \
  1   2
  |   |
  3---4
   \ /
    5
    |
    6

 Edges:
 0 -- 1
 0 -- 2
 1 -- 3
 2 -- 4
 3 -- 4
 3 -- 5
 4 -- 5
 5 -- 6

 Query: Is there a path from 0 to 5?
 Path exists → Output = 1 (true)
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

    bool path_helper(int source, int dest, vector<bool> &visited){
        if(source == dest){
            return true;
        }

        visited[source] = true;

        list<int> neighbours = l[source];

        for(auto itr : neighbours){
            if(visited[itr] == false){
                if(path_helper(itr, dest, visited) == true){
                    return true;
                }
            }
        }
        return false;
    }

    bool Has_path(int source, int dest){
        vector<bool> visited(v,false);
        return path_helper(source, dest, visited);
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

    cout << graph.Has_path(0,5) << endl; // Output: 1 (true)
    return 0;
}
