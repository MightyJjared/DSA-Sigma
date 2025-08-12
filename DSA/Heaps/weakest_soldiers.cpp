/*
This program finds the k weakest rows in a binary matrix based on the number of soldiers.
A soldier is represented by 1 and a civilian by 0.
The weakness of a row is determined first by the number of soldiers (ascending order),
and if there’s a tie, the row with the smaller index is considered weaker.

Algorithm:
1. For each row in the matrix:
   - Count the number of soldiers (1's).
   - Store the count along with the row index in a `row` object.
2. Push all `row` objects into a min-priority queue (`priority_queue` with custom comparator).
   - Comparator ensures rows are sorted by soldier count first, then by index.
3. Pop the top k elements from the priority queue and print their indices.
   - These correspond to the k weakest rows.

Example:
Input:
matrix = {
    {1,0,0,0},
    {1,1,1,1},
    {1,0,0,0},
    {1,0,0,0}
}
k = 2
Output:
0 2
Explanation: Row 0 and Row 2 have the fewest soldiers and are weaker than others.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class row {
public:
    int count;
    int idx;

    row(int count, int idx) {
        this->count = count;
        this->idx = idx;
    }

    bool operator < (const row &obj) const {
        if (this->count == obj.count) { // checking whether both rows have the same number of soldiers.
            return this->idx > obj.idx;
        }
        return this->count > obj.count;
    }
};

void weakest_soldiers(vector<vector<int>> &matrix, int k) {
    vector<row> rows;
    for (int i = 0; i < matrix.size(); i++) {
        int count = 0;
        for (int j = 0; j < matrix[i].size(); j++) {
            count += matrix[i][j];
        }
        rows.push_back(row(count, i));
    }

    priority_queue<row> pq(rows.begin(), rows.end());

    for (int i = 0; i < k; i++) {
        cout << pq.top().idx << " ";
        pq.pop();
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1,0,0,0},
        {1,1,1,1},
        {1,0,0,0},
        {1,0,0,0}
    };

    int k = 2;
    weakest_soldiers(matrix, k);
    cout << endl;
    return 0;
}
