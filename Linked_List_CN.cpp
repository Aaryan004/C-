#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int data){
    this->data=data;
    }
};
Node* TakeInputBetter(){
int data;
cin>>data;
Node* head=NULL;
Node* tail=NULL;
while(data != -1){
    Node* newNode=new Node(data);
    if(head == NULL){
        head=newNode;
        tail=newNode;
    }else{
    tail->next=newNode;
    tail=tail->next;
    }
    cin>>data;
}
return head;
}
Node* TakeInput(){
int data;
cin>>data;
Node* head=NULL;
while(data != -1){
    Node* newNode=new Node(data);
    if(head == NULL){
        head=newNode;
    }else{
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    }
    cin>>data;
}
return head;
}
void print(Node *head){
Node *temp=head;//We should always traverse on a temporary node not on a permanent node as head once lost is lost forever.
while(temp!=NULL){
    cout<<temp->data<<endl;
    temp=temp->next;
}
}
Node* insertNode(Node* head,int i,int data){
Node* temp=head;
Node* newNode=new Node(data);
int count_node=0;
if(i==0){//Only for the inserting a new head
    newNode->next=head;
    head=newNode;
    return head;
}
while(temp!=NULL && count_node<i-1){//temp!=Null condition is their for if the linked list is of 5 nodes and we say we want to insert at 7 node then there is a segmentation Fault
    temp=temp->next;
    count_node++;
}
if(temp!=NULL){//The loop could have been broken because temp==Null or i==count so we only run the if statements if temp!=Null meaning that we are inserting within the Linked List
newNode->next=temp->next;
temp->next=newNode;
}
return head;//We do not need to return for other cases other than the first one but it is just that since we have a return type of Node* so we write this.
}//Essentially, the address of the original address is only being returned so there is no change.
int main(){
Node* head=TakeInputBetter();
print(head);
/*
//Statically
Node n1(1);
Node n2(2);
Node n3(3);
Node n4(4);
Node n5(5);
Node *head=&n1;
n1.next=&n2;
n2.next=&n3;
n3.next=&n4;
n4.next=&n5;
print(head);
*/
/*
//Dynamically
Node *n3=new Node(3);
Node *head=&n1;
Node *n4=new Node(4);

n3->next=n4;

cout<<n3->data<<endl;
n3=n3->next;
cout<<n3->data<<endl;*/
}
