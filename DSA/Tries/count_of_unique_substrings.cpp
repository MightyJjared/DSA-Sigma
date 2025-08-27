#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

/*
Here the logic is to get all unique substring of a string we have to take out all the suffixes of the string
then if we take out all uniques prefixes of that suffixes we will get all unique substribgs of the string
So what we are doin is taking out suffixes of the word and then building a trie with that suffixes and so basically
since trie dont store same letters so all the nodes are unique subarrays so basically the total number of nodes in the 
trie is our count of unique subarrays and we will also add an empty subarrray as it also possible so instead of 
adding that empty subarray since we have main root as empty so we will count that as our mpty subarray.
*/

/*
❓ Question:
We want to count the number of unique substrings of a given string.

⚡ Approach:
- A substring is any continuous part of a string.
- To generate all substrings, one way is:
    1. Take all suffixes of the string.
    2. For each suffix, take all of its prefixes.
- But instead of explicitly generating them, we use a **Trie** (prefix tree).
- Why? Because a Trie automatically avoids duplicates. Each path in the Trie represents a unique substring.

👩‍💻 How we do it:
- Insert all suffixes of the string into the Trie.
- Every node in the Trie corresponds to a unique prefix of some suffix, i.e., a unique substring.
- So, the total number of nodes in the Trie = total number of unique substrings.
- We also consider the **empty substring ""** (which always exists).  
  Our Trie root node itself represents this empty substring.

🧮 Example:
String = "ababa"

All unique substrings are:
""
"a"
"b"
"ab"
"ba"
"aba"
"bab"
"abab"
"baba"
"ababa"

Total = 10

✔ Our code works because:
- We insert all suffixes into the Trie.
- Trie nodes represent unique substrings.
- `count()` function counts all nodes (including root for ""), giving the correct answer.
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

    int count_helper(node* root){
        node* temp = root;
        int ans = 0;

        for(auto itr: root->children){
            ans += count_helper(itr.second);
        }
        return ans+1;
    }

    int count(){
        return count_helper(root);
    }
};

void substring(string str){
    Trie trie;

    for(int i =0; i< str.size(); i++){
        string str1 = str.substr(i);
        trie.insert(str1);
    }

    cout << trie.count() << endl;
}

int main(){
    string str = "ababa";
    substring(str);
    return 0;
}