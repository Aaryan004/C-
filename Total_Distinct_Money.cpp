#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
int n, m, t;
int ans=0, sum=0;
unordered_map <int,int> mm;
bool valid(int x, int y){
    if(x==n || y==m) return false;
    return true;
}
void answer(int i, int j, int num, vector<vector <int>> a2){
    if(i==n-1 && j==m-1){
        if(mm.count(num)==0){
            sum+=num;
            ans++;
            mm[num]=num;
        }
        return;
    }
    if(valid(i+1,j)) answer(i+1,j,num+a2[i][j],a2);
    if(valid(i,j+1)) answer(i,j+1,num+a2[i][j],a2);
    return;

}
int main() {
    cin >> n >> m;
    vector < vector < int >> arr(n, vector < int > (m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    a = arr;
    answer(0, 0, 0, a);
    cout << ans << endl << sum;
}
