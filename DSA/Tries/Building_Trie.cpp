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
};

int main(){
    vector<string> words = {"the", "a", "there", "their", "any", "thee"};
    Trie trie;
    for(int i =0 ; i< words.size(); i++){
        trie.insert(words[i]);
    }
    cout << trie.search("there") << endl;
    return 0;
}