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

int sum(int *arr, int n){                         // This function calculates the sum of array using recursion and returns sum to the caller
    n=n-1;
    if (n==0)
        return arr[0];
    else{
        return (arr[n]+sum(arr,n));
    }
}

void main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int arr[n];
    inputarr(arr,n);
    int sol=sum(arr,n);
    printf("\nSum of array is %d.",sol);
}