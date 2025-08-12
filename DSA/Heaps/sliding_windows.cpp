#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Question:
Given an array and a window size k, find the maximum element in each sliding window of size k as the window moves 
from left to right.

Example:
arr = [1, 3, -1, -3, 5, 3, 6, 7], k = 3
Windows and their max:
[1, 3, -1] -> 3
[3, -1, -3] -> 3
[-1, -3, 5] -> 5
[-3, 5, 3] -> 5
[5, 3, 6] -> 6
[3, 6, 7] -> 7
Output: 3 3 5 5 6 7

Approach:
We use a max heap (priority_queue) storing elements along with their indices.
1. Insert first k elements into the heap.
2. For each new element added (as the window slides), remove elements from the top if their index is outside the 
current window.
3. The heap’s top always contains the current window’s maximum.
This ensures O(n log k) time since each element is pushed and popped at most once.
*/

class window {
public:
    int data;
    int index;

    window(int data, int index) {
        this->data = data;
        this->index = index;
    }

    bool operator<(const window &obj) const {
        return this->data < obj.data; // max heap based on data
    }
};

void sliding_windows(vector<int> arr, int k) {
    priority_queue<window> pq;

    for (int i = 0; i < k; i++) {
        pq.push(window(arr[i], i));
    }
    cout << "Max = " << pq.top().data << " ";

    for (int i = k; i < arr.size(); i++) {
        while (!pq.empty() && pq.top().index <= i - k) {
            pq.pop();
        }
        pq.push(window(arr[i], i));
        cout << pq.top().data << " ";
    }
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    sliding_windows(arr, k);
    cout << endl;
    return 0;
}
