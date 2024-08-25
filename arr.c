#include<stdio.h>

// Date- 17/01/2022
// Problem Statement- Create an array 'a1' with 'n' elements. Insert an element in ith position of 'a1' and also delete an element from jth
//                    position of 'a1'.                                                                                                  
// Name- Shashank Dimri

void inputarr(int *a1,int n){                    // This function takes input of Array from user
    for (int i=0; i<n; i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&a1[i]);
    }
}

void insert1(int *a1, int n){
    int pos;
    printf("Enter the position of to insert the element: ");
    scanf("%d",&pos);
    pos--;
    for (int i=n; i>pos; i--)
        a1[n]=a1[n-1];
    
}

void insert(int *a1, int n){
    int choice;
    printf("Enter your choice [1.Insert at any position 2.Insert at the beginning 3.Insert at the end]");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        insert1(a1,n);
        break;
    }
}

void main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a1[100];
    inputarr(a1,n);

}