#include <iostream>
#include<string.h>
using namespace std;
/*int FirstIndex(int arr[],int n,int x){
if(n==0){
    return -1;
}
if(arr[0]==x){
    return 0;
}
int SmallArrayFirstIndex=FirstIndex(++arr,n-1,x);
if(SmallArrayFirstIndex==-1){
    return -1;
}
else{
    return SmallArrayFirstIndex+1;
}
}*/
bool checkPalindrome(char arr[],int n){
if(n==0 || n==1){
    return true;
}
if(arr[0]!=arr[n-1]){
    return false;
}
return checkPalindrome(++arr,n-2);
}

int main(){
  char arr[] ="abcbaf" ;
  cout<<checkPalindrome(arr,6)<<endl;
}
