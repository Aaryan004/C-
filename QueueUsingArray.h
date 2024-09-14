template <typename T>
class QueueUsingArray{
private:
    T* arr;
    int firstIndex;
    int nextIndex;
    int queuesize;
    int capacity;
public:
    QueueUsingArray(T n){
    arr=new T[n];
    nextIndex=0;
    firstIndex=-1;
    queuesize=0;
    capacity=n;
    }
    bool isEmpty(){
    return queuesize==0;
    }
    T top(){
        if(queuesize==0){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return arr[firstIndex];
    }
    T Size(){
    return queuesize;
    }
    void enqueue(T element){
    if(queuesize==capacity){
        T* newData=new T[capacity*2];
        int j=0;
        for(int i=firstIndex;i<capacity;i++){
            newData[j]=arr[i];
            j++;
        }
        for(int i=0;i<firstIndex;i++){
            newData[j]=arr[i];
            j++;
        }
        delete [] arr;
        arr=newData;
        delete newData;
        firstIndex=0;
        nextIndex=capacity;
        capacity*=2;

    }
    arr[nextIndex]=element;
    if(firstIndex==-1){
        firstIndex=0;
    }
    nextIndex=(nextIndex+1)%capacity;
    queuesize++;
    }
    T dequeue(){
    if(firstIndex==-1){
        cout<<"Queue is Empty"<<endl;
        return -1;
    }
    T x=arr[firstIndex];
    firstIndex=(firstIndex+1)%capacity;
    queuesize--;
    if(queuesize==0){
        firstIndex=-1;
        nextIndex=0;
    }
    return x;
    }
};
