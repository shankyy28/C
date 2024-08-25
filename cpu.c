//SRTF
#include<stdio.h>
 
//At arrival time 0 SRTF will run as SJF
 
void sort(int *process, int *burst, int n){
    int i=0;
    int temp,temp1;
    while (n>=0){
        for (int j=0; j<n-1; j++){
            if (burst[j]>burst[j+1]){
                temp=burst[j+1];
                burst[j+1]=burst[j];
                burst[j]=temp;
                //
                temp1=process[j+1];
                process[j+1]=process[j];
                process[j]=temp1;
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
 
void disp(int *process, int *burst, int *turn, int *wait, int n){
    printf("Processes\tArrival_time\tBurst_time\tWaiting_time\tTurn-around\n");
    for (int i=0; i<n; i++)
        printf("%d\t\t0\t\t%d\t\t%d\t\t%d\n",process[i],burst[i],wait[i],turn[i]);
}
 
void main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int process[n];
    int burst[n];
    int wait[n];
    int turn[n];
    for (int i=0; i<n; i++){
        printf("Enter process number: ");
        scanf("%d",&process[i]);
        printf("Enter burst time: ");
        scanf("%d",&burst[i]);
    }
    sort(process,burst,n);
    wait_time(wait,burst,n);
    turn_time(turn,burst,wait,n);
    disp(process,burst,turn,wait,n);
}














//LJF
 
 
#include<stdio.h>
 
void sort(int *process, int *burst, int n){
    int i=0;
    int temp,temp1;
    while (n>=0){
        for (int j=0; j<n-1; j++){
            if (burst[j]<burst[j+1]){
                temp=burst[j+1];
                burst[j+1]=burst[j];
                burst[j]=temp;
                //
                temp1=process[j+1];
                process[j+1]=process[j];
                process[j]=temp1;
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
 
void disp(int *process, int *burst, int *turn, int *wait, int n){
    printf("Processes\tArrival_time\tBurst_time\tWaiting_time\tTurn-around\n");
    for (int i=0; i<n; i++)
        printf("%d\t\t0\t\t%d\t\t%d\t\t%d\n",process[i],burst[i],wait[i],turn[i]);
}
 
void main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int process[n];
    int burst[n];
    int wait[n];
    int turn[n];
    for (int i=0; i<n; i++){
        printf("Enter process number: ");
        scanf("%d",&process[i]);
        printf("Enter burst time: ");
        scanf("%d",&burst[i]);
    }
    sort(process,burst,n);
    wait_time(wait,burst,n);
    turn_time(turn,burst,wait,n);
    disp(process,burst,turn,wait,n);
}

