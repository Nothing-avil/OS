#include<stdio.h>
#include<stdlib.h>
# define MAX 9999

struct Process{
    int pid,at,bt,ct, tat,wt,rt,st;
    int remt; // remaining time of particular process
};

int compare(const void *p1 , const void *p2){
    int a = ((struct Process *) p1)->at;
    int b = ((struct Process *) p2)->at;
    if(a < b) return -1;
    else return 1;
}

int main(){
    int n  , remain = 0; // store of remaining process
    int mn; // track the min val
    float avgrt = 0, avgWT = 0 , avgTat = 0 ;
    float sumWT = 0 , sumTat = 0 , sumrt = 0;
    printf("Enter the number of Process - ");
    scanf("%d" , &n);
    struct Process p[n+1];
    for(int i = 0 ; i < n ; i++){
        p[i].pid = i;
        printf("Enter the Arrival Time and Burst Time for Process = %d - " , p[i].pid);
        scanf("%d%d" , &p[i].at , &p[i].bt);
        p[i].st = -1;
        p[i].remt = p[i].bt;        
    }
    // sorting the processes according to their arrival time
    qsort((void*)p , n , sizeof(struct Process) , compare);
    p[n].remt = MAX;
    for(int time = 0 ; remain != n ; time++){
        mn = n;
        // in this loop we are finding the min of all avaliable process in the queue
        for(int i = 0 ; i < n ; i++){
            if(p[i].at <= time && p[i].remt < p[mn].remt && p[i].remt > 0){
                mn = i;
            }
        }

        if(p[mn].st == -1){
            p[mn].st = time;
            p[mn].rt = p[mn].st-p[mn].at;
            sumrt += p[mn].rt;
        }   
        // reduce the remaining time by 1
        p[mn].remt--;
        if(p[mn].remt == 0){
            remain++;
            p[mn].ct = time+1;
            p[mn].tat = p[mn].ct - p[mn].at;
            sumTat +=p[mn].tat;
            p[mn].wt = p[mn].tat - p[mn].bt;
            sumWT += p[mn].wt;
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
