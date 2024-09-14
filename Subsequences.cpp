#include <iostream>
#include <string>
using namespace std;
int subsequences(string input, string* output){
    if(input.empty()){
        output[0]="";
        return 1;
    }
    string smallerString=input.substr(1);
    int n=subsequences(smallerString,output);
    for(int i=0;i<n;i++){
        output[i+n]=input[0]+output[i];
    }
    return 2*n;
}
int main(){
string input;
cin>>input;
string* output=new string[1000];
int n=subsequences(input,output);
for(int i=0;i<n;i++){
 cout<<output[i]<<endl;
}
}

