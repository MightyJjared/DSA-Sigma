// LeetCode 126: Word Ladder II

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

// Here this is giving memory exceed in leetcode but will work absolutely fine in interview
// aslo this is extremeely ahrd so to understand the intiuition watch striver graph lecture 30
// now he gave a leetocde oriented solution in next lecture but he said dont try this in interview as
// it not intitutive , do this in interview

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // Initialization part
        vector<vector<string>> ans; // this is to store the final 2d vector of strign which we will return
        vector<string> UsedOnLevel; // this vectors only work is so that we can remove the words from the set when vec.size > level

        unordered_set<string> s;
        queue<vector<string>> q;    

        // 1 Part
        // Here we are initializing the values
        int level = 0;
        UsedOnLevel.push_back(beginWord);
        for(auto itr : wordList){
            s.insert(itr);
        }
        q.push(UsedOnLevel);

        // 2 Part
        // Here we are applying bfs
        while(q.size() > 0){
            vector<string> vec; // this is the vector with which we will insert vector string in queue and basically it is te main vector;
            vec =q.front();
            q.pop();

            //  1 part inside the while loop
            // here will check if vec.size is greater then level then will remove all thewords from set which are preset in usedlevel vector
            if(vec.size() > level){
                level++;
                for(auto itr : UsedOnLevel){
                    s.erase(itr);
                }
                UsedOnLevel.clear(); // just a slight optimization for time complexity, will work even without this
            }

            // 2 Part
            // Here we are checking the lest word of vec is our endword meaning we have found as sequence so will insert it in the ans vector
            string word = vec.back();
            if(word == endWord){
                if(ans.size() == 0){
                    ans.push_back(vec);
                }
                else if (ans[0].size() == vec.size()){
                    ans.push_back(vec);
                }
            }

            // 3 Part
            // Here we are checking all the available words which we change into using the lastword of our vector
            for(int i =0; i < word.size(); i++){
                for(char c = 'a'; c <= 'z'; c++){
                    if(c != word[i]){
                        string newWord = word;
                        newWord[i] = c;
                        if(s.find(newWord) != s.end()){ // we have found a match in set
                            vec.push_back(newWord);
                            q.push(vec);
                            UsedOnLevel.push_back(newWord);
                            vec.pop_back(); // here we are poping because for exampe lets say we have dog as the word now in the set the changing words can be bog as well as cog
                            // and we want both like vec = [dog, bog] as well as vec = [dog, cog] , Used on level will store both [bog, cog]                                  
                        }
                    }
                }
            }
        }
        return ans; 
    }
};

int main() {
    Solution sol;
    
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    vector<vector<string>> result = sol.findLadders(beginWord, endWord, wordList);

    for (auto &path : result) {
        for (auto &w : path) {
            cout << w << " ";
        }
        cout << endl;
    }

    return 0;
}
