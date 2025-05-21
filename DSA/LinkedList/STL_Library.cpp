#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void printlist(list<int> l1){
    list<int>::iterator itr1; // iterator can be used for array, vector, linked list etc.
    for(itr1 = l1.begin(); itr1 != l1.end(); itr1++){
        cout << (*itr1) << " -> ";
    }
    cout << "NULL\n";
}
int main(){
    list<int> l1; // linked list initialization 
    l1.push_front(40);
    l1.push_front(30);
    l1.push_front(20);
    l1.push_front(10);
    l1.push_back(50);
    printlist(l1);

    cout << "Size of linked list : " << l1.size() << endl; // gives size of linked list

    cout << "head of linked list : " << l1.front() << endl;
    cout << "tail of linked list : " << l1.back() << endl;

    l1.pop_front();
    cout << "popped  1 node : ";
    printlist(l1);

    l1.pop_back();
    cout << "popped  last node : ";
    printlist(l1);

    // Insert 25 at 2rd position (index 1)
    list<int>::iterator it = l1.begin();
    advance(it, 1); // move to position 1
    l1.insert(it, 25);

    printlist(l1);
    return 0;
}