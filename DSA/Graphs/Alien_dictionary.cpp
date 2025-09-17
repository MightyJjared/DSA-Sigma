#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// here ware using list to store grpah connections
// see striver for explanation
/*
Alien Dictionary (LeetCode 269 / GFG version)
---------------------------------------------
Problem:
Given N words sorted lexicographically according to an alien language 
that has K distinct characters, determine the order of characters 
in the alien dictionary.

Input:
- dict[]: array of N words
- N: number of words
- K: number of unique characters in alien alphabet

Output:
- String representing the order of characters

Approach Outline:
-----------------
1. Build graph:
   - Compare adjacent words in dict[].
   - Find the first different character -> directed edge (u -> v).
   - Graph will have K nodes (each character).

2. Perform Topological Sort:
   - Use Kahn’s Algorithm (BFS) or DFS.
   - Ensure all K characters are included.

3. Return the order as a string.

TODO:
-----
- Implement graph building using dict[].
- Handle invalid case (e.g., prefix issue).
- Perform topo sort.

Note:
-----
- We are using `list<int> l[K];` as the adjacency list.
  This means `l` is an array of K linked lists,
  where each `l[i]` contains all characters that come after character i.
  It is a graph representation where nodes are characters
  and edges represent precedence rules.
*/

class Solution {
public:
    void topological_helper(int v, stack<int> &s, vector<int> &visited, list<int> l[]){
        visited[v] = true;

        for(auto itr : l[v]){
            if(visited[itr] == false){
                topological_helper(itr, s, visited, l);
            }
        }
        s.push(v);
    }

    stack<int> topological(int K, list<int> l[]){
        stack<int> s;
        vector<int> visited(K, false);
        for(int i =0; i < K; i++){
            if(visited[i] == false){
                topological_helper(i, s, visited, l);
            }
        }
        return s;
    }

    string alienOrder(string dict[], int n, int K) {
        list<int> l[K];
        string ans;
        for(int i =0; i< n-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int length = min(s1.size(), s2.size());
            for(int i =0; i < length; i++){
                if(s1[i] != s2[i]){
                    l[s1[i] - 'a'].push_back(s2[i] - 'a');
                    break;
                }
            }
        }
        stack<int> s = topological(K, l);
        while(s.size() > 0){
            char a = char(s.top() + 'a');
            s.pop();
            ans.push_back(a);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    int N = 5, K = 4;
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};

    string order = sol.alienOrder(dict, N, K);

    cout << "Alien Dictionary Order: " << order << endl;

    return 0;
}
