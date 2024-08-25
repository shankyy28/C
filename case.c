#include<stdio.h>

// Date- 17/01/2022
// Problem Statement- Convert uppercase string to lowercase using for loop
// Name- Shashank Dimri

void main(){
    char string[30];
    printf("Enter a string in uppercase: ");
    gets(string);
    for (int i=0; string[i]!='\0'; i++){
        if (string[i]>64 && string[i]<91)
            string[i]=string[i]+32;
    }
    puts(string);
}