#include <stdio.h>
int arr[100];
int size=0;
void insert(int val){
size=size+1;
int index=size;
arr[index]=val;
while(index>1){
int parent= index/2;
if(arr[parent]<arr[index]){
int temp=arr[parent];
arr[parent]=arr[index];
arr[index]=temp;
}
index=parent;
}
}
void print_heap(int prr[],int n){
for(int i=0;i<n;i++){
printf("%d ",prr[i]);
}
printf("\n");
}
void heapify(int prr[],int n,int i){
    int smallest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(prr[l] < prr[i] && l<n){
        smallest=l;
    }
    if(prr[r]<prr[i] && r<n){
        smallest=r;
    }
    if(i != smallest){
        int temp=prr[i];
        prr[i]=prr[smallest];
        prr[smallest]=temp;
        heapify(arr,n,smallest);
    }
}
void heapsort(int prr[], int n){
int size=n;
while(size>0){
    int temp=arr[1];
    arr[1]=arr[n];
    arr[n]=temp;

    size--;

    heapify(prr,n,1);
}


}
int main(){
/*insert(50);
insert(55);
insert(53);
insert(52);
insert(54);
print_heap();
//insert(50);*/
int prr[10]={54,53,52,51,50,59,58,57,56,55};
int n=10;
for(int i=n/2;i>=0;i--){
    heapify(prr,n,i);
}
heapsort(prr,n);//Remember for heapsort you need to make a min heap first
for(int i=0; i<n; i++){
    printf("%d ",prr[i]);
}
}
