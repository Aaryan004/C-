#include <iostream>
#include <stack>
using namespace std;
int main(){
stack<int> s1,s2;
s1.push(10);
s1.push(20);
s1.push(40);
s1.push(80);
s1.push(160);
s2=s1;
cout<<s2.top()<<endl;
cout<<s1.size()<<endl;

cout<<s1.top()<<endl;
s1.pop();
cout<<s1.top()<<endl;
s1.pop();
cout<<s1.top()<<endl;
s1.pop();
cout<<s1.top()<<endl;
s1.pop();
s1.empty();

}
