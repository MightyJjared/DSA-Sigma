#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    // Max-heap by default
    priority_queue<int> pq;

    // Push elements
    pq.push(10);
    pq.push(5);
    pq.push(20);

    cout << "Max-Heap order: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";

    // Min-heap
    // For min-heap, we must explicitly specify: 
    //   1) the container type (vector<int>) 
    //   2) the comparator (greater<int>) instead of default less<int>
    // This makes the smallest element have highest priority.
    priority_queue<int, vector<int>, greater<int>> minpq;
    minpq.push(10);
    minpq.push(5);
    minpq.push(20);

    cout << "Min-Heap order: ";
    while (!minpq.empty()) {
        cout << minpq.top() << " ";
        minpq.pop();
    }
    cout << "\n";

    return 0;
}
