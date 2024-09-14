#include<iostream>
using namespace std;
int main(){
int a[8]={2,3,7,14,19,23,56,78};
int b[10]={1,5,8,20,24,34,44,58,79,90};
int c[18];
int i=0,j=0;
for(int k=0;k< 18;k++){
 if(i<8 && j<10){
  if(b[j]<a[i]){
   c[k]=b[j];
   j++;
  }
  else{
   c[k]=a[i];
   i++;

  }
 }
 else{
   if(i==8){
    c[k]=b[j];
    j++;
   }
   else{
    c[k]=a[i];
    i++;
   }
 }
}
for(int k=0;k<18;k++){
    cout<<c[k]<<" ";
}

}
