#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
   Problem: Count the number of distinct elements in an array.
   Approach: 
   - We use an unordered_set which automatically stores only unique elements.
   - Insert each element of the array into the set (duplicates are ignored by default).
   - After inserting all elements, the size of the set gives the count of distinct elements.
   - Additionally, we print all distinct elements stored in the set.
   - Finally, return the set size as the answer.
*/

int count_distinct(vector<int> arr){
    unordered_set<int> s;
    for(int i =0; i< arr.size(); i++){
        s.insert(arr[i]);
    }

    for(int itr : s){
        cout << itr << " ";
    }
    cout << endl;
    return s.size();
}

int main(){
    vector<int> arr = {4,3,5,2,6,7,3,4,2,1};
    cout << "count " << count_distinct(arr) << endl;
    return 0;
}

