#include <iostream>
#include <string>
using namespace std;

bool print(string str,int i,int y){
    if(i>y){
        return true;
    }
    if(str[i] != str[y]){
        return false;
    }
    return print(str,i+1,y-1);
    //return true;
}
int main(){
    string str = "munazzanum";
    if(print(str,0,str.length()-1)){
        cout << "It is a palindrome." << endl;
    }
    else{
        cout << "Not a palindrome." << endl;
    }
    return 0;
}