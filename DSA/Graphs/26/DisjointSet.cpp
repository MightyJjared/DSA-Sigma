#include <iostream>
#include <vector>
using namespace std;

// Disjoint Set Union (Union-Find)
// Time Complexity (amortized):
//   find() and unionByRank() → O(α(n)) ≈ constant time in practice
// Space Complexity:
//   O(n) for parent[] and rank[]
// DSU with path compression + union by rank: ~O(1) time per operation (amortized)

/*
When to use Disjoint Set Union (DSU / Union-Find):

1. When the problem involves CONNECTED COMPONENTS.
2. When elements are dynamically connected (edges/nodes added over time).
3. When you need to answer queries like:
   - Are two nodes in the same component?
   - How many connected components exist after each operation?
4. When DFS/BFS would be too slow due to repeated queries or updates.
5. When the graph/grid is updated incrementally (dynamic connectivity problems).
6. When union and find operations are required frequently and efficiently.

Typical examples:
- Number of Islands II (Dynamic Islands)
- Number of Provinces / Provinces II
- Accounts Merge
- Kruskal’s Minimum Spanning Tree
- Connecting graph components with minimum operations

Why DSU:
- Almost O(1) per operation using path compression and union by rank
- Efficient for large inputs with many queries
*/

class DisjointSet{
    int n;
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    public:
    DisjointSet(int n){
        this -> n = n;
        for(int i =0; i<n; i++){
            parent.push_back(i);
            rank.push_back(0);
            size.push_back(1);
        }
    }

    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    
    void unionByRank(int A, int B){
        int parA = find(A);
        int parB = find(B);

        if(parA == parB) return;   // 🔑 missing guard

        if(rank[parA] == rank[parB]){
            parent[parB] = parA;
            rank[parA]++;
        }
        else if (rank[parA] > rank[parB]){
            parent[parB] = parA;
        }
        else{
            parent[parA] = parB;
        }
    }

    void unionBySize(int A, int B){
        int parA = find(A);
        int parB = find(B);

        if(parA == parB) return;   // 🔑 missing guard

        if(size[parA] == size[parB]){
            parent[parB] = parA;
            size[parA] += size[parB];
        }
        else if (size[parA] > size[parB]){
            parent[parB] = parA;
            size[parA] += size[parB];
        }
        else{
            parent[parA] = parB;
            size[parB] += size[parA];
        }
    }

    void getInfo(){
        for(int i =0; i<n; i++){
            cout << i << " : " << parent[i] << " , " << rank[i] << endl;
        }
    }
};

int main(){

    DisjointSet dj(6);
    dj.unionByRank(0,2);
    cout << dj.find(2) << endl;
    dj.unionByRank(1,3);
    dj.unionByRank(2,5);
    dj.unionByRank(0,3);
    cout << dj.find(2) << endl;
    dj.unionByRank(0,4);

    dj.getInfo();
    return 0;
}