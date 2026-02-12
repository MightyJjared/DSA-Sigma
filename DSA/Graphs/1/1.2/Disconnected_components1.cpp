#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

// this is for undirected and unweighted graph
// Graph structure (Undirected & Unweighted)
/*
Question:
We want to perform BFS (Breadth-First Search) traversal on an undirected, 
unweighted graph. BFS visits all vertices level by level, starting from a 
given node. If the graph is disconnected (has multiple components), we 
run BFS on each unvisited component.

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
- BFS uses a queue and a visited array:
    1. Start from a node, mark it visited, push it into the queue.
    2. Repeatedly take a node from the queue, print it, and 
       push all its unvisited neighbours.
    3. Continue until the queue is empty.
- To handle disconnected graphs, we run BFS for every node 
  that hasn’t been visited yet (so all components are covered).
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

    void bfs_helper(int start, vector<bool> &visited){
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while(q.size() > 0){
            int u = q.front();
            q.pop();
            cout << u << " ";

            list<int> neighbours = l[u];
            for(auto itr : neighbours){
                if(visited[itr] == false){
                    visited[itr] = true;
                    q.push(itr);
                }
            }
        }
    }

    void bfs(){
        vector<bool> visited(v, false);
        for(int i =0; i< v; i++){
            if(visited[i] == false){
                bfs_helper(i, visited);
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

    graph.bfs();

    return 0;
}