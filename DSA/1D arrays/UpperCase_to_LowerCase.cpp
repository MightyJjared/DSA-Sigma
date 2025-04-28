#include <iostream>
#include <cstring>
using namespace std;
void UpperCase(char word[], int size){
    for(int i =0; i<size;i++){
        char ch = word[i];
        if(ch >= 'A' && ch <= 'Z'){
            continue;
        }
        else{
            int pos = ch - 'a';
            word[i ]= pos + 'A';
        }
    }
}

void LowerCase(char word[], int size){
    for(int i =0; i<size;i++){
        char ch = word[i];
        if(ch >= 'a' && ch <= 'z'){
            continue;
        }
        else{
            int pos = ch - 'A';
            word[i ]= pos + 'a';
        }
    }
}

int main(){
    char word[] = "heLlo";
    int size = strlen(word);
    UpperCase(word, size);
    cout << word << endl;
    LowerCase(word, size);
    cout << word << endl;

    return 0;
}