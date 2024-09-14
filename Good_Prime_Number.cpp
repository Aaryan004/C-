#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
bool isPrime(int n){
    if(n==1) return false;
    for(int i=2;i<n;i++){
        if(n%i==0) return false;
    }
    return true;
}
int sumOfDigits(int n){
    int ans=0;
    while(n>0){
        int remainder=n%10;
        ans+=remainder;
        n=n/10;
    }
    return ans;
}
int main(){
int n,k;
cin>>n>>k;
int i=n+1;
int ans;
while(k!=0){
    int digitSum=sumOfDigits(i);
    if(isPrime(digitSum)){
        ans=i;
        k--;
    }
    i++;
}
cout<<ans<<endl;
}
