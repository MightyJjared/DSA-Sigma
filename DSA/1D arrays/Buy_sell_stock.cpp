#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum profit from buying and selling a stock once
int maxprofit(vector<int> prices) {
    int bestbuy = prices[0];  // Track the lowest price encountered so far
    int mxprofit = 0;         // Store the maximum profit
    int n = prices.size();    // Get the number of days

    // Iterate through the prices from day 1 to n-1
    for (int i = 1; i < n; i++) {
        // If selling today gives a better profit, update mxprofit
        if (prices[i] > bestbuy) {
            mxprofit = max(mxprofit, prices[i] - bestbuy);
        }
        // Update bestbuy to the minimum price encountered so far
        bestbuy = min(bestbuy, prices[i]);
    } 
    return mxprofit;  // Return the maximum possible profit
}

int main() {
    vector<int> prices = {5, 7, 3, 8, 1, 12, 4};  // Stock prices on different days
    int result = maxprofit(prices);  // Call the function to compute max profit
    cout << "Maximum Profit: " << result << endl;  // Print the result
    return 0;
}
