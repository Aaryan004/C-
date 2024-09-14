#include <iostream>
using namespace std;

#include "Templates.h"

int main(){
Pair<Pair<int,int>,int> t1;
Pair<int,int> t2;
t2.setx(3);
t2.sety(4);
t1.setx(t2);//The x part is a pair so it will only input pairs
t1.sety(5);
cout<<t1.getx().getx()<<endl;
cout<<t1.getx().gety()<<endl;
cout<<t1.gety()<<endl;
/*Pair<int,double> a;
a.setx(10);
a.sety(20.24);
cout<<a.getx()<<" "<<a.gety()<<endl;
*/
}
