#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class student{
    public:
    string name;
    int marks;

    student(string name, int marks){
        this->name = name;
        this->marks = marks;
    }

    bool operator < (const student &obj) const{
        return this->marks < obj.marks;//on line 17 and 18 we have '<' therefore it will be default therefore max heap
        // return this->marks < obj.marks; here it will be min heap
    }
    // operator< is overloaded here so that priority_queue knows how to compare two 'student' objects
    // This syntax means: when comparing two students, use their marks to decide order
};

int main(){
    priority_queue<student> pq;
    pq.push(student("abdullah", 85));
    pq.push(student("rayyan", 95));
    pq.push(student("khaled", 90));

    while(!pq.empty()){
        cout << "top = " << pq.top().name << ", " << pq.top().marks << endl;
        pq.pop();
    }
    return 0;
}
