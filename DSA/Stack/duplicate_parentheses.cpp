#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

bool isValid(string str){
    stack<char> s;
    for(int i =0; i< str.size(); i++){
        char ch = str[i];
        if(ch != ')'){
            s.push(ch);
        }
        else{
            if(s.top() == '('){
                return true;
            }
            while(s.top() != '('){
                s.pop();
            }
            s.pop();
        }
    } 
    return false;
}

int main(){
    string str1 = "(x+y)"; // valid
    string str2 = "((x+y))"; // invalid
    string str3 = "((x+y) + z)"; // valid
    string str4 = "((x+y) + (z))"; // valid
    string str5 = "((x+y) + ((z)))"; // invalid
    if(isValid(str5)){
        cout << "duplicate parenthesis.";
    }
    else{
        cout << "not duplicate parenthesis.";
    }
    cout << endl;
    return 0;
}