#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> remove_Duplicates(int arr[],int n){
    unordered_map<int,bool> seen;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(seen.count(arr[i])>0){
            continue;
        }else{
            seen[arr[i]]=true;
            ans.push_back(arr[i]);
        }
    }
    return ans;
}
int main(){
    int arr[]={1,1,2,2,2,3,3,3,6,6,6,5,5,5,4,4,4};
    vector<int> ans=remove_Duplicates(arr,17);
    for(int i=0;i<ans.size();i++){
        cout<<ans.at(i)<<" ";
    }
}
