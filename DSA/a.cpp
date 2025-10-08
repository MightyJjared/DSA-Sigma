#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to count subsets with sum = K
int helper(int n, int sum, vector<int> &nums, vector<int> &temp)
{
    if (sum == 0)
    { // base case1
        temp.push_back(nums[n]);
        for (int itr : temp){
            cout << itr << " ";
        }
        cout << endl;
        temp.pop_back();
        return 1;
    }
    if (n == 0)
    { // base case 2
        if (nums[n] == sum)
        {
            temp.push_back(nums[n]);
            for (int itr : temp){
                cout << itr << " ";
            }
            cout << endl;
            temp.pop_back();
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int not_pick = helper(n - 1, sum, nums, temp);

    int pick = 0;
    if (nums[n] <= sum)
    {
        temp.push_back(nums[n]);
        pick = helper(n - 1, sum - nums[n], nums, temp);
        temp.pop_back();
    }

    return pick + not_pick;
}

int countSubsetsWithSumK(vector<int> &nums, int target)
{
    vector<int> temp;
    int sum = 5;
    int n = nums.size();
    return helper(n - 1, sum, nums, temp);
}

int main()
{
    // Example input
    int n = 5, sum = 5;
    vector<int> nums = {1, 2, 3, 2, 1};

    int result = countSubsetsWithSumK(nums, sum);
    cout << "Count of subsets with sum " << sum << " = " << result << "\n";

    return 0;
}
