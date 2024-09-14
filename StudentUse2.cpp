#include <iostream>
#include "Student2.h"
using namespace std;
int main(){
char name[]="abcd";
Student s1(23,name);
s1.display();

Student s2(s1);
s2.name[0]='x';
s2.display();
s1.display();

/* For Shallow and Deep Copy
char name[]="abcd";
Student s1(23,name);
s1.display();

name[3]='e';
Student s2(25,name);
s2.display();

s1.display();*/
}
