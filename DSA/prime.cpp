#include <iostream>
using namespace std;

void Prime(int n){
    for(int num=2;num<=n;num++){
        bool isPrime = true;
        for(int i =2;i*i<=num;i++){
            if(num%i == 0){
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            cout << num << " ";
        }
    }
    cout << endl;
}

int main(){
    int n = 21;
    cout << "Prime numbers are : ";
    Prime(n);
    return 0;
}