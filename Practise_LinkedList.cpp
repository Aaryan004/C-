#include <stdio.h>
#include <stdlib.h>
struct node{
int songID;
struct node* next;
};
void ADD(struct node** head);
int main(){
struct node* head=(struct node*)malloc(sizeof(struct node));
struct node* Q=(struct node*)malloc(sizeof(struct node));
head=NULL;
int x=0;
while(x!=99){
    struct node* P= (struct node*)malloc(sizeof(struct node));
    P->songID=x;
    if(head==NULL){
        head=P;
    }
    else{
        Q->next=P;
    }
    Q=P;
    P->next=NULL;
    x++;
}
ADD(&head);
struct node* Z=(struct node*)malloc(sizeof(struct node));
Z=head;
while(Z!=NULL){
    printf("%d \t %d \n",Z->songID,Z->next);
    Z=Z->next;
}
}
void ADD(struct node** head){
struct node* P=(struct node*)malloc(sizeof(struct node));
struct node* Q=(struct node*)malloc(sizeof(struct node));
P=*head;
while(P!=NULL){
if(P==*head && (P->songID)%2==0) {
    *head=P->next;
    P=*head;
    }
else if((P->songID)%2==0){
        Q->next=P->next;
        //free(P);
}
Q=P;
P=P->next;
}
}
