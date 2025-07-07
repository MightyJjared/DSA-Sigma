#include <iostream>
#include <vector>
using namespace std;

/*
📌 Problem: Minimum Number of Coins for a Given Amount

You are given:
- A list of coin denominations (e.g. 1, 2, 5, 10, ..., 2000)
- A total value (e.g. 599)

🧠 Goal:
Find the **minimum number of coins** needed to make up the given value,  
assuming an **infinite supply of each coin**.

💡 Approach:
- Use a **greedy strategy**: always pick the largest coin that does not exceed the remaining value.
- Subtract it from the value and repeat.
- Stop when the value becomes 0.

🔢 Example:
Coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000}  
Value = 599

Steps:
- Use one 500 → remaining = 99
- Use one 50 → remaining = 49
- Use two 20 → remaining = 9
- Use one 5 → remaining = 4
- Use two 2 → remaining = 0

Total coins used = 1 + 1 + 2 + 1 + 2 = 7 ✅
*/

void change(vector<int> coins, int value){
    int count = 0;
    int n = coins.size();
    for(int i = n-1; i >=0 && value > 0; i--){
        if(coins[i] <= value){
            count += value / coins[i];
            value = value % coins[i];
        }
    }
    cout << "min change = " << count << endl;
}
int main(){
    vector<int> coins = {1,2,5,10,20,50,100,500,2000};
    int value = 599;
    change(coins, value);
    return 0;
}