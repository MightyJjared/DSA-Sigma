#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Problem: Given N ropes of different lengths, connect them into one rope with minimal total cost. 
The cost of connecting two ropes is equal to the sum of their lengths.

Approach: Use a min-heap (priority queue with greater<int>) to always pick the two smallest ropes, 
add their lengths to total cost, and push their combined length back into the heap. 
Repeat until only one rope remains.

Example: arr = {4, 3, 2, 6}
Step 1: Pick 2, 3 → cost = 5, total = 5, push 5 → heap = {4, 5, 6}
Step 2: Pick 4, 5 → cost = 9, total = 14, push 9 → heap = {6, 9}
Step 3: Pick 6, 9 → cost = 15, total = 29
Final Answer = 29
*/

int ropes(vector<int> arr){
    priority_queue<int, vector<int> , greater<int>> pq(arr.begin(), arr.end());
    int total_sum = 0;
    while(pq.size() != 1){
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();

        int min3 = min1 + min2;
        total_sum += min3;
        pq.push(min3);
    }
    return total_sum;
}

int main(){
    vector<int> arr = {4,3,2,6};
    cout << "Min cost to connect all ropes = " << ropes(arr) << endl;
    return 0;
}
