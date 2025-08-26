#include <iostream>
#include <map>
using namespace std;

// map in C++
// -----------------------------------------------------------
// 1. It stores elements in the form of key-value pairs (unique keys).
// 2. Internally, it uses a **balanced binary search tree** (usually Red-Black Tree).
// 3. Time complexity of insert, erase, and find is O(log n).
// 4. Elements are always stored in **sorted order of keys**.
// 5. Keys must be unique, but values can be duplicated.
// 6. Provides ordered traversal of elements using iterators.
// 7. Useful when both fast lookups and maintaining key order are important.


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