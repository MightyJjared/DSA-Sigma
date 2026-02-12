#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

// this is directed graph
// Question: Print all possible paths between two nodes in a directed graph.
// 
// Approach:
// - We use DFS with backtracking.
// - Maintain a visited[] array and a path string.
// - At each node, mark it visited and add it to path.
// - Recurse for all unvisited neighbors.
// - If we reach the destination, print the current path.
// - Backtrack: unmark the node and remove it from the path.

/*
    5 ----> 0 <---- 4
    |       |       |
    v       v       v
    2 ----> 3 -----> 1
*/

// for undirected exactly same

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
       // l[v].push_back(u);
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

    void dfs_helper(int src, int dest, vector<bool> &visited, string &path){
        if(src == dest){
            cout << path << dest << endl;
            return;
        }
        visited[src] = true;
        path += to_string(src);

        list<int> neighbours = l[src];
        for(auto itr : neighbours){
            if(visited[itr] == false){
                dfs_helper(itr, dest, visited, path);
            }
        }

        visited[src] = false;
        path = path.substr(0, path.size()-1);
        
    }

    void all_paths(int src, int dest){
        vector<bool> visited (v, false);
        string path = "";
        dfs_helper(src, dest, visited, path);
        cout << endl;
    }
};

int main(){
    Graph graph(6);

    graph.addedge(0,3);
    graph.addedge(2,3);
    graph.addedge(3,1);
    graph.addedge(4,0);
    graph.addedge(4,1);
    graph.addedge(5,0);
    graph.addedge(5,2);

    graph.all_paths(5,1);

    return 0;
}