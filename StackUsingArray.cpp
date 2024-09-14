#include <iostream>
using namespace std;

#include "StackUsingArray.h"

int main(){
StackUsingArray a;
a.push(10);
a.push(11);
cout<<a.Size()<<endl;
a.push(12);
a.push(13);
a.push(14);
cout<<a.top()<<endl;
a.push(15);
cout<<a.pop()<<endl;
cout<<a.pop()<<endl;
cout<<a.pop()<<endl;
cout<<a.pop()<<endl;
cout<<a.pop()<<endl;
cout<<a.pop()<<endl;
cout<<a.isEmpty()<<endl;
}
