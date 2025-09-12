#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <queue>
using namespace std;


class Graph {
    int v;             // number of vertices
    list<int>* l;      // adjacency list

public:
    Graph(int v) {
        this->v = v;
        l = new list<int>[v];
    }

    void addedge(int u, int v) {
        l[u].push_back(v); 
        l[v].push_back(u); // undirected edge
    }

    void dfs(int src, int &time, int parent, vector<int> &discovery_time, vector<int> &lowTime, vector<bool> &visited,
            vector<bool> &articulate){

        visited[src] = true;
        time++;
        discovery_time[src] = lowTime[src] = time;
        int children = 0;

        list<int> neighbours = l[src];
        for(auto itr : neighbours){
            if(itr == parent){
                continue;
            }
            else if(visited[itr] == false){
                dfs(itr, time, src, discovery_time, lowTime, visited, articulate);
                lowTime[src] = min(lowTime[src], lowTime[itr]);
                if(discovery_time[src] <= lowTime[itr] && parent != -1){
                    articulate[src] = true;
                }
                children++;

            }
            else if(visited[itr] == true){
                lowTime[src] = min(lowTime[src], discovery_time[itr]);
            }
        }
        if(parent == -1 && children > 1){
            articulate[src] = true;
        }
     }

   void articulation_point(){
    vector<int> discovery_time(v);
    vector<int> lowTime(v);
    vector<bool> visited(v, false);
    vector<bool> articulate(v, false);
    int time =0;

    for(int i =1; i< v; i++){
        if(visited[i] == false){
            dfs(i, time, -1, discovery_time, lowTime, visited, articulate);
        }
    }
    
    cout << "articulate points are : ";
    for(int i =0; i< v; i++){
        if (articulate[i] == true){
            cout << i << " ";
        }
    }
    cout << endl;
   }
};

int main() {
    Graph graph(4);
    graph.addedge(1,3);
    graph.addedge(1,2);
    graph.addedge(2,3);

    graph.articulation_point();

    return 0;
}

/*
Articulation Point Explanation for our graph:

Graph structure:
        0
      / | \
     1--2  3--4

- An articulation point (cut vertex) is a vertex that, if removed, increases
  the number of connected components in the graph.
- In this graph:
    - Removing 0 disconnects {1,2} from {3,4} → 0 is an articulation point.
    - Removing 3 disconnects {0,1,2} from {4} → 3 is an articulation point.
- Approach:
    - We do a DFS keeping track of discovery time (first visit) and low time 
      (earliest reachable ancestor).
    - If for a child `v`, lowTime[v] >= discovery[u], then `u` is an articulation point.
    - Special case: if the root has more than 1 DFS child, it is also an articulation point.
*/
