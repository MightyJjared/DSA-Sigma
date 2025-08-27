#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

/*
   Question:
   Given a string `str` and a dictionary of words, check if `str` can be segmented into 
   one or more dictionary words. This is known as the "Word Break Problem".

   Approach:
   1. Build a Trie from all dictionary words for efficient prefix search.
   2. Use recursion (helper function) to check all possible prefix splits of the input string:
      - Take every prefix of the string.
      - If the prefix exists in the Trie (a valid dictionary word), 
        recursively check if the remaining suffix can also be segmented.
   3. If any segmentation path leads to full coverage of the string, return true.
   4. Otherwise, return false.

   Time Complexity (worst case):
   - Insertion in Trie: O(N * L), where N = number of words, L = average length of each word.
   - Word Break (helper): Exponential in worst case due to recursion, 
     but efficient for practical cases because Trie reduces lookup cost to O(L) per word.
*/

/*
QUESTION:
Word Break Problem – Given a string and a dictionary of words, determine if the string can be segmented 
into a sequence of one or more dictionary words.

APPROACH:
We use a Trie to store all dictionary words for fast prefix searching. Then we recursively try to split 
the string into two parts:
    - `first` = a prefix (from start to some index i)
    - `second` = the remaining substring
If `first` is present in the Trie and `helper(second)` is true, we return true. 
The recursion continues until we reach an empty string, which is the base case → return true.

FLOW OF EXECUTION (for str = "ilikesamsung", words = {"i","like","sam","samsung","any","thee"}):
1. helper("ilikesamsung")
   - first = "i" ✅ found in Trie → call helper("likesamsung")
   - other prefixes ("il", "ili", ...) fail.

2. helper("likesamsung")
   - first = "like" ✅ found in Trie → call helper("samsung")
   - other prefixes ("l", "li", "lik") fail.

3. helper("samsung")
   - first = "sam" ✅ but helper("sung") ❌ fails
   - first = "samsung" ✅ → call helper("")

4. helper("") 
   - base case reached → return true.

Thus recursion path is:
"i" → "like" → "samsung" → "" ✅

FINAL RESULT: helper("ilikesamsung") returns true, so word_break("ilikesamsung") = true.
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
};

bool helper(string str, Trie &trie){
    if(str.size() == 0){
        return true;
    }

    for(int i =0; i< str.size(); i++){

        string first = str.substr(0, i+1);
        string second = str.substr(i+1);

        if(trie.search(first) == true && helper(second, trie) == true){
            return true;
        }
    }
    return false;
}

bool word_break(string str, vector<string> words){
    Trie trie;
    for(int i =0; i< words.size(); i++){
        trie.insert(words[i]);
    }

    if(helper(str, trie) == true){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    vector<string> words = {"i", "like", "sam", "samsung", "any", "thee"};
    string str1 = "ilikesamsung"; // true
    string str2 = "ilikesung";    // false
    string str3 = "ilikesam";     // true

    cout << word_break(str1, words) << endl;
    return 0;
}