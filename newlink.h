#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node ** create_new(){
    struct node *start=NULL;
    return &start;
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

void insert_beg(struct node **start, int ins){   //updating the start value by new node
    struct node *new=create_node();
    new->link=*start;
    new->data=ins;
    *start=new;
}

void insert_end(struct node **start, int ins){   //find the last node and update the link of last node with new node
    struct node *temp=*start;
    if (*start==NULL){
        insert_beg(start,ins);
        return;
    }
    while (temp->link!=NULL)
        temp=temp->link;
    struct node *new=create_node();
    new->data=ins;
    new->link=NULL;
    temp->link=new;
}

void insert_pos(struct node **start,int ins, int pos){    //if pos is 1 it means we are talking about starting element. So this is a case
    struct node *temp=*start;                                      //of inserting in beginning.
    if (pos==1){
        insert_beg(start,ins);
        return;
    }else{
        int loc=1;
        while (temp->link!=NULL){                            //Find the position of delete and also the location of the node 
            loc=loc+1;
            if (pos==loc)
                break;
            temp=temp->link;
        }
        if (temp->link==NULL){                               //while traversing if element is not found it means the postion to insert is not present
            printf("Position is out of range. Number of element of linked list is %d.\n",loc);
            return;
        }
        struct node *new=create_node();
        new->data=ins;                                      //updating the link of pervious node with new node and new node with previous node 
        new->link=temp->link;
        temp->link=new;
    }
}

int del_beg(struct node **start){                      //Making start value point from second node
    struct node *temp=*start;
    if (temp==NULL){
        printf("Linked list is empty.\n");
        return;
    }
    *start=temp->link;
    return temp->data;
}

int del_end(struct node **start){                      //Find end node then update the pointer of previous node with null
    struct node *temp=*start;
    struct node *ptr;
    if (temp==NULL){
        printf("Linked list is empty.\n");
        return;
    }
    if (temp->link==NULL){
        del_beg(start);
        return;
    }
    while (temp->link!=NULL){
        ptr=temp;
        temp=temp->link;
    }
    ptr->link=NULL;
    return temp->data;
}

int del_pos(struct node **start,int pos){
    struct node *temp=*start;
    int loc=1;
    struct node *ptr;                                      //Find the location and find the pointer to the location and the previous
    if (pos==1){
        del_beg(start);
        return;
    }else{
        while (temp->link!=NULL){
            loc=loc+1;
            ptr=temp;
            temp=temp->link;
            if (pos==loc)                                 //Finds the pointers
                break;
        }
        if (temp->link==NULL){
            if (pos>loc)
                printf("Position is out of range. Number of element of linked list is %d.\n",loc);
            else
                del_end(start);
            return;
        }
        ptr->link=temp->link;                              //updates the values
        return temp->data;
    }
}

void del_val(struct node **start,int val){
    struct node *temp=*start;
    int count=0;
    while (temp!=NULL){                                //find position of the value and call del_pos function
        count=count+1;
        if (temp->data==val){
            del_pos(start,count);
            return;
        }
        temp=temp->link;
    }
    if (temp==NULL)                                    //if temp is null it means value was not found 
        printf("Value doesn't exist.\n");
}