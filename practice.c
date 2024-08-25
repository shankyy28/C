#include<stdio.h>
#include<stdlib.h>

struct hash{
    int key;
    int value;
}table[10];

int n=10;

int hash_key(int key){
    int num=key%1000;
    int sum=0,temp=num;
    while (temp>0){
        int rem=temp%10;
        sum=sum+rem;
        temp=temp/10;
    }
    return sum%10;
}

void display(){
    for (int i=0; i<n; i++)
        printf("%d:%d ",table[i].key,table[i].value);
}

void insert(int value){
    int key=hash_key(value);
    int index;
    for (int i=0; i<n; i++){
        index=(key+i)%10;
        if (table[index].key==-1){
            table[index].key=key;
            table[index].value=value;
            return;
        }
    }
    printf("Overflow.");
}

void delete(int value){
    int key=hash_key(value);
    int index;
    for (int i=0; i<n; i++){
        index=(key+i)%10;
        if (table[index].value==value){
            table[index].key=-1;
            table[index].value=0;
            return;
        }
    }
    printf("Value not present.");
}

void main(){
    for (int j=0; j<n; j++)
        table[j].key=-1;
    
    insert(5000423);
    insert(5000425);
    insert(5000100);
    insert(5000132);
    insert(5000124);
    insert(5000345);
    insert(5000456);
    insert(5000567);
    insert(5000678);
    insert(5000679);
    display();
}