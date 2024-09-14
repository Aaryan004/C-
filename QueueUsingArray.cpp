#include <iostream>
using namespace std;
#include "QueueUsingArray.h"
int main(){
QueueUsingArray<int> a(5);
a.enqueue(10);
a.enqueue(20);
a.enqueue(30);
a.enqueue(40);
a.enqueue(50);
a.enqueue(90);
cout<<a.Size()<<endl;
cout<<a.top()<<endl;
cout<<a.dequeue()<<endl;
cout<<a.dequeue()<<endl;
cout<<a.dequeue()<<endl;
cout<<a.dequeue()<<endl;
a.enqueue(30);
a.enqueue(60);
cout<<a.dequeue()<<endl;
cout<<a.dequeue()<<endl;
cout<<a.dequeue()<<endl;

}
