#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
vector<int> v(5,5);
/*for(int i=0;i<v.size();i++){
    cin>>v[i];
}*/
cout<<v.size()<<" "<<v.capacity()<<endl;
v.push_back(7);
/*cout<<v.size()<<" "<<v.capacity()<<endl;
v.push_back(8);
v.push_back(9);
v.push_back(10);
v.push_back(11);
cout<<v.size()<<" "<<v.capacity()<<endl;*/
//When the v.push_back() is called more than the assigned size of the vector the size shown increases by one but the v.capacity() which was initially at
//5 is now increased to 10. If this is filled again the v.capacity() will then increase to 20. So everytime it 2x the capacity but shows the size according
//to the pusback function calls.

/*for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
}*/
}
