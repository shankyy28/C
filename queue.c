#include<stdio.h>

int FRONT=-1;
int REAR=-1;

void ENQUEUE(int *queue, int ins, int max){
    if ((REAR==max-1 && FRONT==0) || REAR==FRONT-1){
        printf("Overflow\n");
        return;
    }
    else if (REAR==-1){
        REAR++;
        FRONT++;
    }else if (REAR==max-1)
        REAR=0;
    else
        REAR++;
    queue[REAR]=ins;
}

int DEQUEUE(int *queue, int max){
    int temp;
    if (FRONT==-1){
        printf("Underflow.\n");
        return;
    }
    temp=queue[FRONT];
    if (FRONT==REAR){
        FRONT=-1;
        REAR=-1;
    }else if (FRONT==max-1)
        FRONT=0;
    else
        FRONT++;
    return temp;
}

void display(int *queue, int max){
    if (REAR==-1){
        printf("Empty Queue.");
        return;
    }
    int i=FRONT;
    while (i!=REAR){
        printf("%d ",queue[i]);
        i++;
        if (i==max)
            i=0;
    }
    printf("%d",queue[REAR]);
}

void main(){
    int n;
    printf("Enter size of Queue: ");
    scanf("%d",&n);
    int queue[n];
    ENQUEUE(queue,1,n);
    ENQUEUE(queue,2,n);
    ENQUEUE(queue,3,n);
    ENQUEUE(queue,4,n);
    ENQUEUE(queue,5,n);
    ENQUEUE(queue,6,n);
    printf("DELETED ITEM=%d\n",DEQUEUE(queue,n));
    printf("DELETED ITEM=%d\n",DEQUEUE(queue,n));
    ENQUEUE(queue,7,n);
    ENQUEUE(queue,8,n);
    display(queue,n);
}