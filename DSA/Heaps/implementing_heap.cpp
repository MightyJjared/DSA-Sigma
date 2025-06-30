#include <iostream>
#include <vector>
using namespace std;

// implementing heap using vector
class Heap{
    private:
    vector<int> vec;

    void heapify(int parent){
        if(parent >= vec.size()){
            return;
        }
        int left_child = (2*parent) + 1;
        int right_child = (2*parent) + 2; 
        int max = parent;

        if(left_child < vec.size() && vec[left_child] > vec[max]){
            max = left_child;
        }
        if(right_child < vec.size() && vec[right_child] > vec[max]){
            max = right_child;
        }

        swap(vec[max], vec[parent]);

        if(max != parent){ // Swapping happend with either child not with parent case
            heapify(max);
        }
    }

    public:

    void push(int x){ //O(logn)
        // 1 step insert
        vec.push_back(x); // O(1)

        // 2 step fix // O(logn)
        int child = vec.size()-1;
        int parent = (child-1)/2;
        while(parent >= 0 && vec[child] > vec[parent]){
            swap(vec[child], vec[parent]);
            child = parent;
            parent = (child-1)/2;
        }
    }

    void pop(){ // O(logn)
        // we will return 0 index element as top

        // 1 step - Swapping the top or 0 index element with the last index element or last node in the tree
        swap(vec[0], vec[vec.size()-1]); //O(1)

        // 2 step - Popping the last index elemnt
        vec.pop_back(); // O(1)

        // 3 step - fixing the heap, since the order changed
        heapify(0); // O(logn)
    }

    int top(){ //O(1)
        return vec[0];
    }

    bool empty(){
        return vec.size() == 0;
    }

};

int main(){
    Heap heap1;
    heap1.push(6);
    heap1.push(3);
    heap1.push(9);
    heap1.push(8);

    while(!heap1.empty()){
        cout << "top = " << heap1.top() << endl;
        heap1.pop();
    }
    return 0;
}