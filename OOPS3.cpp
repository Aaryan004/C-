#include <iostream>
using namespace std;
class Vehicle{
private:
    int maxSpeed;
protected:
    int numTyres;
public:
    string color;
    Vehicle(){
    cout<<"Vehicle Constructor Called"<<endl;
    }
    Vehicle(int n){
    cout<<"Vehicle Parametrized Constructor Called "<<n<<endl;
    }

    ~Vehicle(){
    cout<<"Vehicle Destructor Called"<<endl;
    }
    void print(){
    cout<<"Vehicle"<<endl;
    }
};
class Car:virtual public Vehicle{
public:
    int numGears;
    Car():Vehicle(3){
    cout<<"Car Constructor Called"<<endl;
    }
    Car(int x,int y):Vehicle(x){
    cout<<"Car Parametrized Constructor Called"<<endl;
    }
    ~Car(){
    cout<<"Car Destructor Called"<<endl;
    }
    void print(){
    cout<<"NumTyres: "<<numTyres<<endl;
    cout<<"Color: "<<color<<endl;
    cout<<"NumGears: "<<numGears<<endl;
    }

};
class Truck: virtual public Vehicle{
public:
    Truck():Vehicle(4){
        cout<<"Truck constructor called"<<endl;
    }
    ~Truck(){
    cout<<"Truck Destructor Called"<<endl;
    }
};
class Bus: public Car,public Truck{
public:
    Bus():Vehicle(5){
        cout<<"Bus's Constructor called"<<endl;
    }
    ~Bus(){
    cout<<"Bus Destructor Called"<<endl;
    }
    void print(){
        cout<<"Bus"<<endl;
    }
};
int main(){
Bus b;
//b.Car::print();
/*Vehicle v1;
  v1.color="red";
Car c1;
    c1.color="blue";
*/
}
