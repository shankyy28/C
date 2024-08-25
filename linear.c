#include<stdio.h>

// Date- 17/01/2022
// Problem Statement- Find sum of all array elements using recursion
// Name- Shashank Dimri

void inputarr(int *arr,int n){                    // This function takes input of Array
    for (int i=0; i<n; i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
}

int search(int *arr, int n){                     // This functions searches element
    int ele;
    printf("Enter the number you want to search: ");
    scanf("%d",&ele);
    for (int i=0; i<n; i++){
        if (arr[i]==ele)
            return i;
    }
    return -1;
}

void main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int array[n];
    inputarr(array, n);
    int count=search(array, n);
    if (count!=-1)
        printf("\nElement found at position %d",count+1);
    else
        printf("\nElement not found.");
}