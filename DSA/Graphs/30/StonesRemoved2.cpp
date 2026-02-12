#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
LeetCode Reference:
947. Most Stones Removed with Same Row or Column
https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

Approach:
- Treat each row and each column as a node in Disjoint Set (Union-Find).
- Offset column indices by total number of rows to avoid collision.
- Union the row node and column node for every stone.
- Count number of connected components that actually appear.
- Maximum stones removable = total stones - number of connected components.

Time Complexity:
- O(N * α(N)) where α is inverse Ackermann function (almost constant)

Space Complexity:
- O(R + C) for DSU arrays, where R = max rows, C = max columns
*/

class DisjointSet{
public:
    int n;
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    DisjointSet(int n){
        this->n = n;
        for(int i = 0; i < n; i++){
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

        if(parA == parB) return;

        if(rank[parA] == rank[parB]){
            parent[parB] = parA;
            rank[parA]++;
        }
        else if(rank[parA] > rank[parB]){
            parent[parB] = parA;
        }
        else{
            parent[parA] = parB;
        }
    }

    void unionBySize(int A, int B){
        int parA = find(A);
        int parB = find(B);

        if(parA == parB) return;

        if(size[parA] == size[parB]){
            parent[parB] = parA;
            size[parA] += size[parB];
        }
        else if(size[parA] > size[parB]){
            parent[parB] = parA;
            size[parA] += size[parB];
        }
        else{
            parent[parA] = parB;
            size[parB] += size[parA];
        }
    }

    void getInfo(){
        for(int i = 0; i < n; i++){
            cout << i << " : " << parent[i] << " , " << rank[i] << endl;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        int totalrows = 0;
        int totalcolumns = 0;
        for(auto itr : stones){
            int row = itr[0];
            int col = itr[1];
            totalrows = max(totalrows, row);
            totalcolumns = max(totalcolumns, col);
        }
        
        totalrows += 1;
        totalcolumns += 1;
        int size = totalrows + totalcolumns;
        DisjointSet ds(size);

        unordered_set<int> s;
        for(auto itr : stones){
            int row = itr[0];
            int col = itr[1];

            col = col + totalrows;

            ds.unionBySize(row, col);
            s.insert(row);
            s.insert(col);
        }
        
        int count = 0;
        for(auto itr : s){
            if(ds.find(itr) == itr){
                count++;
            }
        }
        int ans = n - count;
        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> stones = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 2},
        {2, 1},
        {2, 2}
    };

    cout << sol.removeStones(stones) << endl;
    return 0;
}
