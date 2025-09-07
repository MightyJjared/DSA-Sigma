#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

//here maxheap will be build based upon first data type of pair, ie in this case it is string
int main(){
    priority_queue<pair<string, int>> pq;
    pq.push(make_pair("abdullah", 85));
    pq.push(make_pair("rayyan", 95));
    pq.push(make_pair("khaled", 90));

    while(!pq.empty()){
        cout << "top = " << pq.top().first << ", " << pq.top().second << endl;
        pq.pop();
    }
    return 0;
}


// here min heap will build based on string because in struct we used '>' and first value of pair
// and also change on line 31 with passing container and struct name
// struct comparepair{
//     bool operator () (pair<string, int> &p1, pair<string, int> &p2){
//         return p1.first > p2.first;
//     }
// };

// int main(){
//     priority_queue<pair<string, int>, vector<pair<string, int>>, comparepair> pq;
//     pq.push(make_pair("abdullah", 85));
//     pq.push(make_pair("rayyan", 95));
//     pq.push(make_pair("khaled", 90));

//     while(!pq.empty()){
//         cout << "top = " << pq.top().first << ", " << pq.top().second << endl;
//         pq.pop();
//     }
//     return 0;
// }

// here max heap will be build based upon in value
// struct comparepair{
//     bool operator () (pair<string, int> &p1, pair<string, int> &p2){
//         return p1.second < p2.second;
//     }
// };

// int main(){
//     priority_queue<pair<string, int>> pq;
//     pq.push(make_pair("abdullah", 85));
//     pq.push(make_pair("rayyan", 95));
//     pq.push(make_pair("khaled", 90));

//     while(!pq.empty()){
//         cout << "top = " << pq.top().first << ", " << pq.top().second << endl;
//         pq.pop();
//     }
//     return 0;
// }

// here min heap will be implemented baaed on int value because we used '>' in compare pair
// and also added containr and struct name in line 72.
// struct comparepair{
//     bool operator () (pair<string, int> &p1, pair<string, int> &p2){
//         return p1.second > p2.second;
//     }
// };

// int main(){
//     priority_queue<pair<string, int>, vector<pair<string, int>>, comparepair> pq;
//     pq.push(make_pair("abdullah", 85));
//     pq.push(make_pair("rayyan", 95));
//     pq.push(make_pair("khaled", 90));

//     while(!pq.empty()){
//         cout << "top = " << pq.top().first << ", " << pq.top().second << endl;
//         pq.pop();
//     }
//     return 0;
// }