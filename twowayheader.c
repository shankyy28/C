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
    struct node *temp=start->next;
    if (temp==start){
        printf("Linked list is empty.\n");
        return;
    }
    while (temp!=start){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void insert_beg(struct node **start, int ins){   //updating the start value by new node
    struct node *new=create_node();
    struct node *temp=(*start)->next;
    new->data=ins;
    new->next=temp;
    new->prev=*start;
    (*start)->next=new;
}

void insert_end(struct node **start, int ins){   //find the last node and update the link of last node with new node
    struct node *temp=(*start)->next;
    if (temp==*start)
        insert_beg(start,ins);
    else{
        while (temp->next!=*start)
            temp=temp->next;
        struct node *new=create_node();
        new->data=ins;
        new->next=*start;
        new->prev=temp;
        temp->next=new;
    }
}

void insert_pos(struct node **start, int ins, int pos){    //if pos is 1 it means we are talking about starting element. So this is a case
    struct node *temp=(*start)->next;                                     //of inserting in beginning.
    if (pos==1)
        insert_beg(start,ins);
    else{
        int loc=1;
        while (temp->next!=*start){                            //Find the position of delete and also the location of the node 
            loc=loc+1;
            if (pos==loc)
                break;
            temp=temp->next;
        }
        if (temp->next==*start){                               //while traversing if element is not found it means the postion to insert is not present
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
    struct node *temp=(*start)->next;
    if (temp==*start)
        printf("Linked list is empty.\n");
    else{
        (*start)->next=temp->next;
        if ((*start)->next!=*start)
            ((*start)->next)->prev=*start;
        return temp->data;
    }
}

int del_end(struct node **start){                      //Find end node then update the pointer of previous node with null
    struct node *temp=(*start)->next;
    struct node *ptr;
    if (temp==*start)
        printf("Linked list is empty.\n");
    else if (temp->next==*start)
        del_beg(start);
    else{
        while (temp->next!=*start)
            temp=temp->next;
        (temp->prev)->next=*start;
        return temp->data;
    }
}

int del_pos(struct node **start, int pos){
    struct node *temp=(*start)->next;
    int loc=1;                                    //Find the location and find the pointer to the location and the previous
    if (pos==1)
        del_beg(start);
    else{
        while (temp->next!=*start){
            loc=loc+1;
            temp=temp->next;
            if (pos==loc)                                 //Finds the pointers
                break;
        }
        if (temp->next==*start){
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

void del_val(struct node **start, int val){
    struct node *temp=(*start)->next;
    int count=0;
    while (temp!=*start){                                //find position of the value and call del_pos function
        count=count+1;
        if (temp->data==val){
            del_pos(start,count);
            return;
        }
        temp=temp->next;
    }
    if (temp==*start)                                    //if temp is null it means value was not found 
        printf("Value doesn't exist.\n");
}

void search(struct node *start, int val){
    struct node *temp=start->next;
    if (temp==start)
        printf("List is empty.\n");
    else{
        int pos=1;
        while (temp->next!=start){
            if (temp->data==val){
                printf("\nFound at position %d.\n",pos);
                return;
            }else{
                pos++;
                temp=temp->next;
            }
        }
        if (temp->data==val)
            printf("\nFound at position %d.\n",pos);
        else
            printf("\nNot found.\n");
    }
}

void main(){
    struct node *head=create_node();
    struct node *start=head;
    head->next=head;
    head->prev=start;
    insert_beg(&start,1);
    insert_end(&start,3);
    insert_pos(&start,2,2);
    insert_end(&start,4);
    insert_end(&start,5);
    insert_end(&start,6);
    insert_end(&start,7);
    display(start);
    search(start,7);
}
