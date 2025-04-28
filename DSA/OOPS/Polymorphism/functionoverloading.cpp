#include <iostream>
#include <string>
using namespace std;

// Function Overloading
// depending on the parameter weather it is string or int the method which have same names will be called.
// function overloading comes under compile time polymorphism
class Print{
    public:
    void show(int x){
        cout << "int: " << x << endl;
    }
    void show(string str){
        cout << "string: " << str << endl;
    }
};

int main(){
    Print p1;
    p1.show(25);
    p1.show("AbdullahMunz");
    return 0;
}