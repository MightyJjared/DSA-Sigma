#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    vector<vector<int>> stones = {
    {0, 0},
    {0, 1},
    {1, 0},
    {1, 2},
    {2, 1},
    {2, 2}
};
    cout << stones[0][1] << endl;
    return 0;
}