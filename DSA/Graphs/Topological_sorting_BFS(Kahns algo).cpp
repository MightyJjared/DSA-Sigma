#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <queue>
using namespace std;
// for topological sorting the graph should be directed and there shouldnt be any cycles.

/*
Question: Perform Topological Sort on a Directed Acyclic Graph (DAG).
/*
Question: Perform Topological Sort on a Directed Acyclic Graph (DAG).

Approach (Kahn’s Algorithm / BFS):
1. Compute in-degree of every vertex.
2. Push all vertices with in-degree 0 into a queue.
3. Repeatedly remove a vertex from the queue, print it, and decrease in-degree of its neighbors.
4. If any neighbor’s in-degree becomes 0, push it into the queue.
This ensures nodes are processed only after all their prerequisites are handled.


Approach:


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

    void getInDegree(vector<int> &inDegree){
        for(int i =0; i< v; i++){
            list<int> neighbours = l[i];
            for(auto itr : neighbours){
                inDegree[itr]++;
            }
        }
    }

    void topological(){
        queue<int> q;

        vector<int> inDegree(v, 0);
        getInDegree(inDegree);
        
        for(int i =0; i < v; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        while(q.size() > 0){
            int u = q.front();
            q.pop();

            cout << u << " ";
            list<int> neighbour = l[u];
            for(auto itr : neighbour){
                inDegree[itr]--;
                if(inDegree[itr] == 0){
                    q.push(itr);
                }
            }
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