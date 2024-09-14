#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
int arr[5]={89,7,0,-34,-21};
//(L,R)->R is excluded
//L,L+1,....,R-1
//fill(arr,arr+5,9);
//sort(arr,arr+5);
//reverse(arr,arr+5);
//swap(arr[0],arr[3]);
//if function is to be gone from (L,R)
//then (arr+l,arr+R+1)
sort(arr+1,arr+3+1);
for(int i=0;i<5;i++){
    cout<<arr[i]<<" ";
}

}
