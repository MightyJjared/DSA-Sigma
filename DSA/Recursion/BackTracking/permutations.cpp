#include <iostream>
#include <string>
using namespace std;

// explanation for this is understand print_subsets code and watch video of mam

void permutation(string str, string ans){
    int n = str.size();
    if(str.size() == 0){
        cout << ans << endl;
        return;
    }
    for(int i =0; i< str.size();i++){
    
    char ch = str[i];

    string nextstr = str.substr(0,i) + str.substr(i+1,n-i-1);

    permutation(nextstr, ans+ch);
    }
    

}
int main(){
    string str = "12345";
    string ans = "";
    permutation(str, ans);
    return 0;
}