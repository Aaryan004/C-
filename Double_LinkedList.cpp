#include <stdio.h>
#include <stdlib.h>
struct node{
int num;
struct node *next;
struct node *prev;
};
void DEL_BEG_LL(struct node** start1);
void DEL_END_LL(struct node** start1);
void DEL_MID_LL(struct node** start1,int data);
void ADD_BEG_LL(struct node** start1,int data);
void ADD_END_LL(struct node** start1,int data);
void ADD_MID_LL(struct node** start1,int data,int item);
int main(){
struct node* start=(struct node*)malloc(sizeof(struct node));
struct node* Q=(struct node*)malloc(sizeof(struct node));
start=NULL;
int x=0;
while(x!=99){
struct node* P=(struct node*)malloc(sizeof(struct node));
P->num=x;
if(start==NULL){
start=P;
}
else{
Q->next=P;
P->prev=Q;
}
Q=P;
P->next=NULL;
x++;
}
//DEL_END_LL(&start);
//DEL_MID_LL(&start,94);
//DEL_BEG_LL(&start);
ADD_BEG_LL(&start,78);
ADD_END_LL(&start,78);
ADD_MID_LL(&start,55,5);
struct node* Z=(struct node*)malloc(sizeof(struct node));
Z=start;
while(Z!=NULL){
printf("%d \t %d \t %d \n",Z->num,Z->prev,Z->next);
Z=Z->next;
}
}
void DEL_BEG_LL(struct node** start1){
struct node* P=(struct node*)malloc(sizeof(struct node));
if(*start1==NULL){
        printf("Underflow \n");
}
else{
    P=*start1;
    *start1=P->next;
    free(P);

}
}
void DEL_END_LL(struct node** start1){
struct node* P=(struct node*)malloc(sizeof(struct node));
struct node* R=(struct node*)malloc(sizeof(struct node));
if(*start1==NULL){
        printf("Underflow \n");
}
else{
    P=*start1;
    while(P->next!=NULL){
        R=P;
        P=P->next;
    }
    R->next=NULL;
    free(P);

}
}
void DEL_MID_LL(struct node** start1,int data){
struct node* P=(struct node*)malloc(sizeof(struct node));
struct node* R=(struct node*)malloc(sizeof(struct node));
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
void ADD_BEG_LL(struct node** start1,int data){
struct node* P=(struct node*)malloc(sizeof(struct node));
struct node* R=(struct node*)malloc(sizeof(struct node));
if(R==NULL){
        printf("Overflow \n");
}
else{
    R->num=data;
    R->next=*start1;
    *start1=R;
    //R=*start1;

}
}
void ADD_END_LL(struct node** start1,int data){
struct node* P=(struct node*)malloc(sizeof(struct node));
struct node* R=(struct node*)malloc(sizeof(struct node));
if(R==NULL){
        printf("Overflow \n");
}
else{
    R->num=data;
    P=*start1;
    while(P->next!=NULL){
        P=P->next;
    }
    P->next=R;
    R->prev=P;
    R->next=NULL;
    //R=*start1;

}
}
void ADD_MID_LL(struct node** start1,int data,int item){
struct node* P=(struct node*)malloc(sizeof(struct node));
struct node* R=(struct node*)malloc(sizeof(struct node));
if(R==NULL){
        printf("Overflow \n");
}
else{
    R->num=item;
    P=*start1;
    while(P->num!=data){
        P=P->next;
    }
    R->next=P->next;
    P->next=R;
    R->prev=P;
    //R=*start1;

}
}
