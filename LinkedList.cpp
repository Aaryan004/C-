#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct node{
 int num;
 struct node* next;
 };
 void DEL_BEG_LL(struct node** start1);
 void DEL_MID_LL(struct node** start1,int data);
 void DEL_END_LL(struct node** start1);
 void ADD_END_LL(struct node** start1,int item);
 void ADD_BEG_LL(struct node** start1,int item);
 void ADD_MID_LL(struct node** start1,int item,int data);
int main(){
 struct node *start=(struct node *)malloc(sizeof(struct node));
 struct node *Q=(struct node *)malloc(sizeof(struct node));
 //struct node* P=(struct node *)malloc(sizeof(struct node));
 int x=0;
 start=NULL;
 //printf("%d %d \n",start->num,start->next);
 while(x!=99){
    struct node* P=(struct node *)malloc(sizeof(struct node));
    P->num=x;
    if(start==NULL){
            start=P;
    }
    else{
        Q->next=P;
    }
    Q=P;
    P=NULL;
    x++;
    free(P);
 }
 /*struct node* Z=(struct node *)malloc(sizeof(struct node));
 Z=start;
 while(Z!=NULL){
    printf("%d %d \n",Z->num,Z->next);
    Z=Z->next;
 }*/
 int item=5;
 DEL_BEG_LL(&start);
 DEL_MID_LL(&start,65);
 DEL_END_LL(&start);
 ADD_BEG_LL(&start,item);
 ADD_END_LL(&start,item);
 ADD_MID_LL(&start,item,55);
  struct node* Z=(struct node *)malloc(sizeof(struct node));
 Z=start;
 while(Z!=NULL){
    printf("%d %d \n",Z->num,Z->next);
    Z=Z->next;
 }
}
void ADD_BEG_LL(struct node** start1,int item){
    //printf("%d \n",start1->next);
 struct node* K=(struct node *)malloc(sizeof(struct node));
 if(K==NULL){
    printf("Overflow \n");

 }
 else{
    K->num=item;
    K->next=*start1;
    *start1=K;
 }

}
void ADD_END_LL(struct node** start1,int item){
struct node* Y=(struct node*)malloc(sizeof(struct node));
struct node* Q=(struct node*)malloc(sizeof(struct node));
if(Y==NULL){
    printf("Overflow \n");
}
else{
    Q=*start1;
    while(Q->next!=NULL){
        Q=Q->next;
    }
    Q->next=Y;
    Y->num=item;
    Y->next=NULL;
}
 struct node* Z=(struct node *)malloc(sizeof(struct node));
/* Z=start1;
 while(Z!=NULL){
    printf("%d %d \n",Z->num,Z->next);
    Z=Z->next;
 }*/
}
void ADD_MID_LL(struct node** start1,int item,int data){
struct node* Q=(struct node*)malloc(sizeof(struct node));
struct node* P=(struct node*)malloc(sizeof(struct node));
struct node* R=(struct node*)malloc(sizeof(struct node));
if(P==NULL){
    printf("Overflow \n");
}
else{
    Q=*start1;
    while(Q->num!=data){
        Q=Q->next;
    }
    R=Q->next;
    Q->next=P;
    P->next=R;
    P->num=item;

}
}
void DEL_END_LL(struct node** start1){
struct node* Q=(struct node*)malloc(sizeof(struct node));
struct node* R=(struct node*)malloc(sizeof(struct node));
if(*start1==NULL){
    printf("Underflow \n");
}
else{
    Q=*start1;
    while(Q->next!=NULL){
        R=Q;
        Q=Q->next;
    }
    R->next=NULL;
    free(Q);
}
}
void DEL_BEG_LL(struct node** start1){
struct node* Q=(struct node*)malloc(sizeof(struct node));
if(*start1==NULL){
    printf("Underflow \n");
}
else{
    Q=*start1;
    *start1=Q->next;
    free(Q);
}
}
void DEL_MID_LL(struct node** start1,int data){
struct node* P=(struct node*)malloc(sizeof(struct node));
struct node* R=(struct node*)malloc(sizeof(struct node));
//struct node* Q=(struct node*)malloc(sizeof(struct node));
if(*start1==NULL){
    printf("Underflow \n");
}
else{
    P=*start1;
    while(P->num!=data){
        R=P;
        P=P->next;
    }
    R->next=P->next;
    free(P);

}
}
