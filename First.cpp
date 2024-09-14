#include <stdio.h>
#include <stdlib.h>
struct node{
 int num;
 struct node* next;
 };
int main(){
 struct node* P=(struct node *)malloc(sizeof(struct node));
 printf("%d \n",P->next);
 struct node* Q=(struct node *)malloc(sizeof(struct node));
 printf("%d \n \n",Q->next);
 Q=P;
 //free(Q);
 printf("%d \n",P->next);
 printf("%d \n \n",Q->next);
 P->next=NULL;
  printf("%d \n",P->next);
 printf("%d \n",Q->next);
}
