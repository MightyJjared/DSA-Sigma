// Hard
// GFG: Alien Dictionary
// Link: https://www.geeksforgeeks.org/problems/alien-dictionary/1
//
// Approach: Graph + Topological Sort (Kahn's Algorithm)
//
// Steps:
// 1. Store all unique characters from the given words in a set.
// 2. Compare every pair of adjacent words to find the first position
//    where their characters differ. This gives an ordering rule:
//    word1[j] must come before word2[j], so add a directed edge.
// 3. If the first word is longer than the second and the second is
//    a prefix of the first, the ordering is invalid. Return "".
// 4. Calculate the indegree of every character by counting its incoming
//    edges. Characters with indegree 0 have no prerequisites.
// 5. Push only characters present in the input and having indegree 0
//    into the queue.
// 6. Apply Kahn's algorithm: remove a character, add it to the answer,
//    decrease the indegree of its neighbours, and push any neighbour
//    whose indegree becomes 0.
// 7. If the answer contains all unique characters, return it.
//    Otherwise, a cycle exists, so return "".
//
// Time Complexity: O(N + K + E)
// N = total number of characters in all words
// K = 26 (English lowercase alphabet)
// E = number of directed edges in the graph
//
// Space Complexity: O(K + E)
// For the adjacency list, indegree array, queue, set, and answer.

class Solution {
  public:
    void toposort(int size, string &ans, vector<int> adj[], unordered_set<char> &s){

        vector<int> indegree(size, 0);

        // Count incoming edges for every character.
        for(int i =0; i < size; i++){
            for(auto itr: adj[i]){
                indegree[itr]++;
            }
        }

        queue<int> q;

        // Start with characters that have no prerequisites.
        // Ignore characters that do not appear in the words.
        for(int i =0; i < size; i++){
            char c = i + 'a';
            if(s.count(c)){
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }

        // Process characters in topological order.
        while(q.size() > 0){
            int node = q.front();
            q.pop();

            // Add the current character to the answer.
            ans = ans + char(node + 'a');

            // Remove the current character's outgoing edges.
            // A neighbour becomes ready when its indegree reaches 0.
            for(auto itr : adj[node]){
                indegree[itr]--;
                if(indegree[itr] == 0){
                    q.push(itr);
                }
            }
        }
    }

    string findOrder(vector<string> &words) {

        unordered_set<char> s;

        // Step 1: Collect all unique characters used in the words.
        int size = words.size();

        for(int i =0; i < size; i++){
            string str = words[i];
            for(int j =0; j < str.size(); j++){
                s.insert(str[j]);
            }
        }

        // Total number of distinct characters in the alien language.
        int letters = s.size();

        string ans = "";

        // adj[u] contains all characters that must come after u.
        vector<int> adj[26];

        // Step 2: Compare each pair of adjacent words.
        for(int i =0; i < size - 1; i++){
            int count = 0;
            string word1 = words[i];
            string word2 = words[i+1];

            int mini = min(word1.size(), word2.size());

            for(int j = 0; j < mini; j++){

                // The first different characters determine their order.
                if(word1[j] != word2[j]){
                    adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                    break;
                }
                else if(word1[j] == word2[j]){
                    count++;

                    // Step 3: A longer word cannot come before its prefix.
                    if(count == mini && word1.size() > word2.size()){
                        return "";
                    }
                }
            }
        }

        // Step 4: Find a valid character ordering using Kahn's algorithm.
        toposort(26, ans, adj, s);

        string empty = "";

        // Step 5: If some characters are missing, a cycle exists.
        if(ans.size() == letters){
            return ans;
        }
        else{
            return empty;
        }
    }
};