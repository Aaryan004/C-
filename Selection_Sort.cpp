#include <iostream>
using namespace std;
void Selection_Sort(int arr[],int n){
int start=0;
int end=n-1;
while(start<end){
int k=start;
int smallest=arr[start];
for(int j=start+1;j<n;j++){
  if(smallest>arr[j]){
   smallest=arr[j];
   k=j;
  }
}
int temp=arr[start];
arr[start]=smallest;
arr[k]=temp;
start++;
}
}
int main(){
int arr[]={18,78,98,106,24,15,133,13,14,63,73,46};
Selection_Sort(arr,12);
for(int i=0;i<12;i++){
cout<<arr[i]<<" ";
}
}

