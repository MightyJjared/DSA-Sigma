#include <iostream>
using namespace std;

int SumofDigit(int num){
    int sum = 0;
    while(num > 0){
        int lastdigit = num % 10;
        num /= 10;
        sum += lastdigit;
    }
    return sum;
}
int main(){
    cout << "Sum = " << SumofDigit(245) << endl;
    return 0;
}