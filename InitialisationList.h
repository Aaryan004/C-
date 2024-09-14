using namespace std;
class Student{
public :
    int age;
    const int rollNumber;
    int &j;

    Student(int age,int rollNumber):age(age),rollNumber(rollNumber),j(this->age){
    }

    void display(){
    cout<<age<<endl;
    cout<<rollNumber<<endl;
    cout<<j<<endl;
    }


};
