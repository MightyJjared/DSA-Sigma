#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
   Problem: Find the Union and Intersection of two arrays.

   Approach:
   - We use an unordered_set to take advantage of its O(1) average time for insertions and lookups.
   - For Union:
       1. Insert all elements of arr1 into the set.
       2. Insert all elements of arr2 into the same set.
       3. Since a set automatically removes duplicates, the final set contains only unique elements from both arrays.
       4. Print all elements of the set → this gives the union.
   - For Intersection:
       1. Insert all elements of arr1 into the set.
       2. Traverse arr2:
            - If the current element exists in the set, print it (this ensures it is common).
            - Erase the element from the set after printing, to avoid duplicate printing in case arr2 has repeated elements.
       3. This ensures only distinct common elements are printed → this gives the intersection.
*/

void Union(vector<int> arr1, vector<int> arr2){ // unique from both
    unordered_set<int> s;

    for(int i =0; i< arr1.size(); i++){
        s.insert(arr1[i]);
    }

    for(int i =0; i< arr2.size(); i++){
        s.insert(arr2[i]);
    }

    for(int itr : s){
        cout << itr << " ";
    }
}

void intersection(vector<int> arr1, vector<int> arr2){ // common in both
    unordered_set<int> s;

    for(int i =0; i< arr1.size(); i++){
        s.insert(arr1[i]);
    }

    for(int i =0; i< arr2.size(); i++){
        if(s.find(arr2[i]) != s.end()){
            cout << arr2[i] << " ";
            s.erase(arr2[i]);
        }
    }
}

int main(){
    vector<int> arr1 = {7,3,9};
    vector<int> arr2 = {6,3,9,2,9,4};

    cout << "Union = ";
    Union(arr1, arr2);
    cout << endl;

    cout << "Intersection = ";
    intersection(arr1, arr2);
    cout << endl;
    return 0;
}
