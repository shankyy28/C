#include<stdio.h>

void add(int a){
    a=a+1;
}

void main(){
    int a=5;
    add(a);
    printf("%d",a);
}