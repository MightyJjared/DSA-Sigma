#include <iostream>
#include <string>
using namespace std;

// explanation for this is present in notes

void printsubsets(string str, string ans){
    if(str.size() == 0){
        cout << ans << endl;
        return;
    }
    char ch = str[0];

    // yes choice
    printsubsets(str.substr(1,str.size()-1), ans+ch); // here the second parameter in substr is not till the 
    //ith number but its the lenght


    // no choice
    printsubsets(str.substr(1,str.size()-1), ans);

}
int main(){
    string str = "abc";
    string ans = "";
    printsubsets(str, ans);
    return 0;
}