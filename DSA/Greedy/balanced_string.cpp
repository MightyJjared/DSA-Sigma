#include <iostream>
using namespace std;

/*
📌 Problem: Split a Balanced String

You are given a string `s` consisting of only characters `'L'` and `'R'`.
A string is called **balanced** if it has the same number of `'L'` and `'R'`.

🎯 Goal:
Split the given string into the **maximum number of balanced substrings**.

✅ Return the number of such balanced substrings.

🧠 How it works:
- Use a variable `balance`:
    - Increase when you see 'L'
    - Decrease when you see 'R'
- Whenever balance becomes 0, you’ve found a balanced substring.

👀 Example:
Input: `"RLRRLLRLRL"`

Breakdown:
- "RL" → balanced
- "RRLL" → balanced
- "RL" → balanced
- "RL" → balanced

✅ Output: 4
*/

int balancedStringSplit(string s) {
    int count = 0;
    int balance = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'L'){
            balance++;
        }
        else if(s[i] == 'R'){
            balance--;
        }
        if(balance == 0){
            count++;
        }
    }
    return count;
}

int main() {
    string s = "RLRRLLRLRL";
    cout << "Maximum number of balanced substrings = " << balancedStringSplit(s) << endl;
    return 0;
}
