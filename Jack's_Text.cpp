#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
int main(){
unordered_map<string,bool> umap;
string s,ans;
getline(cin,s);
int start=0,end;
int n=s.size();
for(int i=0;i<n;i++){
    if(s[i]==' ' || i==n-1){
            string sub;
            if(i!=n-1) sub=s.substr(start,i-start);
            else sub=s.substr(start,i-start+1);
        if(umap.count(sub)==0){
            umap[sub]=true;
            ans+=sub;
            ans+=" ";
        }
        start=i+1;
    }
}
cout<<ans;
}
