#include <iostream>
#include <stack>
using namespace std;

// we are creating a function which will push element to the bottom of the stack
void pushatbottom(stack<int> &s, int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    int temp = s.top();
    s.pop();
    pushatbottom(s, val);
    s.push(temp);
}

void reverseStack(stack<int> &s){
    if(s.size() == 0){
        return;
    }
    int temp = s.top();
    s.pop();
    reverseStack(s);
    pushatbottom(s,temp); //while backtraking we are push the temp element on the bottom so that the sack is reversed
}
int main(){
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);

    reverseStack(s);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}