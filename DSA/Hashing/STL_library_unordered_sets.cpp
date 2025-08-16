#include <iostream>
#include <unordered_set>
using namespace std;

// Two types of sets
// 1 - unordered sets in this internally hast table are used and O(1) is the avergae time complexity for 
// insert, delete, search.
// 2 - ordered sets in this self balancing binary trees are used and time complexity is O(logn) for
// insert, delete, search.

int main(){
    unordered_set<int> s;

    s.insert(1);
    s.insert(9);
    s.insert(5);
    s.insert(7);

    cout << "Set = ";
    for(auto itr : s){
        cout << itr << " ";
    }

    cout << endl;

    cout << "size = " << s.size() << endl;

    s.insert(1);
    cout << "size = " << s.size() << endl;

    if(s.find(1) == s.end()){ // doesnt exist
        cout << "1 doenst exists" << endl;
    }else if(s.find(1) != s.end()){ // exists
        cout << "1 exists." << endl;
    }

    s.erase(1);
    cout << "Set = ";
    for(auto itr : s){
        cout << itr << " ";
    }

    cout << endl;
    return 0;
}