#include <stdio.h>
#include <stdlib.h>
struct node{
int num;
struct node* next;
};
void DEL_END_CL(struct node** start1);
void DEL_BEG_CL(struct node** start1);
void DEL_MID_CL(struct node** start1,int data);
int main(){
struct node* start=(struct node *)malloc(sizeof(struct node));
struct node* Q=(struct node *)malloc(sizeof(struct node));
start=NULL;
int x=0;
while(x!=11){
    struct node* P=(struct node *)malloc(sizeof(struct node));
    P->num=x;
    if(start==NULL){
        start=P;
    }
    else{
        Q->next=P;
    }
        Q=P;
        P->next=start;

        x++;

}
DEL_BEG_CL(&start);
DEL_END_CL(&start);
DEL_MID_CL(&start,7);
    struct node* Z=(struct node *)malloc(sizeof(struct node));
    Z=start;
    while(Z->next!=start){
            printf("%d \t %d \n",Z->num,Z->next);
            Z=Z->next;
    }
    printf("%d \t %d \n",Z->num,Z->next);
}
void DEL_BEG_CL(struct node** start1){
     struct node* Z=(struct node *)malloc(sizeof(struct node));
     struct node* R=(struct node *)malloc(sizeof(struct node));
if(*start1==NULL){
    printf("Underflow \n");
}
else{
    Z=*start1;
    R=*start1;
    while(R->next!=*start1){
        R=R->next;
    }
    *start1=Z->next;
    R->next=*start1;
    free(Z);

}
}
void DEL_END_CL(struct node** start1){
     struct node* Z=(struct node *)malloc(sizeof(struct node));
     struct node* R=(struct node *)malloc(sizeof(struct node));
if(*start1==NULL){
    printf("Underflow \n");
}
else{
    R=*start1;
    while(R->next!=*start1){
        Z=R;
        R=R->next;
    }
    Z->next=*start1;
    free(R);

}

}
void DEL_MID_CL(struct node** start1,int data){
     struct node* Z=(struct node *)malloc(sizeof(struct node));
     struct node* R=(struct node *)malloc(sizeof(struct node));
if(*start1==NULL){
    printf("Underflow \n");
}
else{
    R=*start1;
    while(R->num!=data){
        Z=R;
        R=R->next;
    }
    Z->next=R->next;
    free(R);

}

}
