#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int alloc[100][100];
int maxNeeded[100][100];
int avail[100];
int proc,res;
bool dealloc(int a){
for(int j=0;j<res;j++){
    if(alloc[a][j]+avail[j]<maxNeeded[a][j]) return false;
}
return true;
}
void printTable(){
    for(int i=0;i<proc;i++){
        cout<<"Process "<<i<<"\t";
        for(int j=0;j<res;j++){
            cout<<alloc[i][j]<<" ";
        }
        cout<<"\t";
        for(int j=0;j<res;j++){
            cout<<maxNeeded[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Available of each type: ";
    for(int j=0;j<res;j++){
        cout<<avail[j]<<" ";
    }
    cout<<endl;
}
void Solve(){
unordered_map<int,int> umap;
int num=0;
while(num!=proc){
    for(int i=0;i<proc;i++){
        if(umap.count(i)==0){
            if(dealloc(i)){
                for(int j=0;j<res;j++){
                    avail[j]+=alloc[i][j];
                    alloc[i][j]=0;
                }
                printTable();
                umap[i]=i;
            }
        }
    }
}
}
int main(){
cout<<"Enter the number of processes: ";
cin>>proc;
cout<<endl;

cout<<"Enter the number of different resources used by the processes";
cin>>res;
cout<<endl;

for(int i=0;i<proc;i++){
    cout<<"Enter the allocated resources for Process "<<i<<endl;
    for(int j=0;j<res;j++){
        cin>>alloc[i][j];
    }
}
for(int i=0;i<proc;i++){
    cout<<"Enter the resources needed for Process "<<i<<endl;
    for(int j=0;j<res;j++){
        cin>>maxNeeded[i][j];
    }
}
cout<<"Enter the resources available for each type: "<<endl;
for(int i=0;i<res;i++){
    cin>>avail[i];
}
Solve();
}
