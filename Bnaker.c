#include <stdio.h>

struct process{
    int A,B,C;
};

int main()
{
    int n ,A,B,C ;
    printf("Enter no of process");
    scanf("%d",&n);
    
   struct process all[n];
   struct process max[n];
   struct process need[n];
   
   int isexecute[n];
   for(int i= 0;i<n;i++) isexecute[i]=0;
   
   int ans[n];
   
   for(int i =0 ;i< n;i++){
       printf("Enter required and allocated resources of p %d : " ,i);
       scanf("%d%d%d", &max[i].A,&max[i].B,&max[i].C);
        scanf("%d%d%d", &all[i].A,&all[i].B,&all[i].C);
        
        need[i].A = max[i].A - all[i].A;
        need[i].B = max[i].B - all[i].B;
        need[i].C = max[i].C - all[i].C;
   }
   
   printf("Enter available resources : ");
   scanf("%d%d%d", &A,&B,&C);
   
   int idx =0;
   for(int i =0 ;i<n;i++){
       for(int j=0;j<n;j++){
           if(isexecute[j]==0){
               if(need[j].A<=A && need[j].B<=B && need[j].C<=C){
                   A+= all[j].A;
                   B+= all[j].B;
                   C+= all[j].C;
                   
                   ans[idx] = j;
                   idx++;
                   isexecute[j] = 1;
                   break;
               }
           }
       }
   }
   
   for(int i = 0 ; i < n ; i++)
    {
        if(isexecute[i] == 0)
        {
            printf("No Safe Sequence is Possible");
            return 0;
        }
    }
      for(int i = 0 ; i < n ; i++)
    {
        printf("%d\t%d\t%d\t\n", need[i].A, need[i].B, need[i].C);
    }
     printf("The Safe Sequence is - ");
    for(int i = 0 ; i < n-1 ; i++)
    {
        printf("P %d -> ", ans[i]);
    }
    printf("P %d", ans[n-1]);
    return 0;
}
