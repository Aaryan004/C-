#include <iostream>
#include "Student.h"
using namespace std;
int main(){
//Statically Created
Student s1;
s1.rollNumber=1013;
cout<<s1.rollNumber<<endl;
//The public properties can access the private properties of same class
s1.display();//But the age printed will be a garbage value
cout<<s1.getAge()<<endl;// This function returns age but it is still a garbage value
//Now that we have setAge we can do
s1.setAge(17);
s1.display();

//Dynamically Created
Student *s2=new Student;
//(*s2).age=20;
//cout<<(*s2).age<<endl;
s2 ->rollNumber=1014;
s2->setAge(78);
s2->display();

}
