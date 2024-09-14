#include <iostream>
using namespace std;
int ls(char str[]){
if(str[0]=='\0'){
    return 0;
}
else{
    return 1+ls(++str);
}
}
void remove_character(char str[],char ch){
if(str[0]=='\0'){
    return ;
}
if(str[0]==ch){
    int i=1;
    for(;str[i]!='\0';i++){
        str[i-1]=str[i];
    }
    str[i-1]=str[i];
    remove_character(str,ch);
}
else{
    remove_character(++str,ch);
}
}
int main(){
char str[100];
cin>>str;
//int length=ls(str);
remove_character(str,'x');
cout<<str<<endl;

}
