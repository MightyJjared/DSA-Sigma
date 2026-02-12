#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

// here instead of list we used vector<int> [v]
// time complexity and space complexity = O(v + E) where is Edges
// for directed graph in class remove  l[v].push_back(u);
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
    vector<int> *l;

    public:
    Graph(int v){
        this->v = v;
        l = new vector<int> [v];
    }
    

    void addedge(int u, int v){
        l[v].push_back(u);
        l[u].push_back(v);
    }

    void bfs(){
        queue<int> q;
        vector<bool> visited(v, false);
        q.push(0);
        visited[0] = true;

        while(q.size() > 0){
            int u = q.front();
            q.pop();

            cout << u << " ";
            for(auto itr : l[u]){
                if(visited[itr] == false){
                    visited[itr] = true;
                    q.push(itr);
                }

            }
        }
        cout << endl;
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

    graph.bfs();
    //graph.print();
    return 0;
}