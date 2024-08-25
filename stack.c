#include<stdio.h>

int TOP=-1;

void PUSH(int *stack, int ins, int max){
    if (TOP==max)
        printf("Overflow.");
    else{
        TOP=TOP+1;
        stack[TOP]=ins;
    }
}

int POP(int *stack){
    if (TOP==-1)
        printf("Underflow.");
    else{
        int item=stack[TOP];
        TOP=TOP-1;
        return item;
    }
}

int PEEK(int *stack){
    if (TOP==-1)
        printf("Empty stack.");
    else
        return stack[TOP];
}

void display(int *stack){
    if (TOP==-1){
        printf("Empty stack.");
        return;
    }
    for (int i=0; i<TOP+1; i++){
        printf("%d ",stack[i]);
    }
}

void main(){
    int n;
    printf("Enter max size of stack: ");
    scanf("%d",&n);
    int stack[n];
    PUSH(stack,1,n);
    PUSH(stack,2,n);
    PUSH(stack,3,n);
    PUSH(stack,4,n);
    PUSH(stack,5,n);
    display(stack);
    printf("\n%d\n",POP(stack));
    printf("%d\n",POP(stack));
    printf("%d\n",POP(stack));
    display(stack);
    printf("\n%d",PEEK(stack));
}