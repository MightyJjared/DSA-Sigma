#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// recursive (for explanation refer striver dp 50)
/*
🔹 LeetCode Reference: 1547. Minimum Cost to Cut a Stick
---------------------------------------------------------
You are given a stick of length `n` and an integer array `cuts` 
where cuts[i] denotes a position to cut the stick.

After each cut, you have to pay the cost equal to the length 
of the stick you are cutting. After the cut, the stick is split 
into two smaller sticks. Return the minimum total cost to cut 
the entire stick into pieces.
*/

class Solution {
public:
    int helper(int i, int j, vector<int> &arr) {
        if (i > j) {
            return 0;
        }

        int minimum = 1e9;
        for (int k = i; k <= j; k++) {
            int cut = arr[j + 1] - arr[i - 1]
                      + helper(i, k - 1, arr)
                      + helper(k + 1, j, arr);

            minimum = min(minimum, cut);
        }
        return minimum;
    }

    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        sort(cuts.begin(), cuts.end());

        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        return helper(1, m, cuts);
    }
};

int main() {
    Solution sol;

    int n = 7;
    vector<int> cuts = {1, 3, 4, 5};

    cout << "Minimum cost: " << sol.minCost(n, cuts) << endl;

    return 0;
}
