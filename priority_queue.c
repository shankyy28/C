#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    int priority;
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
        printf("%d:%d ",temp->data, temp->priority);
        temp=temp->link;
    }
    printf("\n");
}

void ENQUEUE (int ins, int prior){   //find the last node and update the link of last node with new node
    struct node *new=create_node();
    struct node *temp=start;
    struct node *loc=start;
    if (start==NULL){                 //for empty linked list
        new->data=ins;
        new->priority=prior;
        new->link=NULL;
        start=new;
        end=new;
        return;
    }
    int pos=1;
    while (temp->link!=NULL){          //find the location to insert using loop
        if (temp->priority>prior){
            if (pos==1){               //if position is 1
                new->data=ins;
                new->priority=prior;
                new->link=start;
                start=new;
                return;
            }
            new->data=ins;             //other positions
            new->priority=prior;
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
        new->priority=prior;
        new->link=start;
        start=new;
    }else{             //if after traversing location was not found to insert
        if (temp->priority>prior){      //as loop doesnt take the case for last element
            new->data=ins;
            new->priority=prior;
            new->link=temp;
            loc->link=new;
        }else{
            new->data=ins;
            new->priority=prior;
            new->link=NULL;
            temp->link=new;
            end=new;
        }
    }
}

int DEQUEUE(){                      //Making start value point from second node
    struct node *temp=start;
    if (temp==NULL){
        printf("\nQueue is empty.\n");
        return;
    }
    start=temp->link;
    return temp->data;
}

void main(){
    int choice, cont, invalid=0, ins, priority;
    do{
        do{
            printf("Enter choice [1 to insert][2 to delete][3 to display]: ");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                    printf("Enter number to insert: ");
                    scanf("%d",&ins);
                    printf("Enter priority: ");
                    scanf("%d",&priority);
                    ENQUEUE(ins,priority);
                    invalid=0;
                    break;
                case 2:
                    printf("Number deleted is %d.\n",DEQUEUE());
                    invalid=0;
                    break;
                case 3:
                    display();
                    invalid=0;
                    break;
                default:
                    printf("Enter a valid choice.\n");
                    invalid=1;
                    break;
            }
            if (invalid==0)
                break;
        }while(1);
        printf("Enter any key to continue.[Enter 0 to stop]: ");
        scanf("%d",&cont);
        if (cont==0)
            break;
    }while(1);
}