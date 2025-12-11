#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// NOTE - Subsequence and substring are different
// tabulation

/*
🔹 Problem Explanation: Longest Common Substring
- Given two strings text1 and text2, we want the **longest substring that appears in both**.
- A substring is contiguous characters (unlike subsequence, which can skip characters).
- Example: text1 = "acbeklmz", text2 = "aceklmy" → Longest Common Substring = "cekl"

🔹 Approach (Dynamic Programming, Tabulation):
- Use a 2D dp table where dp[i][j] represents the **length of the longest common substring ending at text1[i-1] and text2[j-1]**.
- If characters match: dp[i][j] = 1 + dp[i-1][j-1] (extend previous substring)
- If characters don't match: dp[i][j] = 0 (substring must be contiguous)
- Keep track of the maximum value in dp to know the length and ending position of the substring.
- To reconstruct the substring: start at the end position of the maximum, move diagonally up-left in dp while values are non-zero, collecting characters from text1, then reverse the collected string.
- Optional: printing the dp table helps visualize how substrings build up across the strings.
*/

class Solution {
public:
    void longestCommonSubstring(string text1, string text2) {
        int i1 = text1.size();
        int i2 = text2.size();

        vector<vector<int>> dp(i1+1, vector<int>(i2+1, 0));

        for(int i =0; i <= i1; i++){ //base case
            dp[i][0] = 0;
        }
        for(int i =0; i <= i2; i++){ // base case
            dp[0][i] = 0;
        }

        for(int i =1; i <= i1; i++){
            for(int j = 1; j <= i2; j++){
                if(text1[i-1] == text2[j-1]){ // match case
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        for(int i =0; i<= i1; i++){
            for(int j =0; j <= i2; j++){
                cout << dp[i][j] << " "; // print dp table to visualize LCS length computation
            }
            cout << endl;
        }
        
        int maxi =0;
        int n = 0, m = 0;
        for(int i =1; i <= i1; i++){
            for(int j = 1; j <= i2; j++){
                if(dp[i][j] > maxi){
                    maxi = max(maxi, dp[i][j]);
                    n =i;
                    m = j;
                }  
            }
        }
        cout << "count of longest Common substring : " << maxi << endl;
        
        string ans;
        while(dp[n][m] != 0){
            ans += text1[n-1];
            m--;
            n--;
        }
        reverse(ans.begin(), ans.end());
        cout << "Longest Common Substring : " << ans << endl;
    }
};

int main() {
    Solution sol;

    // Example inputs
    string text1 = "acbeklmz";
    string text2 = "aceklmy";

    sol.longestCommonSubstring(text1, text2);

    return 0;
}
 