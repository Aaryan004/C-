#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int blockSize[100];
int processSize[100];
int nblocks,nprocesses;
void Solve(){
    unordered_map<int,int> umap;
    for(int i=0;i<n;i++){
        cout<<"Process"<<i+1<<"\t";
        bool found=false;
        for(int j=0;j<nblocks;j++){
            if(blockSize[j]>processSize[i]){
                if(umap.count(j)==0){
                    cout<<j+1<<endl;
                    umap[j]=j;
                    found=true;
                    break;
                  }
                }
            }
            if(!found) cout<<"Not allocated"<<endl;
        }
}
int main(){
    cout<<"Enter the number of blocks: ";
    cin>>nblocks;
    cout<<endl;
    cout<<"Enter the number of processes: ";
    cin>>nprocesses;
    cout<<endl;
    for(int i=0;i<nblocks;i++){
        cout<<"Enter memory space for block "<<i+1<<" : ";
        cin>>blockSize[i];
        cout<<endl;
    }
    for(int i=0;i<nprocesses;i++){
        cout<<"Enter memory needed for process "<<i+1<<" : ";
        cin>>processSize[i];
        cout<<endl;
    }
    Solve();
}
