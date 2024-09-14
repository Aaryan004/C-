#include <iostream>
using namespace std;
int main(){
//In a character array
//char a[4]={'a','b','c','\0'};
string a="abc";
cout<<a<<endl;
string * sp=new string;
*sp="Aaryan";
cout<<*sp<<endl;
cout<<sp<<endl;
string b;
getline(cin,b);
b[0]='s';
b += b;
cout<<b<<endl;
cout<<b.size()<<" "<<b.length()<<endl;
cout<<b.substr(3)<<endl;
cout<<b.substr(3,3)<<endl;
cout<<b.find("gO");

}
