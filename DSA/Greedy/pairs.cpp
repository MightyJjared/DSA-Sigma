#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// here we want to create a pair of the two vector start and end, imagine it like start vector has the index values 
// and the end vector has normal values and we want to sort them in ascending order the end vector,
// but we also want the index values ie start vector with them when we sort them, so we want to create a pair of value
// and their index.

bool compare(pair<int, int> p1, pair<int, int> p2){ // here we are sorting them based on second value of the pair
    return p1.second < p2.second; // this sorts them is ascending
   // return p1.second > p2.second // this sorts them is descending
}
int main(){
    vector<int> start = {0,1,2};
    vector<int> end = {9,2,4};
    vector<pair<int, int>> p1(3, make_pair(0, 0)); // here we are making a pair of vector type, and int, int are the 
    // type of data and name is p1 and 3 , make pair part is the property of vector to initialize it, where 3 is size
    // and  makepair is initializing the index pair with 0 and 0.
    p1[0] = make_pair(0,9);
    p1[1] = make_pair(1,2);
    p1[2] = make_pair(2,4);

    for(int i =0; i < p1.size(); i++){
        cout << p1[i].first << "," << p1[i].second;
        cout << endl;
    }
    
    sort(p1.begin(), p1.end(), compare);

    cout << "------Sorted------" << endl;

    for(int i =0; i < p1.size(); i++){
        cout << p1[i].first << "," << p1[i].second;
        cout << endl;
    }

    return 0;
}