#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct Process{
    int pid,at,bt,ct,tat,wt,rt,st;
    int remt;
};
int findmax(int a, int b)
{
    return a>b?a:b;
}
int compare(const void *p1 , const void *p2){
    int a = ((struct Process *) p1)->at;
    int b = ((struct Process *) p2)->at;
    if(a < b) return -1;
    else return 1;
}
int main(){
    // Input Section 
    int n, tq;
    float avgrt = 0, avgWT = 0 , avgTat = 0, sumWT = 0 , sumTat = 0 , sumrt = 0;
    int curr_time = 0 , executed = 0, queue[100] , front = -1 , rear = -1;

    bool vis[100];
    // visited array ko false initialize kar do pura 
    memset(vis , false , 100*sizeof(bool));
    printf("Enter the number of Process - ");
    scanf("%d" , &n);
    struct Process p[n+1];

    for(int i = 0 ; i < n ; i++)
    {
        p[i].pid = i;
        printf("Enter the Arrival Time and Burst Time for Process = %d - " , p[i].pid);
        scanf("%d%d" , &p[i].at , &p[i].bt); 
        p[i].remt = p[i].bt;     
    }

    printf("Enter the value of time Quanta = ");
    scanf("%d" , &tq);
    // sorting the processes according to their arrival time
    qsort((void*)p , n , sizeof(struct Process) , compare);

    // start processing in the queue
    front = rear = 0;
    queue[rear] = 0;
    vis[0] = true;
    while(executed != n)
    {
        int idx = queue[front];
        front++; 
        // Is the process comming for first time
        if(p[idx].remt == p[idx].bt){
            p[idx].st = findmax(curr_time , p[idx].at);
            curr_time = p[idx].st;
        }
        // This means the process will run for specified Time quanta
        if(p[idx].remt - tq > 0)
        {
            p[idx].remt -= tq;
            curr_time +=tq;
        }
        // Else, if the remaning time or process is <= time quanta. This means the process will complete its execution
        else{
            curr_time += p[idx].remt;
            p[idx].remt = 0;
            executed++;

            p[idx].ct = curr_time;
            p[idx].rt = p[idx].st - p[idx].at;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt =  p[idx].tat - p[idx].bt;

            sumrt += p[idx].rt;
            sumTat += p[idx].tat;
            sumWT += p[idx].wt;
        }

        // Put all the process in the queue which are arrived till now and not yet executed(visited = false)
        for(int i = 1 ;  i < n ; i++)
        {
            if(p[i].remt > 0 && p[i].at <= curr_time && vis[i] == false){
                queue[++rear] = i;
                vis[i] = true;
            }
        }
        // The process that is currently executing, if it is not completed, put it in the queue
        // (matlab ki vo process Tq time ke liye chal gayi hia par abhi bhi uska time baccha hai to use queue me dal do)
        if(p[idx].remt > 0)
            queue[++rear] = idx;

      //if queue is empty, just add one process from list, whose remaining burst time > 0
      // man lo koi process bhut der me arrive karta hia,or us time tak sari process(already present in queue)
      // execute ho jati hia to queue khali ho jayega. to fir hum use late aane wali process ko queue me dal denge
        if(front > rear){
            for(int i = 1 ; i < n ; i++){
                if(p[i].remt > 0){
                    queue[rear++] = i;
                    vis[i] = true;
                    break;
                }
            }
        }    
    }
    avgWT = sumWT/n;
    avgTat = sumTat/n;
    avgrt = sumrt/n;
    printf("process\t\tat\tbt\tst\tct\trt\ttat\twt\n"); 
    for(int i = 0 ; i < n ; i++){
        printf("%d\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid , p[i].at , p[i].bt , p[i].st , p[i].ct , p[i].rt , p[i].tat , p[i].wt);
    }
    printf("Average Response Time =  %0.2f\n Average TurnAround Time = %0.2f\n  Average Waiting Time = %0.2f\n" , avgrt , avgTat , avgWT);
    return 0;
}
