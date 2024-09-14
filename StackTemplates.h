template <typename T>
#include <climits>
class StackUsingTemplates{
private:
    T* data;
    int nextIndex;
    int capacity;
public:
    StackUsingTemplates(){
    data=new T[4];
    nextIndex=0;
    capacity=4;
    }

    bool isEmpty(){
    return nextIndex==0;
    }

    int Size(){
    return nextIndex;
    }

    void push(T element){
    if(nextIndex==capacity){
        T* data1=new T[2*capacity];
        for(int i=0;i<capacity;i++){
            data1[i]=data[i];
        }
        capacity*=2;
        delete [] data;
        data=data1;
        delete data1;
    }
    data[nextIndex]=element;
    nextIndex++;
    }

    T pop(){
    if(isEmpty()){
        cout<<"Stack is Empty"<<endl;
        return 0;
    }
    nextIndex--;
    return data[nextIndex];
    }

    T top(){
    if(isEmpty()){
    cout<<"Stack is Empty"<<endl;
    return 0;
    }
    return data[nextIndex-1];
    }

};
