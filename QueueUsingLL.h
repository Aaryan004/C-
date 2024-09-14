template <typename T>
class Node{
public:
    T data;
    Node<T>* next;
    Node(T data){
    this->data=data;
    next=nullptr;
    }
};

template <typename T>
class QueueUsingLL{
private:
    Node<T>* head;
    Node<T>* tail;
    int queuesize;
public:
    QueueUsingLL(){
    head=nullptr;
    tail=nullptr;
    queuesize=0;
    }
    void enqueue(T element){
    Node<T>* temp=new Node<T>(element);
    if(head==nullptr){
        head=temp;
        tail=temp;
        head->next=nullptr;
    }else if(head->next==nullptr){
    tail=temp;
    head->next=tail;
    }else{
    tail->next=temp;
    tail=temp;
    }
    queuesize++;
    }
    T dequeue(){
    if(queuesize==0){
        return -1;
    }
    Node<T>* temp=head;
    head=head->next;
    T x=temp->data;
    queuesize--;
    delete temp;
    return x;
    }
    T top(){
    if(queuesize==0){
            return -1;
    }
    return head->data;
    }
    int Size(){
    return queuesize;
    }
    bool isEmpty(){
    return queuesize==0;
    }
};
