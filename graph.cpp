#include <iostream>
using namespace std;
void print(int **edges,int n,int sv,bool *visited){
cout<<sv<<endl;
visited[sv]=true;
//edges[sv][i] means it will go in DEPTH for the node and only then move on to the next one so it is DEPTH FIRST SEARCH
for(int i=0;i<n;i++){
    if (i==sv){
        continue;
    }
    if(edges[sv][i]==1){
        if(visited[i]) continue;
        print(edges,n,i,visited);
    }
}
}
int main(){
int n,e;
cin>>n>>e;
int** edges=new int*[n];
for(int i=0;i<n;i++){
    edges[i]=new int[n];
    for(int j=0;j<n;j++){
        edges[i][j]=0;
    }
}
int sv,ev;
for(int i=0;i<e;i++){
    cin>>sv>>ev;
    edges[sv][ev]=1;
    edges[ev][sv]=1;
}
bool *visited=new bool[n];
for(int i=0;i<n;i++){
    visited[i]=false;
}
print(edges,n,0,visited);
delete []visited;
for(int i=0;i<n;i++){
    delete [] edges[i];
}
delete [] edges;
}
