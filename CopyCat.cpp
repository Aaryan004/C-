#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
string s,s1;
int n;
int func(){
    if(n<=1) return 0;
    int ans=0,c=0;
    sort(s.begin(),s.end());
    for(int i=0;i<n;i++)
        if(s1[i]!=s[i]) c++;
    ans=max(ans,c);
    c=0;
    while(next_permutation(s.begin(),s.end())){
        for(int i=0;i<n;i++)
            if(s1[i]!=s[i]) c++;
        ans=max(ans,c);
        c=0;
    }
    return ans;
}
int main(){
int t;
cin>>t;
while(t--){
    cin>>s;
    s1=s;
    n=s.size();
    cout<<func()<<endl;
    }
return 0;
}
