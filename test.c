#include<stdio.h>
#include<string.h>
 
int TOP=-1;
 
void PUSH(int *stack, int ins, int max){
    if (TOP==max)
        printf("Overflow.");
    else{
        TOP=TOP+1;
        stack[TOP]=ins-48;
        printf("%d",stack[TOP]);
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
 
int eval(char *post){
    int max=strlen(post);
    int stack[max],ans,A,B;
    int res;
    for (int i=0; post[i]!=')'; i++){
        if (post[i]>47 && post[i]<58)
            PUSH(stack,(int)post[i],max);
        else{
            if (post[i]=='+'){
                A=POP(stack);
                B=POP(stack);
                ans=B+A;
                PUSH(stack,ans,max);
            }else if (post[i]=='-'){
                A=POP(stack);
                B=POP(stack);
                ans=B-A;
                PUSH(stack,ans,max);
            }else if (post[i]=='*'){
                A=POP(stack);
                B=POP(stack);
                ans=B*A;
                PUSH(stack,ans,max);
            }else if (post[i]=='/'){
                A=POP(stack);
                B=POP(stack);
                ans=B/A;
                PUSH(stack,ans,max);
            }
        }
    }
    res=(int)POP(stack);
    return res;
}
 
void main(){
    char post[]="562+*84/-)";
    int ans=eval(post);
    //printf("%d",ans);
}
