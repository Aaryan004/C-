#include <iostream>
using namespace std;

#include "StackTemplates.h"
int main(){
StackUsingTemplates<char> a;
a.push(97);
a.push(98);
a.push(99);
a.push(100);
a.push(101);
cout<<a.Size()<<endl;
cout<<a.pop()<<endl;
cout<<a.pop()<<endl;
cout<<a.pop()<<endl;
cout<<a.pop()<<endl;
cout<<a.pop()<<endl;
return 0;
}
