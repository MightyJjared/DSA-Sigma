#include <iostream>
using namespace std;

int main(){
    int n = 10;
    // upper diamond
    for(int i =0; i<n;i++){
        //external spaces
        for(int j =0; j<n-i-1; j++){
            cout << " ";
        }
        cout << "*";
        // internal spaces
        if(i != 0){
            for(int j=0;j<2*i-1;j++){
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;

    }
    // bottom diamond
    for(int i=0;i<n-1;i++){
        // external spaces
        for(int j =0;j<i+1;j++){
            cout << " ";
        }
        cout << "*";
        // internal spaces
        if(i!=n-2){
        for(int j =0;j<2*(n-i)-5;j++){
            cout << " ";
        }
        cout << "*";
    }
    cout << endl;
    }

    return 0;
}
