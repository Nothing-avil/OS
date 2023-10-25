#include<stdio.h>
#include<stdlib.h>
# define MAX 999
struct Process
{
    int pid,at,bt,rt,tat,wt,st,ct; 
    int remt , priority;
};
int compare(const void *p1 , const void *p2){
    int a = ((struct Process *) p1)->at;
    int b = ((struct Process *) p2)->at;
    if(a < b) return -1;
    else return 1;
}

int main()
{
    int n , remain = 0 , minp;
    float avgrt = 0, avgWT = 0 , avgTat = 0 ;
    float sumWT = 0 , sumTat = 0 , sumrt = 0, cpuUtilization , Throughput;

    printf("Enter the number of Process = ");
    scanf("%d" , &n);

    struct Process p[n+1];

    for(int i = 0 ; i < n ; i++)
    {
        p[i].pid = i;
        printf("Enter the Arrival time, burst time and priority of Process = P%d", p[i].pid);
        scanf("%d%d%d", &p[i].at , &p[i].bt , &p[i].priority);
        p[i].st = -1;
        p[i].remt = p[i].bt;
    }
    // sorting the processes according to their arrival time
    qsort((void*)p , n , sizeof(struct Process) , compare);
    p[n].priority = MAX;
    for(int time = 0 ; remain != n ; time++)
    {
        minp = n;
        // in this loop we finding the min priority process avaliable in queue
        for(int i = 0 ; i < n ; i++)
        {
            if(p[i].at <= time && p[i].priority < p[minp].priority && p[i].remt > 0)
            {
                minp = i;
            }
        }

       if(p[minp].st == -1){
            p[minp].st = time;
            p[minp].rt = p[minp].st-p[minp].at;
            sumrt += p[minp].rt;
        }
            
        // reduce the remaining time by 1
        p[minp].remt--;

        if(p[minp].remt == 0)
        {
            remain++;
            p[minp].ct = time+1;
            p[minp].tat = p[minp].ct - p[minp].at;
            sumTat +=p[minp].tat;
            p[minp].wt = p[minp].tat - p[minp].bt;
            sumWT += p[minp].wt;
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
}    
