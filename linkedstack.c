#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node * create_new(){
    struct node *start=NULL;
    return start;
}

struct node * create_node(){
    return ((struct node *)malloc(sizeof(struct node)));
}

void display(struct node *start){               //traversing
    struct node *temp=start;
    if (temp==NULL){
        printf("Linked list is empty.\n");
        return;
    }
    while (temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
}

void PUSH(struct node **start, int ins){   //updating the start value by new node
    struct node *new=create_node();
    new->link=*start;
    new->data=ins;
    *start=new;
}

int POP(struct node **start){                      //Making start value point from second node
    struct node *temp=*start;
    if (temp==NULL){
        printf("Linked list is empty.\n");
        return;
    }
    *start=temp->link;
    return temp->data;
}

void main(){
    struct node *start=create_new();
    PUSH(&start,1);
    PUSH(&start,2);
    PUSH(&start,3);
    PUSH(&start,4);
    int del=POP(&start);
    display(start);
}