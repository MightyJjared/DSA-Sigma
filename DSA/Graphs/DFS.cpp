#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

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
        dfs_helper(0, visited);
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

    graph.dfs();

    return 0;
}