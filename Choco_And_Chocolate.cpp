#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
unordered_map<char,int> umap;
void solve(string chocolates, string prices, int index, int length, int money, int & ans){
    if(index==length) return;
    int count=0;
    int amount=money;
    for(int i=index;amount>0;i++){
        amount-=umap[chocolates[i]];
        count++;
    }
    ans=max(ans,count);
    solve(chocolates,prices,index+1,length,money,ans);
}
int main(){
int n,m;
cin>>n>>m;
string chocolates,prices;
cin>>chocolates;
cin>> prices;
char j='a';
for(int i=0;i<prices.size();i++){
    umap[j]=stoi(prices.substr(i,1));
    j++;
}
int ans=0;
solve(chocolates,prices,0,n,m,ans);
cout<<ans;
}
