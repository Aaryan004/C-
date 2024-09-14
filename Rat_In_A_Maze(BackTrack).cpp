#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int vis[100][100];
int cell[100][100];
int n;
bool isValid(int x,int y){
    if(x==n || y==n || y==-1 || x==-1) return false;
    if(cell[x][y]==0 || vis[x][y]==1) return false;
    return true;
}
void printSol(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<vis[i][j]<<" ";
        }
    }
    cout<<endl;
}
void f(int x, int y){
    vis[x][y]=1;
    if(x==n-1 && y==n-1){
        printSol();
        vis[x][y]=0;
        return;
    }
    if(isValid(x,y-1)) f(x,y-1);
    if(isValid(x,y+1)) f(x,y+1);
    if(isValid(x-1,y)) f(x-1,y);
    if(isValid(x+1,y)) f(x+1,y);
    vis[x][y]=0;
    return;
}
int main(){
cin>>n;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>cell[i][j];
    }
}
f(0,0);
}
