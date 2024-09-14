#include <iostream>
#include "Student.h"
using namespace std;
int main(){
Student s1;
cout<<"Address of s1: "<<&s1<<endl;
s1.display();

Student s2(1013);
cout<<"Address of s2: "<<&s2<<endl;
s2.display();

Student *s3=new Student(45,1208);
cout<<"Address of s3: "<<&s3<<endl;
s3->display();

}
