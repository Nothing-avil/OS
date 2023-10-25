#include <stdio.h>
#include <math.h>
#include<stdlib.h>

struct process {
    int pid,st,ct,at,rt,wt,tat,bt;
};
int compare(const void*p1,const void*p2){
    int a = ((struct process*)p1)->at;
    int b = ((struct process*)p2)->at;
    
    return a-b;
}
int main() {
    int n;
    printf("Entet no of processes ");
    scanf("%d",&n);

    struct process p[n];
    for(int i =0 ;i< n;i++){
        p[i].pid=i;
         printf("Enter the at and bt of p[%d]",i);
         scanf("%d%d",&p[i].at,&p[i].bt);  
    }
    qsort((void*)p,n,sizeof(struct process),compare);
    
    p[0].st=p[0].at;
    p[0].ct = p[0].st+p[0].bt;
    p[0].rt= p[0].st-p[0].at;
    p[0].tat=p[0].ct-p[0].at;
    p[0].wt=p[0].tat-p[0].bt;
    
    float swt=p[0].wt,srt=p[0].rt,stat=p[0].tat,sbt = p[0].bt;
    
    for(int i = 1;i<n;i++){
        if(p[i-1].ct>=p[i].at)
            p[i].st=p[i-1].ct;
        else
            p[i].st=p[i].at;
            
        p[i].ct=p[i].st+p[i].bt;
        p[i].rt=p[i].st-p[i].at;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        
        swt+=p[i].wt;
        srt+=p[i].rt;
        stat+=p[i].tat;
        sbt+=p[i].bt;
    }
    
    float max =0;
    for(int i=0;i<n;i++){
        if(p[i].ct>max)
        max= p[i].ct;
    }
    
    printf("Process\tat\tbt\tst\tct\trt\ttat\twt\n");
    for(int i = 0 ;i <n;i++)
        printf("\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].st,p[i].ct,p[i].rt,p[i].tat,p[i].wt);
        
    printf("Avg rt = %f\nAvg tat = %f\nAvg wt = %f\n",srt/n,stat/n,swt/n);
    printf("CPU Util= %.2f%",sbt/max*100);
    printf("ThroughPut= %f",n/max);
    return 0;
}
