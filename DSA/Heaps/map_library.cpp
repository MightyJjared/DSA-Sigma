#include <iostream>
#include <map>
#include <string>
using namespace std;

// map consists of key value pair, where key is unique.
int main(){
    map<int, string> m;
    m[100] = "Mohd";
    m[10] = "Abdullah";
    m[102] = "Ansari";
  
    // in the for loop maps will always print the smaller key value first
    for(auto iterator : m){
        cout << "Key = " << iterator.first << " , " << "Value = " << iterator.second << endl;
    }
    return 0;
}