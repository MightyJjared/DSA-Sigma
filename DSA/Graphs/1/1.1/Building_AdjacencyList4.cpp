#include <iostream>
#include <vector>
#include <list>
using namespace std;

// this is for undirected weighted graph
// instead of using list<int> we are using list<pair<int,int>> where in pair we are storing the neighbour and weight.
/*
     (5)
  0 ------ 1
           / \
        (1)/   \(3)
         /       \
        2 -------- 3
        |    (1)
       (2)
        |
        4
*/

class Graph{
    int v;
    list<pair<int, int>>* l;

    public:
    Graph(int v){
        this->v = v;
        l = new list<pair<int,int>>[v];
    }

    void addedge(int u, int v, int w){
        l[u].push_back({v,w});
        l[v].push_back({u,w});
    }

    void print(){
        for(int i =0; i< v; i++){
    
            cout << i << " : ";
            for(auto itr : l[i]){
               cout << "(" << itr.first << "," << itr.second << ")";
            }
            cout << endl;
        }
    }
};

int main(){
    Graph graph(5);

    graph.addedge(0,1,5);
    graph.addedge(1,2,1);
    graph.addedge(1,3,3);
    graph.addedge(2,3,1);
    graph.addedge(2,4,2);

    graph.print();

    return 0;
}