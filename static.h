class Student{
private:
    static int totalStudents;
public:
    int age;
    int roll_Number;
    //static int totalStudents; // declaring static data member
    Student(){
    totalStudents++;
    }
    static int getTotalStudents(){
    return totalStudents;
    }
};
int Student::totalStudents=0;//Initialize static data member
