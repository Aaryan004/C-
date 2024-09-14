#include <string.h>
using namespace std;
class Student{
private:
    int age;
public:
    char* name;
    Student(int age,char* name){
    this->age=age;
    //Shallow copy,this->name has the address of the name argument so any change in original copy will reflect in this one
    //this->name=name;

    //Deep copy copies the array in heap so neither memory is expanded nor changes in original array affect it
    this->name=new char[strlen(name)+1];//+1 for null character
    strcpy(this->name,name);
    }
    //Our Own Copy Constructor
   Student(Student const & s){
    this->age=s.age;
    //this->name=s.name; Shallow Copy

    this->name=new char[strlen(s.name)+1];
    strcpy(this->name,s.name);
    }

    void display(){
    cout<<age<<" "<<name<<endl;
    }
};
