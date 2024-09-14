#include <iostream>
using namespace std;
int fib_helper(int n, int* ans){
if(n<=1) return n;
if(ans[n]!=-1){
    return ans[n];
}
    ans[n]= fib_helper(n-1,ans)+fib_helper(n-2,ans);
    return ans[n];

}
//
int fib(int n){
int *ans=new int[n+1];
for(int i=0;i<=n;i++){
    ans[i]=-1;
}
return fib_helper(n,ans);
}
//Dynamic Programming
int fib2(int n){
int* ans=new int[n+1];
ans[0]=0;
ans[1]=1;
for(int i=2;i<=n;i++){
    ans[i]=ans[i-1]+ans[i-2];
}
return ans[n];
}
int main(){
cout<<fib2(400);
}
