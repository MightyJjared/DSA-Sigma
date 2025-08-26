#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
   Problem:
   --------
   Given two strings s and t, check if they are anagrams of each other.
   Two strings are anagrams if they contain the same characters with the same frequencies,
   but possibly in a different order. 
   Example: "race" and "care" are anagrams, but "hello" and "world" are not.

   Approach:
   ---------
   1. Create an unordered_map (hashmap) to store character frequencies from string s.
   2. Traverse s: for each character, increment its count in the map.
   3. Traverse t: for each character, decrement its count in the map.
      - If a character in t is not found in the map, return false immediately.
      - If a character’s frequency becomes zero, erase it from the map to keep the map clean.
   4. After processing both strings, if the map is empty, it means every character matched perfectly,
      so s and t are anagrams. Otherwise, they are not.

   Time Complexity: O(n)   [where n = length of strings]
   Space Complexity: O(1)  [at most 26 keys for lowercase letters, or bounded by charset size]
*/

bool valid_anagram(string s, string t){
    unordered_map<char, int> m;
    for(int i =0; i < s.size(); i++){
        if(m.count(s[i]) == 1){
            m[s[i]]++;
        }
        else{
            m[s[i]] = 1;
        }
    }

    for(int i =0; i<t.size(); i++){
        if(m.count(t[i]) == 1){
            m[t[i]]--;
            if(m[t[i]] == 0){
                m.erase(t[i]);
            }
        }
        else{
            return false;
        }
    }
    if(m.size() != 0){
        return false;
    }
    return true;
}

int main(){
    string s = "race";
    string t = "care";
    
    cout << valid_anagram(s,t);
    cout << endl;
    return 0;
}
