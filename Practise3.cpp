#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node{
int dt;
struct node* next;
};
void print_ll(struct node** head);
int main(){
struct node* start=(struct node*)malloc(sizeof(struct node));
struct node* q=(struct node*)malloc(sizeof(struct node));
q=start;
start=NULL;
int x=0;
while(x!=100){
 struct node* p=(struct node*)malloc(sizeof(struct node));
 p->dt=x;
 if(start==NULL){
    start=p;
 }  else{
 q->next=p;
 }
 q=p;
 p->next=start;
 x++;
}
print_ll(&start);

}
void print_ll(struct node** head){
 struct node* p=(struct node*)malloc(sizeof(struct node));
 p=*head;
 while(p->next!=*head){
    printf("%d %d \n",p->dt,p->next);
    p=p->next;
 }
 printf("%d %d \n",p->dt,p->next);
 p=p->next;
  printf("%d %d \n",p->dt,p->next);

}
