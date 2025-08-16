#include <iostream>
#include <map>
using namespace std;

// Two types of maps
// 2 - ordered maps in this self balancing binary trees are used and time complexity is O(logn) for
// insert, delete, search.
// if we want to maintain order in maps we will use maps else unordered map.
// here the order in for loop will be ascending order based upon key

int main(){
    map<string, int> m;
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