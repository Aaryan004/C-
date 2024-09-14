#include <iostream>
using namespace std;
#include <unordered_map>

int main(){
unordered_map<int,int> ourMap;
pair<int,int> a(1,7);
ourMap.insert(a);
cout<<ourMap.at(1)<<endl;
ourMap[1]=2;
cout<<ourMap.at(1)<<endl;
//cout<<ourMap.at(2)<<endl;
cout<<ourMap[2]<<endl;
cout<<ourMap.size()<<endl;
//pair<int,int> b(1,8);
//ourMap.insert(b);
ourMap.erase(2);
cout<<ourMap.size()<<endl;
cout<<ourMap.count(1)<<endl;
if(ourMap.count(2)>0){
    cout<<ourMap.at(2)<<endl;
}else{
    cout<<"The element is not here"<<endl;
}
}
