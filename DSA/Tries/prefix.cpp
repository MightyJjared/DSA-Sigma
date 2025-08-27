#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

// Note - here we are also changing the trie structure by adding frequence and modifyinf it in insert
/*
QUESTION
--------
Given a list of words, print the Shortest Unique Prefix (SUP) for each word—i.e., the shortest prefix
that uniquely identifies that word among all the given words.

EXAMPLE
-------
words = {"zebra", "dog", "dove", "deer"}
Output = "z, dog, dov, de,"
Explanation:
- "zebra" is unique at 'z'                     -> "z"
- "dog" shares 'd' and 'do' with "dove"/"deer" -> unique at "dog"
- "dove" shares 'd' and 'do' with "dog"        -> unique at "dov"
- "deer" shares 'd' with others                -> unique at "de"

CORE IDEA (Trie with frequency counts)
--------------------------------------
Build a Trie where every node stores:
1) children: map<char, node*> to next letters
2) end_of_word: marks the end of a complete word
3) frequency: how many words pass through this node (path count)

Algorithm:
1) INSERT each word into the Trie.
   - For each character c:
     • If child for c doesn’t exist, create it and set frequency = 1.
     • Else, increment that child’s frequency.
   - After last character, mark end_of_word = true.

2) To find a word’s SUP, walk its path from the root, appending characters to a growing 'prefix'.
   - At each step, if the child node’s frequency == 1, we’ve reached a point where only this word
     uses that node/path => current 'prefix' is the SUP. Return it immediately.
   - If we never see frequency == 1, return the full word (no shorter unique prefix).

WHY THIS WORKS
--------------
The frequency on a node equals the number of words that share the path to that node. The first node
on the path of a word where frequency becomes 1 is the earliest position the word becomes unique.

LINE-BY-LINE WALKTHROUGH (high-level)
-------------------------------------
#include … using namespace std;     // Bring in standard containers and I/O.
class node {                        // A Trie node:
  unordered_map<char,node*> children; // edges labeled by characters
  bool end_of_word;                   // true if a word ends here
  int  frequency;                     // how many words pass through this node
  node(){ end_of_word = false; }      // frequency is set during insertion for children
};

class Trie {
  node* root;                       // root of the Trie
public:
  Trie(){ root = new node(); int frequency = -1; } // local 'frequency' is unused (harmless)
  void insert(string key){
    node* temp = root;
    for each character key[i]:
      if child for key[i] doesn’t exist:
        create child node; set its frequency = 1
      else:
        increment that child node’s frequency
      move temp to that child
    mark temp->end_of_word = true
  }
  bool search(string key){          // standard Trie lookup
    start at root; for each char:
      if missing child -> false
      else move to child
    return end_of_word at final node
  }
  string getprefix(string key){     // find SUP for 'key'
    prefix = ""
    temp = root
    for each char key[i]:
      prefix += key[i]
      if child(key[i])->frequency == 1: return prefix  // first unique point
      move temp to child(key[i])
    return prefix  // entire word (no earlier uniqueness)
  }
};

void prefix(vector<string> words){  // driver for building Trie and printing SUPs
  Trie trie;
  insert all words into trie
  print "Shortest unique prefix = "
  for each word:
    print trie.getprefix(word) + ", "
}

DRY RUN (with the given example)
--------------------------------
Insert "zebra":
  z(1) -> e(1) -> b(1) -> r(1) -> a(1)
Insert "dog":
  d(1) -> o(1) -> g(1)
Insert "dove":
  d becomes 2, o becomes 2, v(1) -> e(1)
Insert "deer":
  d becomes 3, e(1) -> e(1) -> r(1)

Now getprefix():
- "zebra": at 'z' frequency == 1 -> return "z"
- "dog":   'd'(3), 'o'(2), 'g'(1) -> return "dog"
- "dove":  'd'(3), 'o'(2), 'v'(1) -> return "dov"
- "deer":  'd'(3), 'e'(1)         -> return "de"

COMPLEXITY
----------
Let N be number of words and L be average length.
Build Trie:  O(N * L)
Query all SUPs: sum over words O(length(word)) -> O(N * L)
Space: O(N * L) nodes in worst case.

NOTES / EDGE CASES
------------------
- Duplicate words will raise frequencies along the entire path; such words may return the full word
  as SUP (since no node along the path is unique).
- Root frequency isn’t used; the code sets children frequencies when they’re first created, and
  increments on reuse, which is sufficient for SUP.
*/


class node{
    public:
    unordered_map<char, node*> children;
    bool end_of_word;
    int frequency;

    node(){
        end_of_word = false;
    }
};

class Trie{
    node* root;
    public:
    Trie(){
        root = new node();
        int frequency = -1;
    }

    void insert(string key){ // O(L) where L is lenght of the word
        node* temp = root;

        for(int i =0; i< key.size(); i++){

            if(temp->children.count(key[i]) == 0){ // doesnt exist
                temp->children[key[i]] = new node();
                temp->children[key[i]]->frequency = 1;
            }
            else{
                temp->children[key[i]]->frequency++;
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

    string getprefix(string key){
        string prefix = "";
        node* temp = root;
        for(int i =0; i< key.size(); i++){
            prefix += key[i];
            if(temp->children[key[i]]->frequency == 1){
                return prefix;
            }
            temp = temp->children[key[i]];
        }
        return prefix;
    }
};

void prefix(vector<string> words){
    Trie trie;
    for(int i =0; i< words.size(); i++){
        trie.insert(words[i]);
    }

    cout << "Shortest unique prefix = ";
    for(int i=0; i< words.size(); i++){
        cout << trie.getprefix(words[i]) << ", ";
    }
}

int main(){
    vector<string> words = {"zebra", "dog", "dove", "deer"};
    prefix(words);
    cout << endl;
    return 0;
}