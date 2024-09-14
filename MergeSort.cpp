#include <iostream>
using namespace std;
void merge(int a[],int si,int ei){
    int mid=(si+ei)/2;
    int *temp=new int[ei-si+1];
    int i=si;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=ei){
        if(a[i]<=a[j]){
            temp[k]=a[i];
            i++;
            k++;
        }
        else{
            temp[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        temp[k]=a[i];
        i++;
        k++;
    }
    while(j<=ei){
        temp[k]=a[j];
        j++;
        k++;
    }
    int m=0;
    while(m<k){
        a[si+m]=temp[m];
        m++;
    }
  delete [] temp;
}
void mergeSort(int arr[], int l, int r) {
   int mid=(l+r)/2;
    if(l>=r){
        return;
    }
    mergeSort(arr, l, mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,r);
}
int main(){
int arr[10]={4,67,5,34,2,8,65,3,90,19};
mergeSort(arr,0,9);
for(int i=0;i<10;i++){
cout<<arr[i]<<" ";
}
}
