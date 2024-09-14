#include <iostream>
using namespace std;
int partitionArray(int input[], int start, int end) {
	// Write your code here
	int x=input[start];
	int countSmallerElements=0;
	for(int i=start+1;i<=end;i++){
		if(input[i]<=x){
			countSmallerElements++;
		}
	}
	int y=start+countSmallerElements;
	int temp=input[y];
	input[y]=x;
	input[start]=temp;

	int i=start;
	int j=end;
	while(i<y && j>y){
		 if(input[i]>input[y] && input[y]>input[j] ){
		 temp=input[i];
		 input[i]=input[j];
		 input[j]=temp;
		 i++;
		 j--;
		 }
		 else if(input[i]>input[y] && input[j]>input[y]){
		 	j--;
		 }
		 else if(input[y]>input[i] && input[y]>input[j]){
          i++;
		}
	}
	return start+countSmallerElements;
}
void quickSort(int input[], int start, int end){
	if(start>=end)
	{
		return ;
	}
	int pi=partitionArray(input,start,end);
	quickSort(input, start, pi-1);
	quickSort(input, pi+1, end);
}
int main(){
int arr[10]={4,67,5,34,2,8,65,3,90,19};
quickSort(arr,0,9);
for(int i=0;i<10;i++){
cout<<arr[i]<<" ";
}
}
