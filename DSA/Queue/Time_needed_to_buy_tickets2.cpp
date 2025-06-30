#include <iostream>
#include <queue>
using namespace std;

// this one is using queue
// The main reason we are usng queue is because we dont want those indexs whose values becomes 0 exempt the k index
// by using queue we can pop that indexes

/*
Leetcode 2073: Time Needed to Buy Tickets

You have a queue of `n` people. Each person in the queue has a certain number of tickets to buy, represented by an array `arr` of size `n`.
The person at position `i` needs to buy `arr[i]` tickets.

The queue works as follows:
- The person at the front buys one ticket and then goes to the end of the line if they still have tickets left.
- If they have no more tickets to buy, they leave the queue.

You are given the index `k` of a person. Return the total time (in seconds) it takes for the person at index `k` to finish buying all their tickets.

Each person takes 1 second to buy a ticket.

Example:
Input: arr = [5,1,1,1], k = 0
Output: 8
*/

int timeRequiredToBuy(int arr[], int n, int k){
    queue<int> q;
    for(int i =0; i< n;i++){
        q.push(i);
    }
    int count = 0;
    while(arr[k] > 0){
        if(arr[q.front()] > 0){
            count ++;
            arr[q.front()]--;
            if(arr[q.front()] > 0){
                q.push(q.front());
                q.pop();
            }
            else{
                q.pop();
            }
        }
    }
    return count;
}

int main(){
    int arr[] = {5,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 0;

    cout << timeRequiredToBuy(arr, n, k) << endl;
    return 0;
}