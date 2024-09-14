#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
int ans;
void func(int i,int n){
    if(i==n-1 || i==n){
        ans++;
        return;
    }
    if(s[i]=='1'){
        func(i+2,n);
    }
    if(s[i]=='2' && s[i+1]<'7'){
        func(i+2,n);
    }
    func(i+1,n);
}
int main(){
    ans = 0;
    cin >> s;
    func(0, s.length());
    cout << ans;
}
