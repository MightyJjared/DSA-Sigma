#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// tabulation (space optimized from 3d to 2d)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int count = 2;
        vector<vector<int>> ahead(2, vector<int>(3, 0)); // tabulation table
        vector<vector<int>> current(2, vector<int>(3, 0));

        for (int index = 0; index <= n; index++) { // base case
            for (int buy = 0; buy <= 1; buy++) {
                current[buy][0] = 0;
            }
        }

        for (int buy = 0; buy <= 1; buy++) { // base case
            for (int count = 0; count <= 2; count++) {
                current[buy][count] = 0;
            }
        }

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int count = 1; count <= 2; count++) {
                    int profit = 0;
                    if (buy == 1) { // can buy
                        profit = max(-prices[index] + ahead[0][count], // buy
                                     0 + ahead[1][count]);             // skip
                    }
                    else { // can sell
                        profit = max(prices[index] + ahead[1][count - 1], // sell
                                     0 + ahead[0][count]);               // skip
                    }
                    current[buy][count] = profit;
                }
            }
            ahead = current;
        }
        return ahead[1][2];
    }
};

int main() {
    Solution s;
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout << "Maximum Profit: " << s.maxProfit(prices) << endl;
    return 0;
}
