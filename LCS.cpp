#include <iostream>
using namespace std;
int lcs_dp(string s, string t){
    int m=s.size();
    int n=t.size();
    int **output=new int*[m+1];
    for(int i=0;i<m+1;i++){
        output[i]=new int[n+1];
    }
    output[0][0]=0;
    for(int j=1;j<n+1;j++){
        output[0][j]=0;
    }
    for(int i=1;i<m+1;i++){
        output[i][0]=0;
    }
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(s[m-i]==t[n-j]){
                output[i][j]=1+output[i-1][j-1];
            }else{
                int a=output[i][j-1];
                int b=output[i-1][j];
                int c=output[i-1][j-1];
                output[i][j]=max(a,max(b,c));
            }
        }
    }
    return output[m][n];
}
int lcs_memoization(string s,string t,int **output){
    int m=s.size();
    int n=t.size();
    int ans;
    if(s.size()==0 || t.size()==0){
        return 0;
    }

    if(output[m][n]!=-1){
        return output[m][n];
    }
    //Recursive calls
    if(s[0]==t[0]){
        ans=1+lcs_memoization(s.substr(1),t.substr(1),output);
    }else{
        int a=lcs_memoization(s.substr(1),t,output);
        int b=lcs_memoization(s,t.substr(1),output);
        ans=max(a,b);
    }
    output[m][n]=ans;
    return ans;
}
int lcs(string s,string t){
    //Base
    if(s.size()==0 || t.size()==0){
        return 0;
    }
    //Recursive calls
    if(s[0]==t[0]){
        return 1+lcs(s.substr(1),t.substr(1));
    }else{
        int a=lcs(s.substr(1),t);
        int b=lcs(s,t.substr(1));
        //This case can already be solved when s[1] is removed and then t[1] is removed
        //int c=lcs(s.substr(1),t.substr(1));
        return max(a,b);
    }
}
int main(){
    string s,t;
    cin>>s>>t;
    int m=s.size()+1;
    int n=t.size()+1;
    int **output=new int*[m+1];
    for(int i=0;i<m+1;i++){
        output[i]=new int[n];
        for(int j=0;j<n;j++){
            output[i][j]=-1;
        }
    }
    cout<<lcs(s,t)<<endl;
    cout<<lcs_dp(s,t)<<endl;
}
