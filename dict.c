#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    int value;
    struct node *link;
};

struct node *start=NULL;

struct node * create_node(){
    return ((struct node *)malloc(sizeof(struct node)));
}

void display(){
    struct node *temp=start;
    if (!temp){
        printf("List is empty.\n");
        return;
    }
    printf("{ ");
    while (temp){
        printf("%d:%d ",temp->key,temp->value);
        temp=temp->link;
    }
    printf("}\n");
}

void insert_update(int key, int value){
    struct node *new=create_node();
    struct node *temp=start;
    struct node *loc=start;
    if (!start){                 //for empty linked list
        new->key=key;
        new->value=value;
        new->link=NULL;
        start=new;
        return;
    }
    while (temp){                 //checks duplication
        if (temp->key==key){
            temp->value=value;
            return;
        }
        temp=temp->link;
    }
    temp=start;        //reset value of temp
    int pos=1;
    new->key=key;
    new->value=value;
    while (temp->link){          //find the location to insert using loop
        if (temp->key>key){
            if (pos==1){               //if position is 1
                new->link=start;
                start=new;
                return;
            }             //other positions
            new->link=temp;
            loc->link=new;
            return;
        }
        pos++;
        loc=temp;
        temp=temp->link;
    }
    if (pos==1){       //if inserting position is 1 when linked list has one element only
        if (temp->key>key){   //if first element is greater
            new->link=start;
            start=new;
        }else{                 //if first element is smaller
            new->link=NULL;
            temp->link=new;
        }
    }else{             //if after traversing location was not found to insert
        if (temp->key>key){      //if last element is greater
            new->link=temp;
            loc->link=new;
        }else{                 //if last element is smaller
            new->link=NULL;
            temp->link=new;
        }
    }
}

int search(int key){
    struct node *temp=start;
    if (!temp)
        printf("List is empty.\n");
    else{
        while (temp){
            if (temp->key==key)
                return (temp->value);
            temp=temp->link;
        }
    }
    return -1;
}

int delete(int key){
    struct node *temp=start;
    struct node *loc=start;
    if (!temp)
        printf("List is empty.\n");
    else{
        int pos=1;
        while (temp){
            if (temp->key==key){
                if (pos==1){
                    start=start->link;
                    return temp->value;
                }
                loc->link=temp->link;
                return temp->value;
            }
            pos++;
            loc=temp;
            temp=temp->link;
        }
    }
    return -1;
}

int length(){
    int len=0;
    struct node *temp=start;
    while (temp){
        len++;
        temp=temp->link;
    }
    return len;
}

int isKeyExist(int key){
    struct node *temp=start;
    while (temp){
        if (temp->key==key)
            return 1;
        temp=temp->link;
    }
    return 0;
}

void main(){
    display();
    insert_update(1,100);
    insert_update(2,200);
    insert_update(3,400);
    insert_update(3,300);
    insert_update(4,400);
    insert_update(5,500);
    display();
    printf("Delete: %d\n",delete(1));
    printf("Delete: %d\n",delete(10));
    display();
    printf("Search: %d\n",search(1));
    printf("Search: %d\n",search(2));
    printf("Length: %d\n",length());
    printf("Exist: %d\n",isKeyExist(4));
    printf("Exist: %d\n",isKeyExist(1));
    display();
}