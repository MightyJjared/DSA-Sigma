#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

/*
QUESTION:
We are given a list of words (like "apple", "app", "mango", "man", "woman") 
and we want to check whether a given prefix (like "app" or "moon") is present 
at the start of any word in the list.

APPROACH:
1. We use a Trie (prefix tree) data structure.
   - Each node contains a map of children and a boolean flag `end_of_word`.
   - Insert: for each word, we add characters into the Trie one by one.
   - Search: checks if a word fully exists in the Trie.
   - starts_with_helper: checks if a given prefix path exists in the Trie (it 
     doesn’t matter whether it’s a full word or not, just the starting path).

2. Steps in main flow:
   - We insert all words into the Trie.
   - For a given prefix:
       → Traverse character by character.
       → If at any point, the character does not exist, return false.
       → If all characters match, return true.
   - This means some word(s) begin with that prefix.

EXAMPLE EXECUTION:
Words = {"apple", "app", "mango", "man", "woman"}

Case 1: prefix = "app"
- Insert words into Trie.
- Check "a" → exists, "p" → exists, second "p" → exists. Done.
- Returns true (since "app" and "apple" start with "app").

Case 2: prefix = "moon"
- Check "m" → exists, but then "o" → does not exist in children of "m".
- Returns false.

Thus, the program prints 0 for "moon" and would print 1 for "app".
Time complexity = O(N*L) for building the Trie (N = words, L = average word length),
and O(P) for checking a prefix (P = length of prefix).
*/


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

    bool starts_with_helper(string prefix, Trie &tries){
        node* temp = root;
        if(prefix.size() == 0){
            return true;
        }
        for(int i =0 ; i <prefix.size(); i++){
            if(temp->children.count(prefix[i]) == 0){
                return false;
            }
            temp = temp-> children[prefix[i]];
        }
        return true;
    }
};

bool starts_with_prefix(vector<string> words, string prefix){
    Trie tries;
    for(int i =0; i< words.size(); i++){
        tries.insert(words[i]);
    }
    return tries.starts_with_helper(prefix, tries);
}

int main(){
    vector<string> words = {"apple", "app", "mango", "man", "woman"};
    string prefix1 = "app";
    string prefix2 = "moon";

    cout << starts_with_prefix(words, prefix2) << endl;

    return 0;
}