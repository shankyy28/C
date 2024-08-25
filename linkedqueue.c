#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *start=NULL;
struct node *end=NULL;

struct node * create_node(){
    return ((struct node *)malloc(sizeof(struct node)));
}

void display(){               //traversing
    struct node *temp=start;
    if (start==NULL){
        printf("Queue is empty.\n");
        return;
    }
    while (temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
}

void ENQUEUE (int ins){   //find the last node and update the link of last node with new node
    struct node *new=create_node();
    if (start==NULL){
        new->data=ins;
        new->link=NULL;
        start=new;
        end=new;
        return;
    }
    new->data=ins;
    new->link=NULL;
    end->link=new;
    end=new;
}

int DEQUEUE(){                      //Making start value point from second node
    struct node *temp=start;
    if (temp==NULL){
        printf("Queue is empty.\n");
        return;
    }
    start=temp->link;
    return temp->data;
}

void main(){
    ENQUEUE(1);
    ENQUEUE(2);
    ENQUEUE(3);
    ENQUEUE(4);
    ENQUEUE(5);
    ENQUEUE(6);
    ENQUEUE(7);
    printf("%d",DEQUEUE());
    printf("%d",DEQUEUE());
    printf("\n");
    display();
}
