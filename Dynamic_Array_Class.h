using namespace std;
class DynamicArray{
int *data;
int nextIndex;
int capacity;

public:
    DynamicArray(int capacity){
    data=new int[capacity];
    nextIndex=0;
    this->capacity=capacity;
    }
    DynamicArray(DynamicArray const & d1){
    //this->data=d1.data; //Shallow Copy

    //Deep Copy
    this->data=new int[d1.capacity];
    for(int i=0;i<d1.nextIndex;i++){
     this->data=d1.data[i];
    }
    this->nextIndex=d1.nextIndex;
    this->capacity=d1.capacity;
    }
    void operator=(DynamicArray const & d1){
     this->data=new int[d1.capacity];
    for(int i=0;i<d1.nextIndex;i++){
     this->data=d1.data[i];
    }
    this->nextIndex=d1.nextIndex;
    this->capacity=d1.capacity;
    }
    void add(int element){
    if(nextIndex == capacity){
        int *newData=new int[2*capacity];
        int i;
        for(i=0;i<capacity;i++){
            newData[i]=data[i];
        }
        capacity*=2;
        delete [] data;
        data=newData;

    }
    data[nextIndex]=element;
    nextIndex++;

    }
    int get(int i)const{
    if(i<capacity){
    return data[i];
    }else{
    return -1;
    }
    }
    void add(int i,int element){
    if(i<nextIndex){
        data[i]=element;
    }
    else if(i == nextIndex){
        add(element);
    }
    else{
        return;
    }

    }
    void print()const {
    for(int i=0;i<nextIndex;i++){
    cout<<data[i]<<" ";
    }
    cout<<endl<<capacity<<" "<<&data<<endl;
    }

};
