#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void print(int **edges, int n,int sv,bool *visited){
    if(n==0) return;
    queue<int> vertices;
    cout<<sv<<" ";
    vertices.push(sv);
    visited[sv]=true;
    while(!vertices.empty()){
        int cv=vertices.front();
        vertices.pop();
        for(int i=0;i<n;i++){
        if(edges[cv][i]==1){
          if(!visited[i]) {
            cout<<i<<" ";
            vertices.push(i);
            visited[i]=true;
            }
            }
        }
    }
}
int main(){
    // Write your code here
    int v,e;
    cin>>v>>e;
    int **edges=new int*[v];
    for(int i=0;i<v;i++){
        edges[i]=new int[v];
        for(int j=0;j<v;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int sv,ev;
        cin>>sv>>ev;
        edges[sv][ev]=1;
        edges[ev][sv]=1;
    }
    bool *visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    if(v!=0 && e==0){
        for(int i=0;i<v;i++){
            print(edges,v,i,visited);
        }
    }else {
        print(edges,v, 0, visited);
    }
}
