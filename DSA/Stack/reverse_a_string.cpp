#include <iostream>
#include <string>
#include <stack>
using namespace std;

// reversing a string using stack
string reversestring(string str){
    stack<char> s;
    for(int i =0;i< str.size(); i++){
        s.push(str[i]);
    }
    string ans;
    while(!s.empty()){
        char top = s.top();
        ans += top;
        s.pop();
    }
    return ans;
}
int main(){
    string str = "abcde";
    cout << "reverse = " << reversestring(str) << endl;
    return 0;
}