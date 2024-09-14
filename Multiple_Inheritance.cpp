#include <iostream>
using namespace std;
class Teacher{
public:
    string name;
    string age;

    void print(){
        cout<<"Teacher"<<endl;
    }
};
class Student{
public:
    void print(){
        cout<<"Student"<<endl;
    }
};
class TA: public Teacher, public Student{

};
int main(){
TA a;
a.Student::print();
}
