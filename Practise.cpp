#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
int dt;
struct node* next;
};
void ADD_BEG_LL(struct node** Head,int x);
void ADD_MID_LL(struct node** Head,int item,int x);
void ADD_END_LL(struct node**Head,int x);
void DEL_BEG_LL(struct node** Head);
void DEL_END_LL(struct node** Head);
void DEL_MID_LL(struct node** Head,int x);
void PrintLL(struct node** Head);
int main(){
int x=0;
struct node* Start=(struct node*)malloc(sizeof(struct node));
struct node* Q=(struct node*)malloc(sizeof(struct node));
Q=Start;
Start=NULL;
printf("%d \n",sizeof(struct node));
while(x!=99){
 struct node* P=(struct node*)malloc(sizeof(struct node));
 P->dt=x;
 if(Start==NULL){
    Start=P;
 }
 else{
    Q->next=P;
 }
 Q=P;
 P->next=NULL;
 x++;
}
DEL_BEG_LL(&Start);
DEL_END_LL(&Start);
DEL_MID_LL(&Start,77);
ADD_BEG_LL(&Start,666);
ADD_MID_LL(&Start,89,777);
ADD_END_LL(&Start,333);
PrintLL(&Start);
}
void PrintLL(struct node** Head){
struct node* Z=(struct node*)malloc(sizeof(struct node));
Z=*Head;
while(Z!=NULL){
 printf("%d %d \n",Z->dt,Z->next);
 Z=Z->next;
}
}
void DEL_BEG_LL(struct node** Head){
struct node* Q=(struct node*)malloc(sizeof(struct node));
Q=*Head;
if(*Head==NULL){
    printf("Underflow \n");
}
else{
        *Head=Q->next;
         free(Q);
}
}
void DEL_END_LL(struct node** Head){
struct node* Q=(struct node*)malloc(sizeof(struct node));
struct node* R=(struct node*)malloc(sizeof(struct node));
Q=*Head;
if(*Head==NULL){
    printf("Underflow \n");
}
else{
    while(Q->next!=NULL){
        R=Q;
        Q=Q->next;
    }
    R->next=NULL;
}
}
void DEL_MID_LL(struct node** Head,int x){
struct node* Q=(struct node*)malloc(sizeof(struct node));
struct node* R=(struct node*)malloc(sizeof(struct node));
Q=*Head;
if(*Head==NULL){
    printf("Underflow \n");
}
else{
    while(Q->dt!=x){
        R=Q;
        Q=Q->next;
    }
    R->next=Q->next;
}
}
void ADD_BEG_LL(struct node** Head,int x){
struct node* Q=(struct node*)malloc(sizeof(struct node));
Q->dt=x;
Q->next=*Head;
*Head=Q;
}
void ADD_MID_LL(struct node** Head,int item,int x){
struct node* Q=(struct node*)malloc(sizeof(struct node));
struct node* R=(struct node*)malloc(sizeof(struct node));
Q=*Head;
R->dt=x;
if(*Head==NULL){
    printf("Overflow \n");
}
else{
    while(Q->dt!=item){
        Q=Q->next;
    }
    R->next=Q->next;
    Q->next=R;
}
}
void ADD_END_LL(struct node** Head,int x){
struct node* Q=(struct node*)malloc(sizeof(struct node));
struct node* R=(struct node*)malloc(sizeof(struct node));
Q=*Head;
R->dt=x;
if(*Head==NULL){
   printf("Overflow \n");
}
else{
    while(Q->next!=NULL){
        Q=Q->next;
    }
    Q->next=R;
    R->next=NULL;
}
}
