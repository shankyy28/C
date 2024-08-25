#include<stdio.h>

int read(int *list){
    FILE *f=fopen("Test.txt","r");
    int num,i=0;
    while(!feof(f)){
        fscanf(f,"%d",&list[i]);
        i++;
    }
    fclose(f);
    return i;
}

void insertion_sort(int *arr, int n){
    int key,j;
    for (int i=1; i<n; i++){
        key=arr[i];
        j=i-1;
        while (j>=0 && key<arr[j]){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

void selection_sort(int *list, int n){
    int temp,min_index;
    for (int i=0; i<n; i++){
        min_index=i;
        for (int j=i+1; j<n; j++){
            if (list[min_index]>list[j])
                min_index=j;
        }
        temp=list[min_index];
        list[min_index]=list[i];
        list[i]=temp;
    }
}

void swap(int *a, int *b){
    int temp=*b;
    *b=*a;
    *a=temp;
}

int partition(int *arr, int start, int end){
    int pivot=arr[end];
    int i=start-1;
    int temp;
    for (int j=start; j<end; j++){
        if (arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[end]);
    return i+1;
}

void quick_sort(int *arr, int start, int end){
    if (start<end){
        int p=partition(arr,start,end);
        quick_sort(arr,start,p-1);
        quick_sort(arr,p+1,end);
    }
}

void write(int *list, int n){
    FILE *f=fopen("Test.txt","w");
    int i=0,num;
    while(i<n){
        num=list[i];
        fprintf(f,"%d ",num);
        i++;
    }
    fclose(f);
}

void main(){
    int n;
    int list[100];
    n=read(list);
    quick_sort(list,0,n-1);
    write(list,n);
}