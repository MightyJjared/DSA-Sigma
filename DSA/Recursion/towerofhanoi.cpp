#include <iostream>
#include <string>
using namespace std;

// Recursive function to solve Tower of Hanoi problem
void towerofhanoi(int n, string source, string helper, string destination){
    // Base case: if only one disk, move it directly from source to destination
    if(n == 1){
        cout << "Transferred disk " << n << " from " << source << " to " << destination << endl;
        return;
    }

    // Step 1: Move top (n-1) disks from source to helper, using destination as intermediate
    towerofhanoi(n - 1, source, destination, helper);

    // Step 2: Move the largest (nth) disk from source to destination
    cout << "Transferred disk " << n << " from " << source << " to " << destination << endl;

    // Step 3: Move the (n-1) disks from helper to destination, using source as intermediate
    towerofhanoi(n - 1, helper, source, destination);
}

int main(){
    int n = 3; // Number of disks
    string source = "source";
    string helper = "helper";
    string destination = "destination";

    // Call the recursive function to solve the Tower of Hanoi problem
    towerofhanoi(n, source, helper, destination);

    return 0;
}
