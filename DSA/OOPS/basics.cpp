#include <iostream>
#include <string>
using namespace std;

// basic syntax to initialize and also here name cannot be called from any other function because it is private.
// class Student{
//     private:
//     string name;
//     public:
//     float cgpa;
//     void getPercentage(){
//         cout << (cgpa * 10) << "%\n";
//     }
// };

// int main(){
//     Student s1;
//     cout << sizeof(s1) << endl;
//     s1.cgpa = 10;
//     s1.getPercentage();
//     return 0;
// }

//getter and setter - We can access private entities.
class Student{
    private:
    string name;
    float cgpa;
    public:
    //Setter
    void setname(string nameval){
        name = nameval;
    }
    void setcgpa(float cgpaval){
        cgpa = cgpaval;
    }

    //Getter
    string getname(){
        return name;
    }
    float getcgpa(){
        return cgpa;
    }
    
};

int main(){
    Student s1;
    s1.setname("Abdullah");
    s1.setcgpa(9.8);
    cout << s1.getname() << endl;
    cout << s1.getcgpa() << endl;
    return 0;
}




