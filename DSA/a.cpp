#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <queue>
#include <string>
using namespace std;


int main(){
    vector<string> wordList;
    bool istrue = false;
    string endWord = "dog";
    wordList = {"hot","dot","dog","lot","log","cog"};
    for(int i =0; i< wordList.size(); i++){
        if(wordList[i] == endWord){
            cout << "found at " << i << endl;
            istrue = true;
        }
    }
    if(istrue == false){
        cout << "not found" << endl;
    }
    return 0;
}