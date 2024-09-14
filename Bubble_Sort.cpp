#include <iostream>
using namespace std;
void Bubble_Sort(int arr[],int n){
for(int i=0;i<n;i++){
    for(int j=0;j<n-1-i;j++){
    if(arr[j]>arr[j+1]){
        int temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
   }
  }
 }
}
int main(){
int arr[10]={10,35,34,8,90,1,23,18,19,78};
int n=10;
Bubble_Sort(arr,n);
for(int i=0;i<10;i++){
    cout<<arr[i]<<" ";
}
}

