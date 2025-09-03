#include <iostream>
#include <vector>
#include <list>
using namespace std;

// this is for undirected and unweighted graph
/*
Graph structure (Undirected):

    0
    |
    1
   / \
  2---3
  |
  4

Edges:
0 -- 1
1 -- 2
1 -- 3
2 -- 3
2 -- 4
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
};

int main(){
    Graph graph(5);

    graph.addedge(0,1);
    graph.addedge(1,2);
    graph.addedge(1,0);
    graph.addedge(2,3);
    graph.addedge(2,4);

    graph.print();

    return 0;
}