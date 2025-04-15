#include <iostream>
#include <cstring>
using namespace std;

void reverse(char word[], int size){
    int start = 0;
    int end = size-1;
    while(start < end){
        swap(word[start], word[end]);
        start++;
        end--;
    }
}
int main(){
    char word[] = "afifa";
    int size = strlen(word);
    reverse(word, size);
    cout << word << endl;
    return 0;
}