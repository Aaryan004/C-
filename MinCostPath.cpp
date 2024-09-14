#include <iostream>
using namespace std;
int minCostPathDP(int **input, int m,int n,int **output){
    output[m-1][n-1]=input[m-1][n-1];

    for(int j=n-2;j>=0;j--){
        output[m-1][j]=output[m-1][j+1] +input[m-1][j];
    }
    for(int i=m-2;i>=0;i--){
        output[i][n-1]=output[i+1][n-1] +input[i][n-1];
    }
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            output[i][j]=min(output[i][j+1],min(output[i+1][j],output[i+1][j+1])) + input[i][j];
        }
    }
    return output[0][0];

}
int minCostPath_Memoization(int **input,int i,int j,int n,int m,int **output){
    if(i==n || j==m) return INT_MAX;

    if(i==n-1 && j==m-1) return input[i][j];

    if(output[i][j]!=-1) return output[i][j];

    int x=minCostPath_Memoization(input,i,j+1,n,m,output);
    int y=minCostPath_Memoization(input,i+1,j,n,m,output);
    int z=minCostPath_Memoization(input,i+1,j+1,n,m,output);

    int ans=input[i][j]+min(x,min(y,z));

    output[i][j]=ans;

    return ans;
}
int minCostPath(int **input,int i,int j,int n,int m){
    if(i==n || j==m) return INT_MAX;

    if(i==n-1 && j==m-1) return input[i][j];

    int x=minCostPath(input,i,j+1,n,m);
    int y=minCostPath(input,i+1,j,n,m);
    int z=minCostPath(input,i+1,j+1,n,m);

    int ans=input[i][j]+min(x,min(y,z));

    return ans;
}
int main(){
    int n,m;
    cout<<"Enter the dimensions: "<<endl;
    cin>>n>>m;
    int **input=new int*[n];
    int **output=new int*[n];
    for(int i=0;i<n;i++){
        input[i]=new int[m];
        output[i]=new int[m];
        for(int j=0;j<m;j++){
            output[i][j]=0;
            cin>>input[i][j];
        }
    }
    cout<<minCostPathDP(input,n,m,output);
}
