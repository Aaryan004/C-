#include <iostream>
#include <cstring>
using namespace std;
void reverse_String(char arr[],int n){
int i=0;
int j=n-1;
while(i<j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
    i++;
    j--;
}
}
int main(){
char arr[100];
cin.getline(arr,100);
int n=strlen(arr);
reverse_String(arr,n);
cout<<arr;
}
