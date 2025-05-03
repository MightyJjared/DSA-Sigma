#include <iostream>
#include <string>
using namespace std;

/*
Question 3:
We are given a string S, we need to find the count of all contiguous substrings starting and ending with the same character. [Leetcode Premium Qs]
Sample Input 1:
S = "abcab"
Sample Output 1:
7
There are 15 substrings of "abcab":
a, ab, abc, abca, abcab, b, bc, bca, bcab, c, ca, cab, a, ab, b
Out of the above substrings, there are 7 substrings: a, abca, b, bcab, c, a and b.
So, only 7 contiguous substrings start and end with the same character.

Sample Input 2:
S = "aba"
Sample Output 2:
4
The substrings are: a, b, a and aba
*/

void substring(string str){
    int count = 0;
    int n = str.size();
    for(int i =0; i<n; i++){
        for(int j = i; j<n; j++){
            if(str[i] == str[j]){
                count++;
            }
        }
    }
    cout << count << endl;
}




int main(){
    string str = "aba";
    substring(str);
    return 0;
}
