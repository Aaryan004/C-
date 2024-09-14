#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node{
char ch;
struct node* next;
};
void Print_LL(struct node** head);
int main(){
struct node* start=(struct node*)malloc(sizeof(struct node));
struct node* Q=(struct node*)malloc(sizeof(struct node));
char t;
char d;
Q=start;
start=NULL;
while(t!='\t'){
struct node* P=(struct node*)malloc(sizeof(struct node));
printf("Enter character: \n");
scanf("%c",&t);
scanf("%c",&d);
P->ch=t;
if(start==NULL){
start=P;
}else{
Q->next=P;
}
Q=P;
Q->next=NULL;
}
Print_LL(&start);
}
void Print_LL(struct node** head){
struct node* Q=(struct node*)malloc(sizeof(struct node));
Q=*head;
while(Q!=NULL){
if(Q->ch=='a'||Q->ch=='e'||Q->ch=='i'||Q->ch=='o'||Q->ch=='u'){
printf("%c %d \n",Q->ch,Q->next);
}
Q=Q->next;
}
}
