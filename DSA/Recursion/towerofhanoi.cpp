#include <iostream>
#include <string>
using namespace std;

void towerofhanoi(int n, string source, string helper, string destination){
    if(n==1){
        cout << "Transfered disk " << n << " from " << source << " to " << destination << endl;
        return;
    }
    towerofhanoi(n-1, source, destination, helper);

    cout << "Transfered disk " << n << " from " << source << " to " << destination << endl;

    towerofhanoi(n-1, helper, source, destination);
}

int main(){
    int n = 3;
    string source = "source";
    string helper = "helper";
    string destination = "destination";
    towerofhanoi(n,source,helper,destination);
    return 0;
}