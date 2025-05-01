#include <iostream>
using namespace std;

// Question:
// Print all binary strings of length N such that there are no consecutive 1s in any string.
// Example for N = 3: valid outputs are 000, 001, 010, 100, 101

void binary_string(int n, int lastspace, string ans){
    // Base case: when no positions left to fill, print the result
    if(n==0){
        cout << ans << endl;
        return;
    }

    // If the last added character was not '1', we can add both '0' and '1'
    // lastspace != 1 means either the last character was '0' or it's the first character
    if(lastspace != 1){
        binary_string(n-1,0,ans+"0"); // Place '0'
        binary_string(n-1,1,ans+"1"); // Place '1'
    }
    else{
        // If last character was '1', we can only add '0' to avoid consecutive 1s
        binary_string(n-1,0,ans+"0");
    }
}

int main(){
    string ans = "";
    binary_string(3,0,ans);
    return 0;
}
