#include <iostream>
#include <stack>
using namespace std;

// stack using library it can also be char , string etc
int main(){
    stack<int> s1;
    s1.push(3);
    s1.push(2);
    s1.push(1);

    while(!s1.empty()){
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;
    return 0;
}