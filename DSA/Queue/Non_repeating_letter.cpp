#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// in this we are giving an ans vector back which is the output , which includes the first non repeating index at 
// till each index, so for example in the output in 0 index we have a which is the first non repeating elemtn 
// from the str string till 0 index, likewise in 3 index of output we have b which is the first non non repeating 
// elemtn in the str string til 3 index, so there fore the last index in ans is x which is overall the first non 
// repeating index inthe whole str string.
// # indicates that we do not have any first non repeating element 
void non_repeating(string str, vector<char> &ans){
    queue<char> q;
    int freq[26] = {0};
    for(int i =0; i< str.size(); i++){
        char ch = str[i];
        q.push(ch);
        freq[ch- 'a']++;
        while(!q.empty() && freq[q.front() - 'a'] > 1){
            q.pop();
        }
        if(q.size() == 0){
            ans.push_back('#');
        }
        else{
            ans.push_back(q.front());
        }
    }

    for(int i =0; i< ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
    string str = "aabccxb";
    vector<char> ans;
    non_repeating(str, ans);
    return 0;
}