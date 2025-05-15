#include <iostream>
#include <string>
using namespace std;

// explanation for this is understand print_subsets code and watch video of mam
// if n =3 permutatons will be n!
void permutation(string str, string ans){
    int n = str.size();
    if(str.size() == 0){
        cout << ans << endl;
        return;
    }
    for(int i =0; i< str.size();i++){
    
    char ch = str[i];

    string nextstr = str.substr(0,i) + str.substr(i+1,n-i-1);

    permutation(nextstr, ans+ch);
    }
    

}
int main(){
    string str = "abc";
    string ans = "";
    permutation(str, ans);
    return 0;
}
/*

                              permutation("abc", "")
                              /        |         \
                            a/         b|          \c
                            /              |             \ 
          permutation("bc", "a")   permutation("ac", "b")   permutation("ab", "c")
               /         \              /         \              /         \
             b/           c\          a/           c\          a/           b\
             /              \         /              \         /              \
     per("c", "ab")  per("b", "ac") per("c", "ba")  per("a", "bc") per("b", "ca") per("a", "cb")
           |               |              |               |              |               |
   per("", "abc")  per("", "acb")  per("", "bac")  per("", "bca")  per("", "cab")  per("", "cba")*/
