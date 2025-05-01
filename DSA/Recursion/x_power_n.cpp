#include <iostream>
using namespace std;

int power(int x, int n){
    if(n==0){
        return 1;
    }
    int halfpower = power(x,n/2);
    int halfpower_square = halfpower*halfpower;
    if(n%2 != 0){
        return x * halfpower_square;
    }
    return halfpower_square;
}
int main(){
    cout << power(2,10) << endl;
    return 0;
}
/*Easy example for 2^10:
First call: power(2,10)

Solve power(2,5)

Solve power(2,2)

Solve power(2,1)

Solve power(2,0) → returns 1

power(2,1) → multiply: 2 * (1 * 1) = 2

power(2,2) → square: 2 * 2 = 4

power(2,5) → odd, so: 2 * (4 * 4) = 32

power(2,10) → even, so: 32 * 32 = 1024*/