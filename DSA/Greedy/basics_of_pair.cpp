#include <iostream>
#include <utility> // For pair
using namespace std;

int main() {
    pair<int, string> student;
    student.first = 101;
    student.second = "Abdullah";

    cout << "ID: " << student.first << ", Name: " << student.second << endl;

    return 0;
}

#include <iostream>
#include <utility>
using namespace std;

int main() {
    pair<string, double> product = make_pair("Pen", 12.50);

    cout << "Product: " << product.first << ", Price: ₹" << product.second << endl;

    return 0;
}


#include <iostream>
#include <utility>
using namespace std;

int main() {
    pair<int, int> points[] = {{1, 2}, {3, 4}, {5, 6}};

    for (int i = 0; i < 3; i++) {
        cout << "x: " << points[i].first << ", y: " << points[i].second << endl;
    }

    return 0;
}
