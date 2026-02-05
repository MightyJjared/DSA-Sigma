#include <bits/stdc++.h>
using namespace std;

/*
GeeksforGeeks Reference:
Problem Name: Number of Islands II (Dynamic Islands)
Link: https://www.geeksforgeeks.org/problems/number-of-islands-ii/1

Approach:
Disjoint Set Union (Union-Find) with path compression and union by rank.

Time Complexity:
O(K * α(N*M))  where K = number of operators
α is inverse Ackermann function (almost constant)

Space Complexity:
O(N*M) for DSU parent, rank and visited array
*/

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unionByRank(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if(pa == pb) return;

        if(rank[pa] == rank[pb]) {
            parent[pb] = pa;
            rank[pa]++;
        }
        else if(rank[pa] > rank[pb]) {
            parent[pb] = pa;
        }
        else {
            parent[pa] = pb;
        }
    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n * m);
        
        // Part 1 Initialization
        vector<bool> visited(n*m, false);
        int count = 0;
        int r[] = {-1,0,0,1};
        int c[] = {0,-1,1,0};
        vector<int> ans;
        
        // part 2 iterating on operator
        for(auto itr : operators){
            int row = itr[0];
            int col = itr[1];
            
            int node = (row * m) + col;
            
            if(visited[node] == false){
                visited[node] = true;
                count++;
                
                // Part 3 Checking neighbours on 4 sides
                for(int i =0; i < 4; i++){
                    int newrow = row + r[i];
                    int newcol = col + c[i];
                    
                    if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m){
                        int newnode = (newrow * m) + newcol;
                        
                        if(visited[newnode] == true){
                            if(ds.find(newnode) != ds.find(node)){
                                count--;
                                ds.unionByRank(newnode, node);
                            }
                            else{
                                continue;
                            }
                        }
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};

int main() {
    // Hard-coded test case (GFG style example)
    int n = 4, m = 5;

    vector<vector<int>> operators = {
        {1, 1},
        {0, 1},
        {3, 3},
        {3, 4}
    };

    Solution obj;
    vector<int> result = obj.numOfIslands(n, m, operators);

    for(int x : result){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
