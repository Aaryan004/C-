#include <iostream>
#include "Student.h"
using namespace std;
int main(){

//Copy Assignment Operator and Destructors
Student s1(18,1829);
Student s2(56,5629);
Student s3;
Student *s4=new Student(79,7929);
s2=(*s4);
s2.display();
s2=s1;
s2.display();
s3=s1;
s3.display();
(*s4)=s1;
s4->display();
delete s4;

/*
COPY CONSTRUCTOR
Student s1(10,1034);
s1.display();

Student s2(s1);
s2.display();

Student *s3=new Student(67,1098);
Student *s4=new Student(*s3);
s4->display();

Student s5(*s3);
s5.display();

Student *s6=new Student(s1);
s6->display();*/

}
