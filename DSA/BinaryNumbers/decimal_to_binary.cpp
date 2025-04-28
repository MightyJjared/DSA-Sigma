#include <iostream>
using namespace std;

int DecToBin(int DecNum){
int ans =0;
int rem = 0;
int power = 1;
while(DecNum > 0){
    rem = DecNum % 2;
    DecNum = DecNum / 2;
    ans += (rem * power);
    power *= 10;
}
    return ans;

}

int BinToDec(int BinNum){
    int ans =0;
    int power = 1;
    while (BinNum > 0){
        int rem = BinNum % 10;
        BinNum = BinNum/10;
        ans += (rem * power);
        power *= 2;
    }
return ans;
}
int main(){
    int DecNum = 60;
    cout << "Binary form of "<< DecNum << " is : "<< DecToBin(DecNum) << endl;
    cout << BinToDec(110010) << endl;

    return 0;
}