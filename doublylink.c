#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node * create_node(){
    return ((struct node *)malloc(sizeof(struct node)));
}

void display(struct node *start){               //traversing
    struct node *temp=start;
    if (temp==NULL){
        printf("Linked list is empty.\n");
        return;
    }
    while (temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void insert_beg(struct node **start, int ins){   //updating the start value by new node
    struct node *new=create_node();
    new->data=ins;
    new->next=*start;
    new->prev=NULL;
    *start=new;
}

void insert_end(struct node **start, int ins){   //find the last node and update the link of last node with new node
    struct node *temp=*start;
    if (*start==NULL){
        insert_beg(start,ins);
        return;
    }
    while (temp->next)
        temp=temp->next;
    struct node *new=create_node();
    new->data=ins;
    new->next=NULL;
    new->prev=temp;
    temp->next=new;
}

void insert_pos(struct node **start,int ins, int pos){    //if pos is 1 it means we are talking about starting element. So this is a case
    struct node *temp=*start;                                      //of inserting in beginning.
    if (pos==1){
        insert_beg(start,ins);
        return;
    }else{
        int loc=1;
        while (temp->next){                            //Find the position of delete and also the location of the node 
            loc=loc+1;
            if (pos==loc)
                break;
            temp=temp->next;
        }
        if (temp->next==NULL){                               //while traversing if element is not found it means the postion to insert is not present
            printf("Position is out of range. Number of element of linked list is %d.\n",loc);
            return;
        }
        struct node *new=create_node();
        new->data=ins;                                      //updating the link of pervious node with new node and new node with previous node 
        new->next=temp->next;
        new->prev=temp;
        (temp->next)->prev=new;
        temp->next=new;
    }
}

int del_beg(struct node **start){                      //Making start value point from second node
    struct node *temp=*start;
    if (temp==NULL)
        printf("Linked list is empty.\n");
    else{
        *start=temp->next;
        if (*start)
            (*start)->prev=NULL;
        return temp->data;
    }
}

int del_end(struct node **start){                      //Find end node then update the pointer of previous node with null
    struct node *temp=*start;
    struct node *ptr;
    if (temp==NULL)
        printf("Linked list is empty.\n");
    else if (temp->next==NULL)
        del_beg(start);
    else{
        while (temp->next)
            temp=temp->next;
        (temp->prev)->next=NULL;
        return temp->data;
    }
}

int del_pos(struct node **start,int pos){
    struct node *temp=*start;
    int loc=1;                                    //Find the location and find the pointer to the location and the previous
    if (pos==1)
        del_beg(start);
    else{
        while (temp->next){
            loc=loc+1;
            temp=temp->next;
            if (pos==loc)                                 //Finds the pointers
                break;
        }
        if (temp->next==NULL){
            if (pos>loc)
                printf("Position is out of range. Number of element of linked list is %d.\n",loc);
            else
                del_end(start);
        }else{
            (temp->next)->prev=temp->prev;                              //updates the values
            (temp->prev)->next=temp->next; 
            return temp->data;
        }
    }
}

void del_val(struct node **start,int val){
    struct node *temp=*start;
    int count=0;
    while (temp){                                //find position of the value and call del_pos function
        count=count+1;
        if (temp->data==val){
            del_pos(start,count);
            return;
        }
        temp=temp->next;
    }
    if (temp==NULL)                                    //if temp is null it means value was not found 
        printf("Value doesn't exist.\n");
}

void main(){
    struct node *start=NULL;
    insert_beg(&start,1);
    insert_end(&start,3);
    insert_pos(&start,2,2);
    insert_end(&start,4);
    insert_end(&start,5);
    insert_end(&start,6);
    insert_end(&start,7);
    del_beg(&start);
    del_end(&start);
    del_val(&start,3);
    del_pos(&start,3);
    display(start);
}
