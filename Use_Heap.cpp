#include <iostream>
using namespace std;
#include "PriorityQueue.h"
void heapify(int arr[],int n,int parentIndex){
    int leftIndex=2*parentIndex+1;
    int rightIndex=2*parentIndex+2;
    int minIndex=parentIndex;

    if(leftIndex<n && arr[leftIndex] < arr[minIndex]){
        minIndex=leftIndex;
    }
    if(rightIndex<n && arr[rightIndex] < arr[minIndex]){
        minIndex=rightIndex;
    }

    if(minIndex!=parentIndex){
        swap(arr[minIndex],arr[parentIndex]);
        heapify(arr,n,minIndex);
    }

    return;
}
void heapSort(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }

    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
int main(){
    int maxHeap[10]={1,2,3,4,5,6,7,8,9,10};
    heapSort(maxHeap,10);
    for(int i=0;i<10;i++){
        cout<<maxHeap[i]<<" ";
    }
    /*int minHeap[10]={10,9,8,7,6,5,4,3,2,1};
    heapSort(minHeap,10);
    for(int i=0;i<10;i++){
        cout<<minHeap[i]<<" ";
    }*/
/*PriorityQueue* p=new PriorityQueue();
p->insertpq(100);
p->insertpq(10);
p->insertpq(15);
p->insertpq(4);
p->insertpq(17);
p->insertpq(21);
p->insertpq(67);

cout<<p->getSize()<<endl;
cout<<p->getMin()<<endl;

while(!p->isEmpty()){
    cout<<p->removeMin()<<" ";
}
cout<<endl;*/
}
