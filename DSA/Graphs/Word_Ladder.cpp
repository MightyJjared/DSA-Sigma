// LeetCode Problem: 127. Word Ladder
// Approach: 
// - We perform a BFS starting from beginWord. 
// - Each step, we try changing every character of the current word 
//   into all possible letters ('a' to 'z').
// - If the new word exists in the dictionary (unordered_set), we 
//   push it into the queue with step+1 and erase it from the set 
//   (to avoid revisiting).
// - BFS guarantees the shortest path, so when we reach endWord, 
//   the corresponding step count is our answer.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bfs(unordered_set<string> &s, string beginWord, string endWord) {
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));

        while (!q.empty()) {
            pair<string, int> p = q.front(); // pair = (word, count)
            q.pop();

            if (p.first == endWord) {
                return p.second;
            }

            for (int i = 0; i < p.first.size(); i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c != p.first[i]) {
                        string newword = p.first;
                        newword[i] = c;
                        if (s.find(newword) != s.end()) {
                            q.push(make_pair(newword, p.second + 1));
                            s.erase(newword);
                        }
                    }
                }
            }
        }
        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        for (auto itr : wordList) {
            s.insert(itr);
        }
        return bfs(s, beginWord, endWord);
    }
};

int main() {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    int result = sol.ladderLength(beginWord, endWord, wordList);
    cout << "Ladder Length: " << result << endl;

    return 0;
}
