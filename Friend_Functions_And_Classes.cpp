#include <iostream>
using namespace std;
class Bus{
public:
    string color="red";
    void print();
};
class Truck{
private:
    int x;
protected:
    int y;

//Access modifiers do not work for friend so can be written after any section(private, public or protected)
friend void Bus::print();
};
void Bus::print(){
    this->color="blue";
    Truck t;
    t.x=10;
    t.y=20;
    cout<<this->color<<" "<<t.x<<" "<<t.y<<endl;
}
int main(){
    Bus b;
    b.print();

}
