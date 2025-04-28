#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &vec, int start,int end,int mid){
    vector<int> temp;
    int i =start, j = mid+1;
    while(i<=mid && j<=end){
        if(vec[i]< vec[j]){
            temp.push_back(vec[i]);
            i++;
        }
        else{
            temp.push_back(vec[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(vec[i]);
            i++;
    }
    while(j<=end){
        temp.push_back(vec[j]);
            j++;
    }
    for(int idx =0;idx<temp.size();idx++){
        vec[idx+start] = temp[idx];
    }
}


void mergersort(vector<int> &vec, int start,int end){
    if(start< end){
        int mid = start + (end-start)/2;
        mergersort(vec,start,mid);
        mergersort(vec,mid+1,end);

        merge(vec,start,end,mid);
    }
}


int main(){
    vector<int> vec = {6,1,8,3,9,23};
    int start =0;
    int end = vec.size()-1;
    mergersort(vec, start, end);
    for(int i =0; i<vec.size();i++){
        cout<< vec[i] << " ";
    }
    cout << endl;
    return 0;
}