#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;



class Graph{/*
Question:
Check whether a given graph is Bipartite or not.
A graph is Bipartite if we can divide its vertices into 2 groups such that
no two adjacent vertices belong to the same group.

Example Graph (used in main):
     0
    / \
   1   2
    \ /
     3

Approach:
We assign colours (0 and 1) to nodes using BFS:
- Start with any unvisited node, give it colour 0.
- Its neighbours must have the opposite colour (1).
- Then their neighbours get 0, and so on.
- If we ever find two adjacent nodes with the same colour → graph is not bipartite.

Note:
We use `colour[itr] = !colour[current]` to flip the colour:
    If colour[current] = 0 → neighbour gets 1
    If colour[current] = 1 → neighbour gets 0
Thus `!` acts like a toggle between 0 and 1.
*/

/*
Important Theory – 3 Ways to Know if Graph is Bipartite:

1. If the graph is Acyclic (no cycles):
   → Always Bipartite.
   Example (tree):
       0
      / \
     1   2
   Groups: {0,2}, {1}

2. If the graph has cycles:
   - If all cycles are of Even length → Bipartite.
     Example (square cycle):
       0 -- 1
       |    |
       3 -- 2
     Cycle length = 4 (even) → Bipartite.

3. If the graph has an Odd cycle:
   → Not Bipartite.
   Example (triangle):
       0
      / \
     1---2
     Cycle length = 3 (odd) → Not Bipartite.
*/

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

    bool helper(int start,vector<bool> &visited, vector<int> &colour){
        queue<int> q;
        q.push(start);
        visited[start] = true;
        colour[start] = 0;

        while(q.size() > 0){
            int current = q.front();
            q.pop();


            list<int> neighbour = l[current];
            for(auto itr : neighbour){
                if(visited[itr] == false){
                visited[itr] = true;
                colour[itr] = !colour[current];
                q.push(itr);
               }
               else{
                if(colour[itr] == colour[current]){
                    return false;
                }
               }
            }
        }
        return true;
    }
    bool bi_partite(){
        vector<bool> visited(v, false);
        vector<int> colour(v, -1);

        for (int i=0; i <v; i++){
            if(visited[i] == false){
            if(helper(i,visited, colour) == false){
                return false;
            }
        }
        }
        return true;
    } 
};

int main(){
    Graph graph(4);

    graph.addedge(0,1);
    graph.addedge(0,2);
    graph.addedge(1,3);
    graph.addedge(2,3);

    cout << graph.bi_partite();
    cout << endl;

    return 0;
}