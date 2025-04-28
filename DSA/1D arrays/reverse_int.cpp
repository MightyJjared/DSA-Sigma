#include <iostream>
using namespace std;


int revint(int x){
    int rem = 0;
    int ans = 0; 
    while(x>0){
        rem = x%10;
        x = x/10;
        ans = ans * 10 + rem;
    }
    return ans;
}
int main(){
    cout << revint(563) << endl;
    return 0;
}