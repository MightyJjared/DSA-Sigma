#include <iostream>
#include <set>
using namespace std;

// set in C++
// -----------------------------------------------------------
// 1. It stores unique elements (no duplicates).
// 2. Internally, it uses a **balanced binary search tree** (Red-Black Tree).
// 3. Time complexity of insert, erase, and find is O(log n).
// 4. Elements are always stored in **sorted order** (ascending by default).
// 5. Duplicate insertions are ignored silently.
// 6. Provides ordered iteration over elements.
// 7. Useful when ordering of elements matters along with uniqueness.


int main(){
    set<int> s;

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

    s.insert(1); // duplicate, will not be added
    cout << "size = " << s.size() << endl;

    if(s.find(1) == s.end()){ // doesn't exist
        cout << "1 doesn't exist" << endl;
    } else {
        cout << "1 exists." << endl;
    }

    s.erase(1); // erase element 1 if it exists
    cout << "Set = ";
    for(auto itr : s){
        cout << itr << " ";
    }

    cout << endl;
    return 0;
}
