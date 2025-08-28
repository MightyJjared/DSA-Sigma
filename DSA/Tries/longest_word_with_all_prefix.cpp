/*
Problem:
--------
Given a list of words, find the longest word that can be built **one character at a time**
such that **every prefix** of that word is also present in the list. If more than one
word qualifies with the same (maximum) length, return the **lexicographically smallest** one.

Example:
--------
words = {"banana", "a", "ap", "apple", "app", "apply", "appl"}
Valid buildable words (each prefix exists): "a", "ap", "app", "appl", "apple", "apply"
Longest length = 5 → candidates: "apple", "apply" → lexicographically smallest is "apple"
So answer = "apple".

High-level approach (what the code does):
-----------------------------------------
1. Build a Trie and mark nodes corresponding to complete words with `end_of_word = true`.
   - Insertion is O(L) per word where L is the word length.
2. Perform a DFS / backtracking from the root of the Trie, but **only** traverse into a child
   node if that child node corresponds to a complete word (`itr.second->end_of_word == true`).
   - This ensures at every step of the path, the prefix formed so far is itself a valid word.
   - In other words, we only follow character edges that extend a valid buildable word.
3. Maintain two strings:
   - `curr` — the current path / candidate word we are building while traversing.
   - `ans`  — the best answer found so far.
4. Update `ans` whenever:
   - `curr` is strictly longer than `ans`, OR
   - `curr` has the same length as `ans` but is lexicographically smaller.
   The code implements this with:
     if ((curr.size() == ans.size() && ans > curr) || (curr.size() > ans.size())) {
         ans = curr;
     }
   - `ans > curr` is a lexical comparison: it evaluates true when `ans` is lexicographically
     greater than `curr`, so `curr` is the smaller string and should replace `ans` in a tie.
   - This logic guarantees the lexicographical tie-break — even if a lexicographically larger
     candidate is discovered earlier, it will be replaced when a lexicographically smaller
     candidate of the same length is found later.

How the code enforces "every prefix is a word":
-----------------------------------------------
- The `helper` function iterates all children of the current node.
- It only **enters** a child if `itr.second->end_of_word == true`.
  That means the child letter completes a valid word at that depth; therefore, every prefix
  up to that point is a word in the dictionary. This is exactly the requirement.

Why backtracking and how it works:
---------------------------------
- When we add a character: `curr += itr.first;`
- Recurse: `helper(itr.second, ans, curr);`
- Then undo the addition (backtrack) with:
  `curr = curr.substr(0, curr.size()-1);`
- `curr` is passed by value into `helper`, so each recursion gets its own `curr` copy.
  The explicit substr backtrack keeps the current stack frame's `curr` consistent for other children.

Complexity:
-----------
- Let N = number of words, L_avg = average word length, T = total characters across all words.
- Building the Trie: O(T) time and O(T) space (every character may create a node).
- DFS/backtracking visits only nodes reachable via full-word prefixes; worst-case it still
  visits O(T) nodes, so the traversal is O(T).
- Overall: O(T) time, O(T) space.

Edge cases & notes:
-------------------
- If no single-character words exist (e.g., no "a" for words starting with 'a'), then longer
  words down that branch won't be considered because the code requires each prefix to exist.
- If multiple words have same length and same lexicographical value, the code naturally
  keeps one (they are identical).
- `unordered_map` iteration order is unspecified, but the lexical tie-break is handled by the
  `ans > curr` string comparison — therefore final result is deterministic (lexicographically
  smallest among equal-length candidates) regardless of traversal order.
- Small optimization: passing `curr` by reference and using `curr.push_back()` / `pop_back()`
  would avoid repeated allocations from `substr`, but the logic would remain the same.

Summary of the key tie-breaking condition in the code:
-----------------------------------------------------
`if ((curr.size() == ans.size() && ans > curr) || (curr.size() > ans.size())) ans = curr;`

- First part `(curr.size() == ans.size() && ans > curr)` ensures that when lengths are equal,
  we pick the lexicographically **smaller** string.
- Second part `(curr.size() > ans.size())` ensures we prefer strictly longer words.
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class node{
    public:
    unordered_map<char, node*> children;
    bool end_of_word;

    node(){
        end_of_word = false;
    }
};

class Trie{
    node* root;
    public:
    Trie(){
        root = new node();
    }

    void insert(string key){ // O(L) where L is lenght of the word
        node* temp = root;

        for(int i =0; i< key.size(); i++){

            if(temp->children.count(key[i]) == 0){ // doesnt exist
                temp->children[key[i]] = new node();
            }
            temp = temp -> children[key[i]];
        }
        temp->end_of_word = true;
    }

    bool search(string key){
        node* temp = root;

        for(int i =0; i< key.size(); i++){
            if(temp->children.count(key[i]) == 0){ // doesnt exist
                return false;
            }
            temp = temp->children[key[i]]; 
        }
        if(temp->end_of_word == true){
            return true;
        }
        else{
            return false;
        }
    }

    void helper(node* temp, string &ans, string curr){
        for(pair<char, node*> itr : temp->children){
            if(itr.second->end_of_word == true){
                curr += itr.first;

                if( (curr.size() == ans.size() && ans > curr) ||  (curr.size() > ans.size()) ){
                    ans = curr;
                }

                helper(itr.second, ans, curr);
                curr = curr.substr(0 , curr.size()-1); // backtracking removing one letter at a time;

            }
        }
    }

    string longestStringWithEOW(){
        string ans = "";
        string curr = "";

        node* temp = root;

        helper(root, ans, curr);
        return ans;
    }
};

string longest_word(vector<string> words){
    Trie trie;
    for(int i =0 ; i< words.size(); i++){
        trie.insert(words[i]);
    }
    return trie.longestStringWithEOW();
}

int main(){
    vector<string> words = {"banana", "a", "ap", "apple", "app", "apply", "appl"};
    
    cout << longest_word(words);
    cout << endl;
    return 0;
}
