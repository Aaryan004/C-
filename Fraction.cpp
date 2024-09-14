#include <iostream>
#include "Fraction.h"
using namespace std;
int main(){
Fraction f1(10,3);
Fraction f2(15,4);
f1.multiply(f2);
f1.display();

//constant objects can only use constant functions
Fraction const f3=f2;
//Will print the same value as f2
f3.display();
Fraction const f5;
//Will show some garbage value
f5.display();

}
