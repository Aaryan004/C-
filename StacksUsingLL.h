template <typename V>
class Node{
public:
    V data;
    Node<V> *next;
    Node<V>(V element){
    data=element;
    next=nullptr;
    }
};
template <typename T>
class Stacks{
private:
    Node<T> *head;
    int t;
public:
    Stacks(){
    head=nullptr;
    t=0;
    }
    void push(T element){
    Node<T> *temp=new Node<T>(element);
    temp->next=head;
    //temp->data=element;
    head=temp;
    t++;
    return;
    }
    T pop(){
    if(isEmpty()){
        return -1;
    }
    T x=head->data;
    Node<T>* temp=head;
    head=head->next;
    delete temp;
    t--;
    return x;
    }
    T top(){
    if(isEmpty()){
        return -1;
    }
    return head->data;
    }
    T Size(){
    return t;
    }
    bool isEmpty(){
    return (t==0)?1:0;
    }
};
