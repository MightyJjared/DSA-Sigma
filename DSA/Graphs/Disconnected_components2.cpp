#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

// this is for undirected and unweighted graph
// Graph structure (Undirected & Unweighted)

/*
Question:
We want to perform DFS (Depth-First Search) traversal on an undirected, 
unweighted graph. DFS explores as far as possible along one path before 
backtracking, visiting nodes in a "deep" manner. If the graph is disconnected, 
we run DFS separately for each unvisited component.

Graph example in this code:
Component 1:
    1 -- 6 -- 4 -- 9
          |
          3
         / \
        8   7

Component 2:
    0 -- 2 -- 5

Approach:
- Represent the graph using an adjacency list (array of linked lists).
- Use a visited array to keep track of visited nodes.
- DFS is implemented using recursion:
    1. Start from a node, mark it visited, and print it.
    2. Recursively visit all unvisited neighbours.
- To handle disconnected graphs, we loop through all vertices 
  and call DFS on each unvisited node.
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

    void dfs_helper(int v, vector<bool> &visited){
        visited[v] = true;
        cout << v << " ";

        list<int> neighbours = l[v];
        for(auto itr : neighbours){
            if(visited[itr] == false){
                dfs_helper(itr, visited);
            }
        }
    }

    void dfs(){
        vector<bool> visited (v, false);
        for(int i =0; i< v; i++){
            if(visited[i] == false){
                dfs_helper(i, visited);
                cout << endl;
            }
        }
    }
};

int main(){
    Graph graph(10);

    graph.addedge(1,6);
    graph.addedge(6,4);
    graph.addedge(4,9);
    graph.addedge(4,3);
    graph.addedge(3,8);
    graph.addedge(3,7);

    graph.addedge(0,2);
    graph.addedge(2,5);

    graph.dfs();

    return 0;
}