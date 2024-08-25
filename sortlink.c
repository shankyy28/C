#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node * create_node(){
    return ((struct node *)malloc(sizeof(struct node)));
}

void display(struct node *start){               //traversing
    if (start==NULL){
        printf("Queue is empty.\n");
        return;
    }
    while (start!=NULL){
        printf("%d ",start->data);
        start=start->link;
    }
    printf("\n");
}

void insert(struct node **start, int ins){   //find the last node and update the link of last node with new node
    struct node *new=create_node();
    struct node *temp=*start;
    struct node *loc=*start;
    if (*start==NULL){                 //for empty linked list
        new->data=ins;
        new->link=NULL;
        *start=new;
        return;
    }
    int pos=1;
    while (temp->link!=NULL){          //find the location to insert using loop
        if (temp->data>ins){
            if (pos==1){               //if position is 1
                new->data=ins;
                new->link=*start;
                *start=new;
                return;
            }
            new->data=ins;             //other positions
            new->link=temp;
            loc->link=new;
            return;
        }
        pos++;
        loc=temp;
        temp=temp->link;
    }
    if (pos==1){       //if inserting position is 1 when linked list has one element only
        new->data=ins;
        new->link=*start;
        *start=new;
    }else{             //if after traversing location was not found to insert
        if (temp->data>ins){      //as loop doesnt take the case for last element
            new->data=ins;
            new->link=temp;
            loc->link=new;
        }else{
            new->data=ins;
            new->link=NULL;
            temp->link=new;
        }
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

void main(){
    struct node *start=NULL;
    insert(&start,4);
    insert(&start,2);
    insert(&start,7);
    insert(&start,6);
    insert(&start,5);
    insert(&start,3);
    insert(&start,1);
    display(start);
    printf("Deleted node:%d\n",del_beg(&start));
    printf("Deleted node:%d\n",del_end(&start));
    printf("Deleted node:%d\n",del_pos(&start,3));
    printf("\n");
    display(start);
}
