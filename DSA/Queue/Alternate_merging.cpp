#include <iostream>
#include <queue>
using namespace std;

/*
    Given a queue of even length, split it into two halves and then
    interleave the elements of the two halves into the original queue.

    For example, if the queue is:
    Input:  1 2 3 4 5 6 7 8 9 10
    Output: 1 6 2 7 3 8 4 9 5 10

    This function assumes the queue size is even.
*/
// Constaraint use only one extra queue
void merge(queue<int> &q){
    queue<int> temp;
    int n = q.size();

    for(int i =0; i< n/2; i++){ //transferiing first half element of original queue to temp, therefore original queue
        temp.push(q.front());   // contains the last half elemnts and temp contains first half elemnts
        q.pop();
    }

    while(!temp.empty()){    // placing all the numbers alternative in the original queue
        q.push(temp.front());
        temp.pop();

        q.push(q.front());
        q.pop();
    }
}

int main(){
    queue<int> q;
    for(int i =1; i<= 10; i++){
        q.push(i);
    }
    
    cout << "Before:";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    
    // Need to refill the queue because queue is empty
    for(int i = 1; i <= 10; i++){
        q.push(i);
    }

    merge(q);

    cout << "After:";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
