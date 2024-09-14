#include <climits>
class StackUsingArray{
private:
    int* data;
    int nextIndex;
    int capacity;
public:
    StackUsingArray(){
    data=new int[4];
    nextIndex=0;
    capacity=4;
    }

    bool isEmpty(){
    return nextIndex==0;
    }

    int Size(){
    return nextIndex;
    }

    void push(int element){
    if(nextIndex==capacity){
        int* data1=new int[2*capacity];
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

    int pop(){
    if(isEmpty()){
        cout<<"Stack is Empty"<<endl;
        return INT_MIN;
    }
    nextIndex--;
    return data[nextIndex];
    }

    int top(){
    if(isEmpty()){
    cout<<"Stack is Empty"<<endl;
    return INT_MIN;
    }
    return data[nextIndex-1];
    }

};
