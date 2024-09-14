#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
bool res;
int n,m;
string word;
int vis[100][100];
vector<vector<char>> block;
bool isValid(int x,int y,int index){
    if(x<0 || x>n || y<0 || y>m)return false;
    if(vis[x][y]==1 || block[x][y]!= word[index]) return false;
    return true;
}
void f(int x, int y, int index){
    vis[x][y]=1;
    if(index==word.size()-1){
        vis[x][y]=0;
        res=true;
        return;
    }
    if(isValid(x-1,y,index+1)) f(x-1,y,index+1);
    if(isValid(x+1,y,index+1)) f(x+1,y,index+1);
    if(isValid(x,y-1,index+1)) f(x,y-1,index+1);
    if(isValid(x,y+1,index+1)) f(x,y+1,index+1);
    vis[x][y]=0;
    return;
}
bool present(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(block[i][j]==word[0]){
                f(i,j,0);
                if(res){
                    return res;
                }
            }
        }
    }
    return res;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
            vector<char> b;
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            b.push_back(c);
        }
        block.push_back(b);
    }
    cin>> word;
    cout<<present();
}
