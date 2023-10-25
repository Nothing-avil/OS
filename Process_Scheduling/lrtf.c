#include<stdio.h>
#include<stdlib.h>
# define MIN -9999

struct Process{
    int pid,at,bt,ct, tat,wt,rt,st;
    int remt; // remaining time of particular process
};

int main(){

    int n  , remain = 0; // store of remaining process
    int mx; // track the min val
    float avgrt = 0, avgWT = 0 , avgTat = 0 ;
    float sumWT = 0 , sumTat = 0 , sumrt = 0;
    printf("Enter the number of Process - ");
    scanf("%d" , &n);

    struct Process p[n+1];

    for(int i = 0 ; i < n ; i++)
    {
        p[i].pid = i;
        printf("Enter the Arrival Time and Burst Time for Process = %d - " , p[i].pid);
        scanf("%d%d" , &p[i].at , &p[i].bt);
        p[i].st = -1;
        p[i].remt = p[i].bt;        
    }

    // bubble sort
    struct Process temp;

    for(int i = 0 ; i < n-1 ; i++)
    {
        for(int j = 0 ; j < n-i-1 ; j++)
        {
            if(p[j].at > p[j+1].at)
            {
                temp = p[j];
                p[j]= p[j+1];
                p[j+1]= temp;
            }
        }
    }

    p[n].remt = MIN;

    for(int time = 0 ; remain != n ; time++)
    {
        mx = n;
        
        // in this loop we are finding the max of all avaliable process in the queue
        for(int i = 0 ; i < n ; i++)
        {
            if(p[i].at <= time && p[i].remt > p[mx].remt && p[i].remt > 0)
            {
                mx = i;
            }
        }

        if(p[mx].st == -1){
            p[mx].st = time;
            p[mx].rt = p[mx].st-p[mx].at;
            sumrt += p[mx].rt;
        }
            
        // reduce the remaining time by 1
        p[mx].remt--;

        if(p[mx].remt == 0)
        {
            remain++;
            p[mx].ct = time+1;
            p[mx].tat = p[mx].ct - p[mx].at;
            sumTat +=p[mx].tat;
            p[mx].wt = p[mx].tat - p[mx].bt;
            sumWT += p[mx].wt;
        }
    }

    avgWT = sumWT/n;
    avgTat = sumTat/n;
    avgrt = sumrt/n;
   
   printf("process\t\tat\tbt\tst\tct\trt\ttat\twt\n");
    
    for(int i = 0 ; i < n ; i++){
        printf("%d\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid , p[i].at , p[i].bt , p[i].st , p[i].ct , p[i].rt , p[i].tat , p[i].wt);
    }
    
    printf("Average Response Time =  %0.2f Average TurnAround Time = %0.2f Average Waiting Time = %0.2f\n" , avgrt , avgTat , avgWT);
    return 0;
}.c
