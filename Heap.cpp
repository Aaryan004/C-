#include <iostream>
using namespace std;
class heap{
public:
    int arr[100];
    int size=0;
heap(){
    arr[0]=-1;
    size=0;
}
void insert(int val){
    size=size+1;
    int index=size;
    arr[index]=val;

    while(index>1){
        int parent=index/2;
        if(arr[parent]<arr[index]){
            swap(arr[parent],arr[index]);
            index=parent;
        }
        else{
            return;
        }
    }
}
void print(){
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void deletefromHeap(){
if(size==0){
    cout<<"Nothing to delete"<<endl;
    return;
}
//Replacing first element with last
arr[1]=arr[size];
//Deleting last element;
size--;

int i=1;
//Guiding last element to right position
while(i<=size){
        int l=2*i;
int r=2*i+1;
if(l<size && arr[i]<arr[l]){
    swap(arr[i],arr[l]);
    i=l;
}
else if(r<size && arr[i]<arr[r]){
swap(arr[i],arr[r]);
i=r;
}
else{
    return;
}
}
}
};
void heapify(int arr[],int n,int i){
int largest=i;
int l=2*i+1;
int r=2*i+2;
if(l<n && arr[largest]<arr[l]){
    largest=l;
}
if(r<n && arr[largest]<arr[r]){
    largest=r;
}
if(i!=largest){
    swap(arr[largest],arr[i]);
    heapify(arr,n,largest);
}
}
void heapsort(int arr[],int n){
int size=n;
while(size>1){
    //step1:
    swap(arr[1],arr[size]);

    //step2:
    size--;

    //step3:
    heapify(arr,size ,1);

}


}
int main(){
/*heap h;
h.insert(50);
h.insert(55);
h.insert(53);
h.insert(52);
h.insert(54);
h.print();
h.deletefromHeap();
h.print();*/
int prr[10]={50,51,52,53,54,55,56,57,58,59};
int n=10;//arr.size()-1 correct for l=2*i,r=2*i+1 ; for l=2*i+1, r=2*i+2 n=arr.size() in this case 8
/*
for(int i=n/2;i>=0;i--){
    heapify(prr,n,i);
}

//for min heap
for(int i=n/2-1;i>=0;i--){
    heapify(prr,n,i);
}
}*/
//heap creation
for(int i=n/2;i>=1;i--){
    heapify(prr,n,i);
}
//heapsort(prr,n);

for(int i=1;i<n;i++){
    cout<<prr[i]<<" ";
}
}
