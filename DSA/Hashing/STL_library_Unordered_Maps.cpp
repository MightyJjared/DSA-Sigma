#include <iostream>
#include <unordered_map>
using namespace std;

// Two types of maps
// 1 - unordered maps in this internally hast table are used and O(1) is the avergae time complexity for 
// insert, delete, search.
// 2 - ordered maps in this self balancing binary trees are used and time complexity is O(logn) for
// insert, delete, search.

int main(){
    unordered_map<string, int> m;
    m["india"] = 150;
    m["china"] = 130;
    m["usa"] = 50;
    m["australia"] = 80;

    for(pair<string, int> i : m){
        cout << i.first << "," << i.second << endl;
    }

    if(m.count("nepal") == 1){
        cout << "nepal exists" << endl;
    }else if(m.count("nepal") == 0){
        cout << "nepal doesnt exist." << endl;
    }

    m["nepal"] = 40;

    if(m.count("nepal") == 1){
        cout << "nepal exists" << endl;
    }else if(m.count("nepal") == 0){
        cout << "nepal doesnt exist." << endl;
    }
    
    return 0;
}