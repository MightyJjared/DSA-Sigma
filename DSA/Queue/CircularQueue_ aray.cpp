#include <iostream>
using namespace std;

// We are implenting a circular queue using array
// Approach - sinc array size is limited we will use two pointers frontindex and rear tot rak first and last element
// of the array whenever we push we will first move rear to the next index and at that index we will place our 
// elemetn at that index and front will track the frst element in our queue, it does not neet to be index 0 it is 
// changing everytime.
class Queue{
    int *arr;
    int frontIndex;
    int rearIndex;
    int totalsize;
    int currentsize;
    public:
    Queue(int totalsize){
        this-> totalsize = totalsize;
        arr = new int[totalsize]; //assigning our array its size from main
        currentsize = 0;
        frontIndex = 0; // first index
        rearIndex = -1; // before 1 index
    }

    void push(int data){
        if(currentsize == totalsize){
            cout << "Queue is full\n";
            return;
        }
        rearIndex = (rearIndex + 1) % totalsize; // instead of using rear++ we are using this, it will help when rear is
        // at the last index and we want to push the next element to 0 index 
        arr[rearIndex] = data;
        currentsize++;
    }

    void pop(){
        if(isempty()){
            cout << "Queue is empty\n";
            return;
        }
        frontIndex = (frontIndex + 1) % totalsize;
        currentsize--;
    }

    int front(){
        if(isempty()){
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[frontIndex];
    }
    bool isempty(){
        if(currentsize == 0){
            return true;
        }
        else{
            return false;
        }
    }

    int last(){if(isempty()){
        cout << "Queue is empty\n";
        return -1;
    }
        return arr[rearIndex];
    }
};
int main(){
    Queue q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << q.front() << endl;
    q.push(5);
    q.pop();
    cout << q.front() << endl;
    cout << q.last() << endl;

    q.push(5);
    cout << q.last() << endl;

    return 0;
}