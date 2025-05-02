#include <iostream>
#include <string>
using namespace std;

void substring(string str){
    int count = 0;
    int n = str.size();
    for(int i =0; i<n;i++){
        for(int j =i; j<n;j++){
            if(str[i] == str[j]){
                count ++;
            }
            //cout << " ";
        }
    }
    cout << count << endl;
}

int main(){
    string str = "aba";
    substring(str);
    return 0;
}