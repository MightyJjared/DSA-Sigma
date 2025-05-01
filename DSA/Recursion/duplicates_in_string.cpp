#include <iostream>
#include <string>
using namespace std;

void duplicate(string sh, int n, int i, string ans, int arr[]){
    if(i==n){
        cout << ans << endl;
        return;
    }
    int ch = sh[i] - 97;
    if(arr[ch] == false){
        arr[ch] = true;
        duplicate(sh,n,i+1,ans + sh[i],arr);
    }
    else{
        duplicate(sh,n,i+1,ans,arr);
    }


}
int main(){
    string sh = "apnacollege";
    int n = sh.size();
    string ans = "";
    int arr[26] = {false};
    duplicate(sh, n, 0,ans,arr);
    return 0;
}