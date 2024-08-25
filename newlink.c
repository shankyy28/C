#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node * create_new(){
    return NULL;
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

void del(struct node **start){                          //ask if user wants to delete position or value.
    int choice;
    struct node *temp=*start;
    if (temp==NULL){
        printf("Linked list is empty.\n");
        return;
    }
    printf("Do you want to delete position[0] or value[1]: ");
    scanf("%d",&choice);
    if (choice==0){                                   //Pick a choice
        int pos;
        printf("Enter position to delete: ");
        scanf("%d",&pos);
        del_pos(start,pos);                     //calls function to delete location
    }else if (choice==1){
        int val;
        printf("Enter value to delete: ");
        scanf("%d",&val);
        del_val(start,val);                    //call function to delete value
    }else
        printf("Enter a valid choice.\n");
}

void main(){
    struct node *START=create_new();
    int count=0;
    do{
        int choice;
        printf("[1 to insert at start]\n");
        printf("[2 to insert at end]\n");
        printf("[3 to insert at any position]\n");
        printf("[4 to delete at start]\n");
        printf("[5 to delete at end]\n");
        printf("[6 to delete any position/value]\n");
        printf("[7 to display]\nEnter your choice: ");
        scanf("%d",&choice);
        int ins,pos;
        switch(choice){
            case 1:
            printf("Enter a number to insert: ");
            scanf("%d",&ins);
            insert_beg(&START,ins);
            break;
            //
            case 2:
            printf("Enter a number to insert: ");
            scanf("%d",&ins);
            insert_end(&START,ins);
            break;
            //
            case 3:
            printf("Enter a number to insert: ");
            scanf("%d",&ins);
            printf("Enter position to insert: ");
            scanf("%d",&pos);
            insert_pos(&START,ins,pos);
            break;
            //
            case 4:
            del_beg(&START);
            break;
            //
            case 5:
            del_end(&START);
            break;
            //
            case 6:
            del(&START);
            break;
            //
            case 7:
            display(START);
            break;
            //
            default:
            printf("Enter a valid choice.\n");
        }
        printf("\nDo you want to continue [0 yes / 1 no]: ");
        scanf("%d",&count);
    }while(count==0);
}