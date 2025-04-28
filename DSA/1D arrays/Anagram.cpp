#include <iostream>
#include <string>
using namespace std;

bool ValidAnagram(string str1, string str2){
    if(str1.length() != str2.length()){
        cout << "Not a valid anagram" << endl;
        return false;
    }
    int frequency[26] = {0};
    for(int i =0;i<str1.length(); i++){
        int idx = str1[i] - 'a';
        frequency[idx]++;
    }
    for(int i =0; i<str2.length(); i++){
        int idx = str2[i] - 'a';
        if(frequency[idx] == 0){
            cout << "Not a valid anagram" << endl;
            return false;
        }
        frequency[idx]--;
    }
    cout << "The given words are valid anagrams." << endl;
    return true;

}

int main(){
    string str1 = "anagram";
    string str2 ="nagaram";
    ValidAnagram(str1, str2);
    return 0;
}