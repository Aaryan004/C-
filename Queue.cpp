#include <stdio.h>
using namespace std;
int rear=9;
int fron=-1;
Q_display(int Q[],int N){
    for(int i=0;i<N;i++){
        printf("%d ",Q[i]);
    }
    printf("\n");
}
Q_insert(int Q[],int N,int item){
   if(rear==N-1){
    printf("Overflow \n");
   }
   else if(rear==-1){
    rear==0;
    fron==0;
    Q[rear]=item;
   }
   else{
    Q[rear]=item;
    rear+=1;
   }

}
Q_delete(int Q[]){
   int temp;
   if(fron==-1){
    printf("Underflow \n");
   }
   else if(fron==rear){
    temp=Q[fron];
    rear==-1;
    fron==-1;
   }
   else{
    temp=Q[fron];
    fron+=1;
   }
   printf("Element deleted: %d",temp);

}
int main(){
    int arr[10]={13,56,78,89,90,76,54,57,62,33};
    int N=10;
    int rear=-1,fron=-1;
    int item=101;
    Q_insert(arr,N,item);
    Q_display(arr,N);
    Q_delete(arr);
    Q_display(arr,N);

}
