#include <iostream>
#include <string>
using namespace std;

// This recursive function removes duplicate characters from a string
void duplicate(string sh, int n, int i, string ans, int arr[]) {
    if(i == n){
        // Base case: when we've reached the end of the string, print the answer
        cout << ans << endl;
        return;
    }

    // Convert current character to an index (0 for 'a', 1 for 'b', ..., 25 for 'z')
    int ch = sh[i] - 97;

    // If the character has not been seen before
    if(arr[ch] == false){
        arr[ch] = true; // Mark it as seen
        duplicate(sh, n, i + 1, ans + sh[i], arr); // Include it in the answer
    } else {
        // If already seen, skip adding this character
        duplicate(sh, n, i + 1, ans, arr);
    }
}

int main(){
    string sh = "apnacollege";
    int n = sh.size();
    string ans = "";

    // Array to track if a character has already been included (only lowercase letters)
    int arr[26] = {false};

    duplicate(sh, n, 0, ans, arr); // Start the recursion
    return 0;
}
