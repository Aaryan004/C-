#include <iostream>
using namespace std;
class Vehicle{
public:
    //Runtime Polymorphism
    virtual void print(){
        cout<<"Vehicle"<<endl;
    }
};
class Car:public Vehicle{
public:
    void print(){
        cout<<"Car"<<endl;
    }
};
class HondaCity: public Car{
public:
    void print(){
        cout<<"HondaCity"<<endl;
    }
};
int main(){
    Vehicle v;
    Car c;
    HondaCity h;
    //C.print();
    //V.print();
    Vehicle *v1=new Vehicle();
    Vehicle *v2;
    v2 = &h;
    v2->print();
}
