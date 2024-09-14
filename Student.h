using namespace std;
class Student{
private:
    int age;
public:
    //Default Constructor
    Student(){
    cout<<"Default Constructor Called"<<endl;
    cout<<"this: "<<this<<endl;
    }
    //Parametrized Constructor
    Student(int r){
    cout<<"Constructor 2 called"<<endl;
    cout<<"this: "<<this<<endl;
    rollNumber=r;
    }
    Student(int a,int r){
    cout<<"Constructor 3 called"<<endl;
    cout<<"this: "<<this<<endl;
    rollNumber=r;
    age=a;
    }
    ~Student(){
    cout<<"Destructor Called"<<endl;
    }
    int rollNumber;
    void display(){
    cout<<age<<" "<<rollNumber<<endl;;
    }
    int getAge(){
    return age;
    }
    void setAge(int a){
        if(a<1){
            return;
        }
    age=a;
    }

};


