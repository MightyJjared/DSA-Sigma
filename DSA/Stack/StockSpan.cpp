#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    vector<int> prices = {100,40,80,90,90,60,100};
    vector<int> ans(prices.size(), 0);
    stack<int> s;

    for(int i =0; i< prices.size(); i++){
        while(s.size() > 0 && prices[s.top()] <= prices[i]){
            s.pop();
        }
        if(s.size() == 0){
            ans[i] = i +1;
        }
        else{
            ans[i] = i - s.top();
        }
        s.push(i);
    }

    for(int val : ans){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}