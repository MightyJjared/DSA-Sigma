#include <iostream>
#include <string>
using namespace std;

string largestOddNumber(string num) {
    string ans = "";
    string reverse = "";
    for(int i = num.size() - 1; i >= 0; i--){
        reverse += num[i];
    }
    for(int i = 0; i < reverse.size(); i++){
        if(reverse[i] % 2 == 0){
            continue;
        }
        else{
            while(i != reverse.size()){
                ans += reverse[i];
                i++;
            }
            break;
        }
    }
    string ans1 = "";
    for(int i = ans.size() - 1; i >= 0; i--){
        ans1 += ans[i];
    }
    return ans1;
}

int main() {
    string num1 = "42053";
    cout << "Input: " << num1 << "\nLargest Odd Number Prefix: " << largestOddNumber(num1) << "\n";

    string num2 = "42050";
    cout << "Input: " << num2 << "\nLargest Odd Number Prefix: " << largestOddNumber(num2) << "\n";

    string num3 = "2468";
    cout << "Input: " << num3 << "\nLargest Odd Number Prefix: " << largestOddNumber(num3) << "\n";

    return 0;
}
