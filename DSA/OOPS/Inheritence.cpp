#include <iostream>
#include <string>
using namespace std;

// Basic syntax of inheritance
class Animal{
    public:
    string colour;

    void eat(){
        cout << "Eats.\n";
    }
    void breathes(){
        cout << "Breathes.\n";
    }
};

class Fish : public Animal {
    public:
    int fins;

    void swim(){
        cout << "swims.\n";
    }
};

int main(){
    Fish f1;
    f1.fins = 3;
    cout << f1.fins << endl;
    f1.swim();
    f1.breathes();
    f1.colour = "blue";
    cout << f1.colour << endl;
}

// there are 3 modes of inheritance
//  public, private , protected
// where protected means it is private but can be accessed in in derived classes.