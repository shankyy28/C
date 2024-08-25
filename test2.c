#include<stdio.h>
 
void sort(int *process, int *burst, int *prioirty, int n){
    int i=0;
    int temp,temp1,temp2;
    while (n>=0){
        for (int j=0; j<n-1; j++){
            if (priority[j]>priority[j+1]){
                temp=burst[j+1];
                burst[j+1]=burst[j];
                burst[j]=temp;
                //
                temp1=process[j+1];
                process[j+1]=process[j];
                process[j]=temp1;
                //
                temp2=priority[j+1];
                priority[j+1]=priority[j];
                priority[j]=temp2;
            }
        }
        n=n-1;
    }
}
 
void wait_time(int *wait, int *burst, int n){
    for (int i=0; i<n; i++){
        if (i==0)
            wait[i]=0;
        else
            wait[i]=burst[i-1]+wait[i-1];
    }
}
 
void turn_time(int *turn,int *wait, int *burst, int n){
    for (int i=0; i<n; i++)
        turn[i]=burst[i]+wait[i];
}
 
void disp(int *process, int *burst, int *priority, int *turn, int *wait, int n){
    printf("Processes\tPriority\tArrival_time\tBurst_time\tWaiting_time\tTurn-around\n");
    for (int i=0; i<n; i++)
        printf("%d\t\t%d\t\t0\t\t%d\t\t%d\t\t%d\n",process[i],priority[i],burst[i],wait[i],turn[i]);
}
 
void main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int process[n];
    int burst[n];
    int wait[n];
    int turn[n];
    int priority[n];
    for (int i=0; i<n; i++){
        printf("Enter process number: ");
        scanf("%d",&process[i]);
        printf("Enter burst time: ");
        scanf("%d",&burst[i]);
        printf("Enter priority: ");
        scanf("%d",&priority[i]);
    }
    sort(process,burst,priority,n);
    wait_time(wait,burst,n);
    turn_time(turn,burst,wait,n);
    disp(process,burst,priority,turn,wait,n);
}

