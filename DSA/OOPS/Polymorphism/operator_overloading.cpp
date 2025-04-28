#include <iostream>
#include <string>
using namespace std;
/*
class Complex{
    int real;
    int imaginary;
    public:
    Complex(int r, int i){
        real = r;
        imaginary = i;
    }

    void ShowNumber(){
        cout << real << " + " << imaginary << "i\n";
    }
};
int main(){
    Complex c1(1,2);
    Complex c2(3,4);

    c1.ShowNumber();
    c2.ShowNumber();
    return 0;
}*/


class Complex{
    int real;
    int imaginary;
    public:
    Complex(int r, int i){
        real = r;
        imaginary = i;
    }

    void ShowNumber(){
        cout << real << " + " << imaginary << "i\n";
    }
    // operator overloading syntax
    void operator + (Complex &c2){
        int resultReal = this->real + c2.real;
        int resultimaginary = this->imaginary + c2.imaginary;
        Complex c3(resultReal, resultimaginary);
        c3.ShowNumber();
    }
};
int main(){
    Complex c1(1,2);
    Complex c2(3,4);

    c1.ShowNumber();
    c2.ShowNumber();
    return 0;
}