#include <iostream>
#include <string>
using namespace std;

/*
Question = Create a user class with properties : id (private), username (public), and password (private).
its id should be initialized  in a parameterized constructor.
It should have a getter and setter for password.
*/

class User{
    private:
    int id;
    string password;

    public:
    string username;

    User(int id){
        this-> id = id;
    }
    // setter
    void setpassword(string password){
        this-> password = password;
    }
    // getter
    string getpassword(){
        return password;
    }
};

int main(){
    User user1(2486);
    user1.username = "AbdullahMunaz";
    user1.setpassword("sdtga");
    
    cout << "Username: " << user1.username << endl;
    cout << "Password: " << user1.getpassword() << endl;
}