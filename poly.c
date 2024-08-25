#include<stdio.h>
#include<stdlib.h>
 
struct node{
    int coeff;
    int exp;
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
    while (temp->link!=NULL){
        printf("%dx^%d",temp->coeff, temp->exp);
        printf("+");
        temp=temp->link;
    }
    printf("%d\n",temp->coeff);
}
 
void insert(struct node **start, int coeff, int exp){   //find the last node and update the link of last node with new node
    struct node *temp=*start;
    struct node *new=create_node();
    if (*start==NULL){
        new->link=*start;
        new->coeff=coeff;
        new->exp=exp;
        *start=new;
        return;
    }
    while (temp->link!=NULL)
        temp=temp->link;
    new->coeff=coeff;
    new->exp=exp;
    new->link=NULL;
    temp->link=new;
}
 
void create_poly(struct node **start){
    int con=0;
    do{
        int coeff,exp;
        printf("Enter exponent: ");
        scanf("%d",&exp);
        printf("Enter coeff: ");
        scanf("%d",&coeff);
        insert(start,coeff,exp);
        printf("Do you want to add more? [1=yes]");
        scanf("%d",&con);
    }while(con==1);
}

void add(struct node *p1, struct node *p2, struct node **res){
    int coeff,exp;
    while(p1 && p2){
        if (p1->exp>p2->exp){
            insert(res, p1->coeff, p1->exp);
            p1=p1->link;
        }else if (p1->exp<p2->exp){
            insert(res,p2->coeff,p2->exp);
            p2=p2->link;
        }else{
            coeff=p1->coeff+p2->coeff;
            insert(res,coeff,p2->exp);
            p1=p1->link;
            p2=p2->link;
        }
    }
    while (p1){
        insert(res,p1->coeff,p1->exp);
        p1=p1->link;
    }
    while (p2){
        insert(res,p2->coeff,p2->exp);
        p2=p2->link;
    }
}
 
void main(){
    struct node *poly1=create_new();
    struct node *poly2=create_new();
    struct node *result=create_new();
    create_poly(&poly1);
    printf("Polynomial 1: ");
    display(poly1);
    create_poly(&poly2);
    printf("Polynomial 2: ");
    display(poly2);
    add(poly1,poly2,&result);
    printf("Resultant Polynomial: ");
    display(result);
}
