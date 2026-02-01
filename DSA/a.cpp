#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class disjoint{
    vector<int> rank;
    vector<int> parent;
    int n;
    
    public:
    disjoint(int n){
        this -> n = n;
        for(int i =0; i <= n; i++){
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int findParent(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }

    void UnionByRank(int a, int b){
        int Par_a = findParent(a);
        int Par_b = findParent(b);

        if(Par_a == Par_b){
            return;
        }
        if(rank[Par_a] == rank[Par_b]){
            parent[Par_b] = Par_a;
            rank[Par_a]++;
        }
        else if(rank[Par_a] > rank[Par_b]){
            parent[Par_b] = Par_a;
        }
        else if(rank[Par_b] > rank[Par_a]){
            parent[Par_a] = Par_b;
        }
    }
};

int main() {
    disjoint ds(5);

    ds.UnionByRank(1,2);
    ds.UnionByRank(1,0);
    ds.UnionByRank(3,4);
    ds.UnionByRank(2,3);
    if(ds.findParent(4) == ds.findParent(5)){
        cout << "Same parent" << endl;
    }
    else{
        cout << "Different Parents" << endl;
    }
    ds.UnionByRank(5,4);
    if(ds.findParent(4) == ds.findParent(5)){
        cout << "Same parent" << endl;
    }
    else{
        cout << "Different Parents" << endl;
    }
    return 0;
}
