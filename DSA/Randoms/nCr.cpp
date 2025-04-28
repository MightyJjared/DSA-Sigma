#include <iostream>
using namespace std;

int calc_factorial(int k){
    int fact = 1;
    for(int i=1;i<=k;i++){
        fact *= i;
    }
    return fact;
}
int calc_ncr(int n, int r){
    int numerator =calc_factorial(n);
    int denominator =calc_factorial(r);
    int nmr =calc_factorial(n-r);
    return numerator / (denominator*nmr);
        
}
int main(){
    cout << "Binomial coefficient = " << calc_ncr(8,2) << endl;
return 0;
}