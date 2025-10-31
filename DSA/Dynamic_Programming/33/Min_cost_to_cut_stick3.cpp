#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// tabulation
/*
Important in memo i was going from 1 to m so opposite here and j was going from m to 1 so opposite
but think logically and acocrding to base case j will always be greater or equal to i so we willstart j from 
i instead of 1
and also if you see here int cut = cuts[j+1] - cuts[i-1] 
                            + dp[i][k-1]
                            + dp[k+1][j];
in last it is saying dp[k+1] ie if i = m it is going m+1 but our vector we declared was m+1 so if we compute
dp[k+1] ie m+1 it will go out of bounds so declare the 2d vector as m+2 instead of m +1
*/
/*
🔹 LeetCode Reference: 1547. Minimum Cost to Cut a Stick
---------------------------------------------------------
Given a stick of length `n` and an array `cuts` where cuts[i] denotes a position to cut the stick. 
The cost of a cut is equal to the length of the stick being cut. Return the minimum total cost 
to cut the stick into pieces.
*/

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        sort(cuts.begin(), cuts.end());

        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        vector<vector<int>> dp(m+2, vector<int> (m+2, 0));
 
        for(int i = m; i >= 1; i--){
            for(int j = i; j <= m; j++){
                int minimum = 1e9;
                for(int k = i; k <= j; k++){
                    int cut = cuts[j+1] - cuts[i-1] 
                            + dp[i][k-1]
                            + dp[k+1][j];
                    
                    minimum = min(minimum, cut);
                }
                dp[i][j] = minimum;
            }
        }       

        return dp[1][m];
    }
};

int main() {
    Solution sol;

    int n = 7;
    vector<int> cuts = {1, 3, 4, 5};

    cout << "Minimum cost: " << sol.minCost(n, cuts) << endl;

    return 0;
}
