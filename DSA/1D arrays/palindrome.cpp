#include <iostream>
#include <cstring>
using namespace std;

void palindrome(char word[], int size){
    int start = 0;
    int end = size-1;
    bool ispalindrome = true;
    while(start < end){
        if(word[start] == word[end]){
            start++;
            end--;
            continue;
        }
        else{
            ispalindrome = false;
            break;
        }
    }
    if (ispalindrome){
        cout << "The given word is a palindrome. " << endl;
    }else{
        cout << "The given word is not a palindrome." << endl;
    }
}
int main(){
    char word[100];
    cout << "Enter a sentence: ";
    cin >> word;
    int size = strlen(word);
    palindrome(word, size);
    return 0;
}