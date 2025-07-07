#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
📌 Problem: Job Sequencing with Deadlines

You are given a list of jobs, where each job has:
- a deadline (an integer, meaning the job must be done on or before this day)
- a profit (earned if the job is done on time)

🧠 Constraints:
- Each job takes **exactly 1 day**
- Only **one job** can be done **per day**
- A job can only be scheduled on a day **≤ its deadline**

🎯 Goal:
Choose a subset of jobs such that:
- No two jobs are scheduled on the same day
- All selected jobs are scheduled on or before their deadline
- The total profit is **maximized**

👀 Example:
Suppose the jobs are:

    jobs = {
        {4, 20},   // deadline 4, profit 20
        {1, 10},   // deadline 1, profit 10
        {1, 40},   // deadline 1, profit 40
        {1, 30}    // deadline 1, profit 30
    };

- After sorting by profit (descending): (1, 40), (1, 30), (4, 20), (1, 10)
- We can pick:
    - Job with profit 40 on day 1 ✅
    - Job with profit 20 on day 4 ✅
- Total profit = 40 + 20 = 60 ✅

⚙️ This code uses a greedy strategy:
- It sorts jobs by profit in descending order
- Then tries to pick jobs whose deadlines allow fitting them in sequence using a `safe_deadline` tracker
*/

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second > p2.second; // descending order
}

int max_profit(vector<pair<int, int>> jobs){
    int n = jobs.size();

    sort(jobs.begin(), jobs.end(), compare); // descending order

    int profit = jobs[0].second;
    int safe_deadline = 2;

    for(int i =1; i< n; i++){
        if(jobs[i].first >= safe_deadline ){
            profit += jobs[i].second;
            safe_deadline++;
        }
    }
    cout << "max profit = " << profit << endl;
}

int main(){
    int n = 4;
    vector<pair<int, int>> jobs(n, make_pair(0, 0));
    // first in pair is deadline and second is the profit
    // each job takes 1 day to complete
    jobs[0] = make_pair(4, 20);
    jobs[1] = make_pair(1, 10);
    jobs[2] = make_pair(1, 40);
    jobs[3] = make_pair(1, 30);

    max_profit(jobs);

    return 0;
}
