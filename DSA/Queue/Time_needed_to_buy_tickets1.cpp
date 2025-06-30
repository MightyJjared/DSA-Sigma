#include <iostream>
using namespace std;

// This one is without using queue

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

int timeRequiredToBuy1(int arr[], int n, int k){
    int count = 0;
    while(arr[k] > 0){
        for(int i = 0; i < n; i++){
            if(arr[i] > 0){
                arr[i]--;
                count++;
            }
            if(arr[k] == 0){
                break;
            }
        }
    }
    return count;
}


int main(){
    int arr[] = {5,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 0;

    cout << timeRequiredToBuy1(arr, n, k) << endl;
    return 0;
}

