#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <queue>
using namespace std;
// this algorithms uses directed and weighted , can also use undirected and weighted but weighted is
// neccessary and the weight should not be negative
// in this we are assuming the weight from each vertex as distance using this algorithm we are calculating 
// the shorted distance for each vertex from src in this case 0.
// to implement this we are using edge list and not adjacency list.
// we are using bsf to implement, time complexity = O(V+E * log V)

// Time Complexity:
// Each extract-min from the priority queue takes O(log V) and happens V times → V log V.
// Each edge relaxation may push into the queue, costing O(log V) and happens E times → E log V.
// Total = V log V + E log V = (V + E) log V.
// Since E ≥ V for connected graphs, it simplifies to O(E log V).
// Valid for graphs with non-negative edge weights.

// Space Complexity:
// dist[] + visited/parent arrays take O(V).
// adjacency list takes O(V + E).
// priority queue holds up to O(V) elements.
// Total space = O(V + E).

/*
Important note - here we use priority queue instead of normal queue because we can use normal queue also but it
will just waster our time in prioirty queue since we are using min heap here the level which has the smallest
distance will be picked which will help us pick the shortest distance
*/

class edge{
    public:
    int v;
    int wt;

    edge(int v, int wt){
        this->v = v;
        this->wt = wt;
    }
};

void dijkstra(int src, int v,vector<vector<edge>> graph){

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // here the priority queue is for min heap and type is pair
    // the pair contains (dist[v], v)
    // since we dinst add a comparator therefore it is based upon first value ie dist[v]

    vector<int> dist(v, INT8_MAX);

    dist[src] = 0;
    pq.push(make_pair(0,src));

    while(pq.size() > 0){
        int u = pq.top().second;
        pq.pop();

        vector<edge> edges = graph[u]; // looping on neighbours of u
        for(auto itr : edges){ // itr.v,  itr.wt
            if(dist[itr.v] > dist[u] + itr.wt){
                dist[itr.v] = dist[u] + itr.wt;
                pq.push(make_pair(dist[itr.v], itr.v));
            }
        }
    }

    for(auto itr : dist){
        cout << itr << " ";
    }
    cout << endl;

}

int main(){
    int v = 6;
    vector<vector<edge>> graph(v);

    graph[0].push_back(edge(1,2));
    graph[0].push_back(edge(2,4));

    graph[1].push_back(edge(2,1));
    graph[1].push_back(edge(3,7));

    graph[2].push_back(edge(4,3));

    graph[3].push_back(edge(5,1));

    graph[4].push_back(edge(3,2));
    graph[4].push_back(edge(2,5));

    dijkstra(0, v, graph);

    return 0;
}