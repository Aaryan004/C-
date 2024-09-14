#include <bits/stdc++.h>
using namespace std;
//a>b the bigger one will be kept first
//a<b the smaller one will be kept first
bool comp(pair<int,int> a,pair<int,int>b){
return a.second<b.second;
}
int main(){
//Three ways to declare a pair
//pair<int,int> t=make_pair(3,2);
//pair<int,int> t={3,2};
//pair<int, int> t(3,2);
//cout<<t.first<<" "<<t.second;
//How to access pair in vectors
vector<pair<int,int>> t;
t.push_back({0,2});
t.push_back({3,4});
t.push_back({8,9});
t.push_back({3,1});
//cout<<t.at(2).first<<endl;
sort(t.begin(),t.end(),comp);
vector<pair<int,int>>::iterator it=t.begin();
for(;it!=t.end();it++){
    cout<<(*it).first<<" "<<(*it).second<<endl;
}
}
