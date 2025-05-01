#include <iostream>
using namespace std;

// Problem: Given 'n' friends, each friend can either stay single or be paired up with another friend.
// Find the total number of ways in which the friends can remain single or be paired up.
//
// For example, for n = 3:
// - All single: (1)(2)(3)
// - One pair: (1-2)(3), (1-3)(2), (2-3)(1)
// So, total = 4 ways

int friends_pair(int n){
    // Base cases:
    // If there's only 1 friend, they can only stay single -> 1 way
    // If there are 2 friends, they can either stay single or pair up -> 2 ways
    if(n == 1 || n == 2){
        return n;
    }

    // Recursive case:

    // Case 1: The nth friend stays single -> solve the problem for (n-1) friends
    int ans1 = friends_pair(n - 1);

    // Case 2: The nth friend pairs up with any of the (n-1) others
    // For each such pair, solve the problem for the remaining (n-2) friends
    int ans2 = (n - 1) * friends_pair(n - 2);

    // Total ways = ways when nth is single + ways when nth is paired
    return ans1 + ans2;
}

int main(){
    int friends = 4;
    cout << friends_pair(friends) << endl;  // Output the total number of ways
    return 0;
}
