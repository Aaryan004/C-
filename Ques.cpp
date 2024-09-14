#include <iostream>
#include <cstring>
using namespace std;
void replacePi(char input[]) {
	int n=strlen(input);
	if(n==0){
		return;
	}
	else{
        if(input[0]=='p' && input[1]=='i'){
			input[0]='1';
			input[1]='4';
			for(int i=n;i>0;i--){
              input[i]=input[i-1];
			}
			n=n+1;
			for(int i=n;i>0;i--){
              input[i]=input[i-1];
			}
			n=n+1;
			input[n]='\0';
			input[0]='3';
			input[1]='.';
		}
		replacePi(input+1);
	}
}
int main(){
char arr[10]={'k','p','i','j','l','8','7','p','i','\0'};
replacePi(arr);
for(int i=0;i<10;i++){
    cout<<arr[i]<<" ";
}
}
