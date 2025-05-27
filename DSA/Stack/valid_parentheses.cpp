#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

bool isValid(string str1){
    stack<char> s;
    for(int i =0 ; i< str1.size(); i++){
        char ch = str1[i];
        if(ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }
        else{
            if(s.empty()){
                return false;
            }

            if((ch == ')' && s.top() == '(') ||
           (ch == ']' && s.top() == '[') ||
           (ch == '}' && s.top() == '{')){
            s.pop();
           }
           else{
            return false;
           }
        }
    }
    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string str1 = "{[()]}"; // valid
    string str2 = "{[(})]}"; // invalid
    if(isValid(str2)){
        cout << "Valid parenthesis.";
    }
    else{
        cout << "Invalid parenthesis.";
    }
    cout << endl;
    return 0;
}
