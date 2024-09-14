#include <iostream>
using namespace std;
//Abstract Class
class Vehicle{
public:
    string color;
    //Pure Virtual Functions
    virtual void print()=0;
};
class Car:public Vehicle{
public:
    void print(){
        cout<<"Car"<<endl;
    }
};
int main(){
    Car c;
    c.print();
}
