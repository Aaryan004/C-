#include <iostream>
#include "Fraction.h"
using namespace std;
int main(){
Fraction f1(10,2);
Fraction f2(20,2);
Fraction f3=f1+f2;
f3.display();
Fraction f4=f1*f2;
f4.display();
cout<<(f4==f4)<<endl;
//Pre-Increment
++(++f4);
//Fraction f5= ++(++f4);//This will work just fine
f4.display();
//Post-Increment
Fraction f6=f4++;
f4.display();
f6.display();
//+= Operator
Fraction f7(3,1);
(f7+=f3)+=f3;
f7.display();
}
