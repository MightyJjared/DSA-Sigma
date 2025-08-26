#include <iostream>
#include <unordered_map>
using namespace std;

// unordered_map in C++
// -----------------------------------------------------------
// 1. It stores elements in the form of key-value pairs (unique keys).
// 2. Internally, it uses a **hash table**.
// 3. Average time complexity of insert, erase, and find is O(1).
// 4. Worst case (due to hash collisions) can degrade to O(n).
// 5. The order of elements is not maintained (unlike std::map which is ordered).
// 6. Keys must be unique, but values can be duplicated.
// 7. Provides very fast lookups when key ordering is not important.


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