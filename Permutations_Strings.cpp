#include <iostream>
#include <string>
using namespace std;
int returnPermutations(string input, string output[]){
	if(input.length()==1){
		output[0]=input[0];
		return 1;
	}
	string smallerInput=input.substr(1);
	string firstLetter=input.substr(0,1);
	int n=returnPermutations(smallerInput, output);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			output[j+(i+1)*n]=output[j];
		}
	}
	int k=0;
	for(int i=0;i<n+1;i++){
		for(int j=0;j<n;j++){
			output[k]=output[k].substr(0,i)+firstLetter+output[k].substr(i);
            k++;
        }
	}
	return n*(n+1);
}
int main(){
string a;
cin>>a;
string output[1000];
int l=returnPermutations(a,output);
for(int i=0;i<l;i++){
    cout<<output[i]<<endl;
}
}
