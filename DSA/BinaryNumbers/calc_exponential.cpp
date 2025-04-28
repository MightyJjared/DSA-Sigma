#include <iostream>
using namespace std;

// bitwise problem, here we are calculating x^n orexample - 3^5 = 243;
void calc_exponential(int x, int n){
    int ans = 1;
    while(n>0){
        int lastbit = n & 1;
        if(lastbit == 1){
            ans = ans * x;
            x = x*x;
        }
        else if(lastbit == 0){
            x = x*x;
        }
       n = n >> 1;
    }
    cout << ans << endl;
}
int main(){
    int x = 3;
    int n = 5;
    calc_exponential(x,n);
    return 0;
}