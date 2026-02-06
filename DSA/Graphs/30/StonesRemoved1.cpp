#include <iostream>
#include <vector>
using namespace std;

/*
LeetCode Reference:
947. Most Stones Removed with Same Row or Column
https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

----------------------------------------------------
Approach (Stone-to-Stone DSU - Brute-force Union):

1. Treat each stone as a node.
2. Two stones belong to the same component if:
   - They share the same row, OR
   - They share the same column.
3. For every stone i, scan all stones j:
   - If stones[i] and stones[j] share row or column,
     union them in DSU.
4. After building DSU:
   - Each connected component must keep at least one stone.
   - All other stones in that component can be removed.
5. Final answer = total stones − number of connected components.

----------------------------------------------------
Time Complexity:
- For each stone, we scan all stones: O(n²)
- Each DSU operation is amortized O(α(n))
Overall: O(n² · α(n))

Space Complexity:
- DSU arrays: O(n)
Overall: O(n)
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
    void helper(int row, int column, int node,
                vector<vector<int>>& stones,
                DisjointSet &ds){
        int n = stones.size();
        for (int i = 0; i < n; i++) {
            int currentrow  = stones[i][0];
            int currentcolumn = stones[i][1];
            int currentnode = i;

            if(currentrow == row){
                ds.unionBySize(node, currentnode);
            }
            if(currentcolumn == column){
                ds.unionBySize(node, currentnode);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSet ds(n);

        for (int i = 0; i < n; i++) {
            int u = stones[i][0];
            int v = stones[i][1];
            helper(u, v, i, stones, ds);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(ds.parent[i] != i){
                ans++;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;

    vector<vector<int>> stones = {
        {0,0}, {0,1}, {1,0},
        {1,2}, {2,1}, {2,2}
    };

    cout << sol.removeStones(stones) << endl;
    return 0;
}
