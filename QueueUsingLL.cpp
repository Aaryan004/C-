#include <iostream>
using namespace std;

#include "QueueUsingLL.h"

int main(){
QueueUsingLL<char> a;
a.enqueue(97);
a.enqueue(98);
a.enqueue(99);
a.enqueue(100);
a.enqueue(101);
a.enqueue(102);
cout<<a.top()<<endl;
cout<<a.Size()<<endl;
cout<<a.dequeue()<<endl;
cout<<a.dequeue()<<endl;
cout<<a.dequeue()<<endl;
cout<<a.dequeue()<<endl;
cout<<a.dequeue()<<endl;
cout<<a.dequeue()<<endl;
cout<<a.isEmpty()<<endl;
}
