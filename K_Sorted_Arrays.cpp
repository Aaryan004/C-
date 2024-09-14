#include <iostream>
using namespace std;
#include <queue>
void kSortedArrays(int arr[],int n,int k){
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    int j=0;
    for(int i=k;i<n;i++){
        arr[j]=pq.top();
        pq.pop();
        pq.push(arr[i]);
        j++;
    }

    while(!pq.empty()){
        arr[j]=pq.top();
        pq.pop();
        j++;
    }
    //Same as
    /*for(int i=0;i<k;i++){
        arr[j]=pq.top();
        pq.pop();
        j++;
    }*/
}
int main(){
    int arr[5]={12,7,5,9,4};
    kSortedArrays(arr,5,3);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }

}
