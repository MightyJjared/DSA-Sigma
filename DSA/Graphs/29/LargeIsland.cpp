#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
LeetCode Reference:
827. Making A Large Island
https://leetcode.com/problems/making-a-large-island/

----------------------------------------------------
Approach (Using Disjoint Set Union - DSU):

1. Treat each cell (i, j) as a node with id = i*n + j.
2. First pass:
   - For every cell with value 1, union it with its 4-directional
     neighboring cells that also have value 1.
   - This builds connected components (islands).
3. Second pass:
   - For every cell with value 0, simulate flipping it to 1.
   - Collect unique parent components of its neighboring islands
     using an unordered_set to avoid double counting.
   - Sum their sizes + 1 (for the flipped cell).
4. Track the maximum possible island size.
5. Edge case:
   - If grid contains no 0s, return the size of the largest existing island.

----------------------------------------------------
Time Complexity:
- Building DSU: O(n^2 * α(n^2))
- Evaluating each 0-cell: O(n^2 * α(n^2))
Overall: O(n^2 * α(n)) ≈ O(n^2)

Space Complexity:
- DSU arrays: O(n^2)
- Temporary unordered_set: O(1) (at most 4 elements)
Overall: O(n^2)
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
    bool isValid(int row, int col, vector<vector<int>>& grid){
        int n = grid.size();
        if(row < n && row >= 0 && col < n && col >= 0 && grid[row][col] == 1){
            return true;
        }
        else{
            return false;
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        int r[] = {-1, 0, 0, 1};
        int c[] = {0, -1, 1, 0};

        // Step 1: Build DSU for existing islands
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int node = (n * i) + j;
                    for(int k = 0; k < 4; k++){
                        int newrow = i + r[k];
                        int newcol = j + c[k];

                        if(isValid(newrow, newcol, grid)){
                            int newnode = (newrow * n) + newcol;
                            ds.unionBySize(node, newnode);
                        }
                    }
                }
            }
        }

        int ans = -1e9;

        // Step 2: Try flipping each 0
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int count = 0;
                unordered_set<int> s;

                if(grid[i][j] == 0){
                    int node = (n * i) + j;
                    for(int k = 0; k < 4; k++){
                        int newrow = i + r[k];
                        int newcol = j + c[k];

                        if(isValid(newrow, newcol, grid)){
                            int newnode = (newrow * n) + newcol;
                            int parents = ds.find(newnode);

                            if(s.find(parents) == s.end()){
                                s.insert(parents);
                                count += ds.size[parents];
                            }
                        }
                    }
                    count += 1;
                    ans = max(ans, count);
                }
            }
        }

        // Step 3: All 1s edge case
        if(ans == -1e9){
            for(auto itr : ds.size){
                ans = max(ans, itr);
            }
        }

        return ans;
    }
};

int main(){
    Solution sol;

    vector<vector<int>> grid = {
        {1, 0},
        {0, 1}
    };

    cout << sol.largestIsland(grid) << endl;
    return 0;
}
