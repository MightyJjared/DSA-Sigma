#include <bits/stdc++.h>
using namespace std;

/*
LeetCode Reference:
Problem 721: Accounts Merge
https://leetcode.com/problems/accounts-merge/

Approach:
Disjoint Set Union (Union-Find)

Time Complexity:
O(N * α(N) + E log E)
N = number of accounts
E = total emails

Space Complexity:
O(N + E)
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string, int> m;

        for(int i =0; i < n; i++){
            int k = accounts[i].size();
            for(int j = 1; j < k; j++){
                string email = accounts[i][j];
                if(m.find(email) == m.end()){
                    m[email] = i;
                }
                else{
                    ds.unionByRank(i, m[email]);
                }
            }
        }
        
        vector<vector<string>> mergeEmail(n);
        vector<vector<string>> ans;
        for(auto itr : m){
            string email = itr.first;
            int index = ds.find(itr.second);

            mergeEmail[index].push_back(email);
        }

        for(int i = 0; i < n; i++){
            if(mergeEmail[i].empty()) continue;

            sort(mergeEmail[i].begin(), mergeEmail[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for(auto &email : mergeEmail[i]){
                temp.push_back(email);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};

int main() {
    // Hard-coded test case (LeetCode example)
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}
    };

    Solution obj;
    vector<vector<string>> result = obj.accountsMerge(accounts);

    for(auto &acc : result){
        for(auto &s : acc){
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}

