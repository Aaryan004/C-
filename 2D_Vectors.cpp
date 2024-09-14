#include <bits/stdc++.h>
using namespace std;
int main(){
int r,c;
cin>>r>>c;
// First Method
/*vector<int> vec[r];
for(int i=0;i<r;i++){
    vec[i].resize(c);
}*/
//Second Method
vector<vector<int>> vec(r);
for(int i=0;i<r;i++){
    vec.push_back(vector<int>(c));
}
//Third method
/*vector<vector<int>> vec(r,vector<int>(c));*/
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        cin>>vec[i][j];
    }
}
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        cout<<vec[i][j]<<" ";
    }
    cout<<endl;
}
}
