#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
vector<int> v(5);
int a[]={1,2,3,4,5};
v.assign(a,a+5);
vector<int> :: iterator i=v.begin();
for(;i!=v.end();i++){
    cout<<*i<<" ";
}
cout<<endl;
cout<<v.front()<<" "<<v.back()<<endl;//First and Last element
/* when we print v[i] in a for loop or when we use iterator it will print till its capacity but .at() only prints till
 the size so used more in production time.*/
cout<<v.at(2)<<endl;
cout<<v.empty()<<endl;//Tells us if the vector is empty or not(True:1 False:0)
v.clear();//clears the vector and makes it empty and reduces vector size to 0
cout<<v.size()<<" "<<v.empty();
}
