#include <iostream>
using namespace std;
#include <queue>
int main(){
    priority_queue<int> pq;

    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);
    pq.push(6);

    cout<<pq.size()<<endl;

    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
}
