#include<iostream>
#include<string.h>
using namespace std;
/*substring making
int main(){
string t="Hello";
cout<<t.substr(0,2);
}*/
void arraypointer(int* a){
a=a+1;
cout<<a<<endl;
//for(int i=0;i<sizearray;i++){
  //  cout<<*(a+i)<<" ";
//}
}
int main(){
//int a[10]={3,4,5,8,9,90,40,30,43,71};
int a=10;
cout<<a<<endl;
arraypointer(&a);
cout<<a<<endl;
}
