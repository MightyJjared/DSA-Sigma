#include <iostream>
#include <vector>
using namespace std;

/*
LeetCode 685: Redundant Connection II
-------------------------------------
We are given a directed graph with n nodes and n edges.
Originally, the graph was a rooted tree (n nodes, n-1 edges).
But one extra edge was added, creating one of these problems:
1. A node has two parents.
2. A cycle is formed.
We must remove one edge to make the graph a valid rooted tree again.
*/

/*
approach - here because it is directed graph so by adding one extra edge we are having 3 cases
1 case - a cycle is formed but no node has 2 parent
2 case - no cycle is formed but a node has 2 parents whereas every node in a tree should have 1 parent except root node
3 case = a cycle is formed as well as a node has 2 parents
to solve this 3 cases first we will do a for loop and check if the graph has two parents if it does then we capture
those two parents in vector candidate_b and candidate_a
then we will reset the parent vector with themselves ie for arr[4] = 4
then we will again traverse using for loop and check for the 3 cases
it is a bit hard but if u want to understand it see youtuber CodenCode
*/

class Solution {
public:
    int find(int x, vector<int> &parent){
        if(parent[x] == x){
            return x;
        }
        parent[x] = find(parent[x], parent);
        return parent[x];
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0);

        vector<int> candidate_b;
        vector<int> candidate_a;

        for(int i =0; i< n; i++){
            int a = edges[i][0];
            int b = edges[i][1];

            if(parent[b] == 0){
                parent[b] = a;
            }
            else{
                candidate_b.push_back(a);
                candidate_b.push_back(b);

                candidate_a.push_back(parent[b]);
                candidate_a.push_back(b);
            }
        }
        for(int i =1; i<=n; i++){
            parent[i] = i;
        }

        for(auto e : edges){
            if(e == candidate_b){
                continue;
            }

            int a = find(e[0], parent);
            int b = find(e[1], parent);

            if(a == b){
                if(candidate_a.size() > 0){
                    return candidate_a;
                }
                else{
                    return e;
                }
            }
            else if (a != b){
                parent[b] = a;
            }
        }
        return candidate_b;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {{1,2},{2,3},{3,4},{4,1},{1,5}};
    vector<int> redundant = sol.findRedundantDirectedConnection(edges);

    cout << "Redundant edge: [" << redundant[0] << ", " << redundant[1] << "]" << endl;
    return 0;
}
