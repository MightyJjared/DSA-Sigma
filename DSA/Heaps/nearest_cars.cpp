#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Question:
Given a list of car coordinates (x, y) on a 2D plane, find the K nearest cars to the origin (0,0).
The distance is calculated using the squared Euclidean formula: distance² = x² + y².

Approach:
1. Create a `car` class to store each car's distance from origin and its index in the input list.
2. Overload the `<` operator so that the priority queue (min-heap) gives priority to smaller distances.
3. Calculate the squared distance for each car and store it in a vector of `car` objects.
4. Build a min-heap (`priority_queue`) from this vector.
5. Extract the top K elements from the priority queue, which correspond to the K nearest cars.

Example:
Input:
    position = [(3,3), (5,-1), (-2,4)], k = 2
Distances:
    Car0: 3² + 3² = 18
    Car1: 5² + (-1)² = 26
    Car2: (-2)² + 4² = 20
Sorted by distance:
    Car0 (18), Car2 (20), Car1 (26)
Output:
    Nearest 2 cars -> Car0, Car2
*/

class car {
public:
    int distance;
    int index;

    car(int distance, int index) {
        this->distance = distance;
        this->index = index;
    }

    bool operator < (const car &obj) const {
        return this->distance > obj.distance;
    }
};

void nearby_cars(vector<pair<int, int>> position, int k) { // O(klogn)
    vector<car> cars;

    for (int i = 0; i < position.size(); i++) { // O(n)
        int distance = (position[i].first * position[i].first) + (position[i].second * position[i].second);
        int index = i;
        cars.push_back(car(distance, index));
    }

    priority_queue<car> pq(cars.begin(), cars.end());

    cout << "Nearest cars from index = " << endl;
    for (int i = 0; i < k; i++) { //O(klogn)
        cout << "Car" << pq.top().index << " " << endl;
        pq.pop(); // O(logn)
    }
}

int main() {
    vector<pair<int, int>> position;
    position.push_back(make_pair(3, 3));
    position.push_back(make_pair(5, -1));
    position.push_back(make_pair(-2, 4));

    int k = 2;

    nearby_cars(position, k);
    return 0;
}
