#include <iostream>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        // Start from the end of the string and move backwards
        for (int i = num.size() - 1; i >= 0; i--) {
            // Convert char digit to int and check if it's odd
            if ((num[i] - '0') % 2 == 1) {
                // Return substring from start to this position (inclusive)
                return num.substr(0, i + 1);
            }
        }
        // If no odd digit found, return empty string
        return "";
    }
};

int main() {
    Solution sol;

    string num1 = "42053";
    cout << "Input: " << num1 << endl;
    cout << "Largest odd number prefix: " << sol.largestOddNumber(num1) << endl;

    string num2 = "42050";
    cout << "Input: " << num2 << endl;
    cout << "Largest odd number prefix: " << sol.largestOddNumber(num2) << endl;

    string num3 = "2468";
    cout << "Input: " << num3 << endl;
    cout << "Largest odd number prefix: " << sol.largestOddNumber(num3) << endl;

    return 0;
}
