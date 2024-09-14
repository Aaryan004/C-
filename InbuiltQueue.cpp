#include <iostream>
using namespace std;
#include <queue>
int main(){
queue<int> a;
a.push(10);
a.push(20);
a.push(30);
a.push(40);
a.push(50);
a.push(60);
cout<<a.size()<<endl;
while(!a.empty()){
    cout<<a.front()<<endl;
    a.pop();
}
}
