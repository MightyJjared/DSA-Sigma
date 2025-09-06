#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <queue>
using namespace std;
// for topological sorting the graph should be directed and there shouldnt be any cycles.

/*
Question: Perform Topological Sort on a Directed Acyclic Graph (DAG).

Approach:
We use Depth First Search (DFS) with a stack.
1. Visit each unvisited node.
2. Recursively visit its neighbours.
3. After exploring all neighbours, push the current node into the stack.
4. Finally, pop all nodes from the stack to get the Topological Order.

Graph (Directed):
    5 → 0 ← 4
    ↓       ↑
    2 → 3 → 1

Edges:
2 → 3
3 → 1
4 → 0
4 → 1
5 → 0
5 → 2
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

    void helper(int src, vector<bool> &visited,stack<int> &s){
        visited[src] = true;

        list<int> neighbours = l[src];
        for(auto itr : neighbours){
            if(visited[itr] == false){
                helper(itr, visited, s);
            }
        }
        s.push(src);
    }

    void topological(){
        vector<bool> visited (v, false);
        stack<int> s;
        for(int i =0; i< v ; i++){
            if(visited[i] == false){
                helper(i, visited, s);
            }
        }

        while(s.size() > 0){
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
};

int main(){
    Graph graph(6);

    graph.addedge(2,3);
    graph.addedge(3,1);
    graph.addedge(4,0);
    graph.addedge(4,1);
    graph.addedge(5,0);
    graph.addedge(5,2);
    

    graph.topological();

    return 0;
}