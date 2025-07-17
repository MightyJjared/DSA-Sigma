#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    map<int, string> m;
    m[100] = "Mohd";
    m[101] = "Abdullah";
    m[102] = "Ansari";

    for(auto iterator : m){
        cout << "Key = " << iterator.first << " , " << "Value = " << iterator.second << endl;
    }
    return 0;
}