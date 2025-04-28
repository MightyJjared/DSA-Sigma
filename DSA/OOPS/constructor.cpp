#include <iostream>
#include <string>
using namespace std;
/*
// Constructor= there are 3 types of constructors
   (1) non parameterized constructor (created by default).
   (2) parameterized constructor
   (3) Copy constructor
class Car{
    string name;
    string colour;

    public:
    // Constructor, it has same class name.
    Car(){
        cout << "Constructor is called.\n";
    }

    void start(){
        cout << "Car started.\n";
    }
    void stop(){
        cout << "Car stopped.\n";
    }
};

int main(){
    Car c1;
    return 0;
}*/
/*
// More on constructors like accessing propeties ie name and color which are private from constructors.
class Car{
    string name;
    string colour;

    public:
    // Constructor, it has same class name.
    Car(string nameval, string namecolour){
        cout << "Constructor is called.\n";
        name = nameval;
        colour = namecolour;
    }

    string getname(){
        return name;
    }
};

int main(){
    Car c1("Maruti Suzuki", "Black");
    cout << "Car name: " << c1.getname() << endl;
    return 0;
}*/

// Now we want to perform same operation from above but for parameters of constructor we want to pass
// same name and colour spelling as defined in propeties ie string name, string colour, so syntax is as follows.
/*
class Car{
    string name;
    string colour;

    public:
    // Constructor, it has same class name.
    Car(){
        cout << "constructor without parameter.\n";
    }
    Car(string name, string colour){
        cout << "Constructor with parameter.\n";
        this -> name = name;
        this -> colour = colour;
        // we can also write this
       // *this.name = name;
    }

    string getname(){
        return name;
    }
};

int main(){
    Car c0;
    Car c1("Maruti Suzuki", "Black");
    cout << "Car name: " << c1.getname() << endl;
    return 0;
}*/
/*
// Copy Constructor
class Car{
    public:
    string name;
    string colour;

    Car(string name, string colour){
        this -> name = name;
        this -> colour = colour;
    }  
};

int main(){
    Car c1("Maruti Suzuki", "Black");
    Car c2(c1);
    cout << "Car name: " << c2.name << endl;
    cout << "Car colour: " << c2.colour << endl;

    return 0;
}*/

// we can also make custom copy constructor
class Car{
    public:
    string name;
    string colour;

    Car(string name, string colour){
        this -> name = name;
        this -> colour = colour;
    }  
    Car(Car &original){
        cout << "Copying original to new...\n";
        name = original.name;
        colour = original.colour;
    }
};

int main(){
    Car c1("Maruti Suzuki", "Black");
    Car c2(c1);
    cout << "Car name: " << c2.name << endl;
    cout << "Car colour: " << c2.colour << endl;

    return 0;
}