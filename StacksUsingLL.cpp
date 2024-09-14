#include <iostream>
using namespace std;

#include "StacksUsingLL.h"

int main(){
Stacks<char> a;
a.push(97);
a.push(98);
cout<<a.top()<<endl;
a.push(99);
a.push(100);
a.push(101);
cout<<a.Size()<<endl;
cout<<a.isEmpty()<<endl;
cout<<a.pop()<<endl;
cout<<a.pop()<<endl;
cout<<a.pop()<<endl;
cout<<a.pop()<<endl;
cout<<a.pop()<<endl;
}
