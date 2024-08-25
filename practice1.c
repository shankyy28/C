#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node * create(){
    return ((struct node *)malloc(sizeof(struct node)));
}

void display(struct node *start){
    if (start==NULL){
        printf("List is empty.\n");
        return;
    }
    struct node *temp=start;
    while (temp){
        printf("%d",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

void insert_beg(struct node **start, int ins){
    struct node *new=create();
    new->data=ins;
    new->link=*start;
    *start=new;
}

void insert_end(struct node **start, int ins){
    struct node *new=create();
    new->data=ins;
    new->link=NULL;
    struct node *temp=*start;
    if (!temp){
        *start=new;
        return;
    }
    while (temp->link)
        temp=temp->link;
    temp->link=new;
}

void insert_pos(struct node **start, int ins, int pos){
    if (pos==1){
        insert_beg(start,ins);
        return;
    }
    struct node *prev=*start,*temp=(*start)->link;
    int loc=1;
    while (temp){
        loc=loc+1;
        if (loc==pos){
            struct node *new=create();
            new->data=ins;
            new->link=temp;
            prev->link=new;
            return;
        }
        prev=temp;
        temp=temp->link;
    }
    printf("Index doesn't exist.\n");
}

int delete_beg(struct node **start){
    if (*start==NULL){
        printf("List is empty.\n");
        return -1;
    }
    int data=(*start)->data;
    *start=(*start)->link;
    return data;
}

int delete_end(struct node **start){
    if (*start==NULL){
        printf("List is empty.\n");
        return -1;
    }
    int data;
    struct node *prev,*temp=*start;
    if ((*start)->link==NULL){
        data=(*start)->data;
        *start=NULL;
        return data;
    }
    while (temp->link){
        prev=temp;
        temp=temp->link;
    }
    data=temp->data;
    prev->link=NULL;
    return data;
}

void main(){
    struct node *start=NULL;
    display(start);
    insert_beg(&start,2);
    insert_beg(&start,1);
    insert_end(&start,4);
    insert_end(&start,5);
    insert_pos(&start,3,3);
    display(start);
}