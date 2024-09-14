using namespace std;
class Fraction{
private:
    int numerator;
    int denominator;
public:
    Fraction(){
    }
    Fraction(int numerator,int denominator){
    this->numerator=numerator;
    this->denominator=denominator;
    }
    //Does not change any attribute so declared constant (mind the position of keyword const)
    void display() const{
    cout<<"Fraction is: "<<this->numerator<<"/"<<this->denominator<<endl;
    }
    int getNumerator() const{
    return numerator;
    }
    int getDenominator() const{
    return denominator;
    }
    void simplify(){
    int gcd=1;
    int n=min(this->numerator,this->denominator);
    int i;
    for(i=1;i<=n;i++){
        if(this->numerator%i==0 && this->denominator%i==0){
            gcd=i;
        }
    }
    this->numerator=this->numerator/gcd;
    this->denominator=this->denominator/gcd;
    }
    //&f2 lets us make a pass by reference and const makes sure we cannot change the value of original f2.
    void add(Fraction const &f2){
    int lcm=denominator*f2.denominator;
    int numerator_sum=(f2.denominator*numerator)+(denominator*f2.numerator);
    numerator=numerator_sum;
    denominator=lcm;
    simplify();
    }
    Fraction operator+ (Fraction const &f2){
    int lcm=denominator*f2.denominator;
    int numerator_sum=(f2.denominator*numerator)+(denominator*f2.numerator);
    Fraction fNew(numerator_sum,lcm);
    fNew.simplify();
    return fNew;
    }
    void multiply(Fraction const &f2){
    this->numerator=this->numerator*f2.numerator;
    this->denominator=this->denominator*f2.denominator;
    simplify();
    }
     Fraction operator*(Fraction const &f2){
    int numerator_sum=this->numerator*f2.numerator;
    int denominator_sum=this->denominator*f2.denominator;
    Fraction fNew(numerator_sum,denominator_sum);
    fNew.simplify();
    return fNew;
    }
    bool operator== (Fraction const& f2){
    return(numerator==f2.numerator && denominator==f2.denominator);
    }
    //Pre-increment
    Fraction& operator++(){
    this->numerator=numerator+denominator;
    simplify();
    return *this;//this has address of the object so derefferring it will lead you to the object
    }
    //Post-Increment
    Fraction operator++(int){
    Fraction fNew(numerator,denominator);
    this->numerator=numerator+denominator;
    fNew.simplify();
    simplify();
    return fNew;//this has address of the object so derefferring it will lead you to the object
    }
    Fraction& operator+=(Fraction const &j){
    *this=*this+j;
    return *this;
    }
};
